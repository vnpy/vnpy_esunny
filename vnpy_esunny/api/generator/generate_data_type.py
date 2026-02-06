""""""
import importlib


class DataTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str, name: str) -> None:
        """Constructor"""
        self.filename: str = filename
        self.prefix: str = prefix
        self.name: str = name
        self.typedefs: dict[str, str] = {}

    def load_constant(self) -> None:
        """"""
        # module_names = ["tap_td_commen_typedef", "tap_md_commen_typedef"]
        module_names = ["esunny_commen_typedef"]
        for module_name in module_names:
            module = importlib.import_module(module_name)

            for name in dir(module):
                if "__" not in name:
                    self.typedefs[name] = getattr(module, name)

    def run(self) -> None:
        """主函数"""
        self.f_cpp = open(self.filename)
        if self.name == "td":
            self.f_define = open(f"{self.prefix}_{self.name}_data_constant.py", "w")
        self.f_typedef = open(f"{self.prefix}_{self.name}_data_typedef.py", "w")
        self.f_struct = open(f"{self.prefix}_{self.name}_data_struct.py", "w")

        self.load_constant()

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        if self.name == "td":
            self.f_define.close()
        self.f_typedef.close()
        self.f_struct.close()

        print(f"{self.name}_DataType生成完毕")

    def process_line(self, line: str) -> None:
        """处理每行"""
        line = line.replace("\n", "")
        line = line.replace(";", "")

        # MD
        if self.name == "md":
            if line.startswith("typedef"):
                self.process_typedef_md(line)
            elif "struct" in line:
                self.process_declare(line)
            elif "{" in line:
                self.process_start(line)
            elif "}" in line and "@" not in line:
                self.process_end(line)
            elif "///<" in line:
                self.process_member(line)
        # TD：TapTradeAPIDataType.h 里的 typedef 在此解析，供 struct 成员查类型
        elif self.name == "td":
            if line.strip().startswith("typedef "):
                self.process_typedef_td(line)
            elif line.strip().startswith("const"):
                self.process_const(line)
            elif "struct" in line:
                self.process_declare(line)
            elif line.startswith("{"):
                self.process_start(line)
            elif line.startswith("}") or line.startswith("\t}"):
                self.process_end(line)
            elif "///<" in line:
                self.process_member(line)
            elif not line.strip().startswith("typedef") and "#" not in line and "!" not in line and "=" not in line and "*" not in line and "(" not in line and "namespace" not in line and "TapTradeAPI" not in line and len(line) != 0:
                self.process_special(line)

    def process_special(self, line: str) -> None:
        sector = line.split("///<")[0].split("//")[0]
        words = sector.split()
        if len(words) < 2:
            return
        type_ = words[0].strip()
        name = words[1].strip()
        if "[" in name:
            name = name.split("[")[0]
        if not name:
            return
        py_type = self.typedefs.get(type_, "dict")

        new_line = f"    \"{name}\": \"{py_type}\",\n"
        self.f_struct.write(new_line)

    def process_declare(self, line: str) -> None:
        """处理声明（struct 与名之间可能为 tab）"""
        words = line.split()
        if len(words) < 2:
            return
        name = words[-1]
        end = "{"

        new_line = f"{name} = {end}\n"
        self.f_struct.write(new_line)

    def process_start(self, line: str) -> None:
        """处理开始"""
        pass

    def process_end(self, line: str) -> None:
        """处理结束"""
        new_line = "}\n\n"
        self.f_struct.write(new_line)

    def process_member(self, line: str) -> None:
        # 格式: (空白)(TYPE)(空白)(NAME);(可选 ///< 注释)。去掉注释后按空白切分，首 token=类型，末 token 去分号=成员名。
        sector = line.split("///<")[0].strip()
        words = sector.split()
        if len(words) < 2:
            return
        type_ = words[0]
        name = words[-1].rstrip(";")
        if "[" in name:
            name = name.split("[")[0]
        if not name:
            return
        py_type = self.typedefs.get(type_, "dict")
        # 嵌套 struct 保留类型名，供 generate_api_functions 展开为子 dict
        if py_type == "dict":
            py_type = type_
        new_line = f"    \"{name}\": \"{py_type}\",\n"
        self.f_struct.write(new_line)

    def process_typedef_md(self, line: str) -> None:
        """处理类型定义"""
        words = line.split(" ")[-1].split("\t")
        words = [word for word in words if word != ""]

        name = words[-1]
        py_type = self.typedefs[words[0]]
        new_line = f"{name} = \"{py_type}\"\n"

        self.f_typedef.write(new_line)
        self.typedefs[name] = py_type

        if py_type == "dict":
            short2full = f"{name} = {words[-2]}\n"
            self.f_struct.write(short2full)

    def process_typedef_td(self, line: str) -> None:
        """TD 头文件里的 typedef BaseType NewType，写入 data_typedef 并更新 typedefs"""
        words = line.split()
        if len(words) < 3:
            return
        base_type = words[1]
        new_type = words[-1]
        py_type = self.typedefs.get(base_type, "dict")
        self.f_typedef.write(f"{new_type} = \"{py_type}\"\n")
        self.typedefs[new_type] = py_type

    def process_const(self, line: str) -> None:
        sectors = line.split("=")
        value = sectors[1].replace("\'", "\"").strip()

        words = sectors[0].split()
        name = words[-1].strip()

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)


if __name__ == "__main__":
    md_generator = DataTypeGenerator("../include/esunny/TapQuoteAPIDataType.h", "esunny", "md")
    md_generator.run()

    td_generator = DataTypeGenerator("../include/esunny/TapTradeAPIDataType.h", "esunny", "td")
    td_generator.run()
