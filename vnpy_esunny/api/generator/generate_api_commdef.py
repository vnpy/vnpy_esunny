""""""
import importlib


class CommenTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str, name: str) -> None:
        """Constructor"""
        self.filename: str = filename
        self.prefix: str = prefix
        self.name: str = name
        self.typedefs: dict[str, str] = {}

    def load_constant(self) -> None:
        """"""
        module_name = f"{self.prefix}_commen_typedef"
        module = importlib.import_module(module_name)

        for name in dir(module):
            if "__" not in name:
                self.typedefs[name] = getattr(module, name)

    def run(self) -> None:
        """主函数"""
        self.f_cpp = open(self.filename)
        self.f_define = open(f"{self.prefix}_commen_constant.py", "w")
        self.f_typedef = open(f"{self.prefix}_commen_typedef.py", "w")
        self.f_struct = open(f"{self.prefix}_commen_struct.py", "w")

        self.add_supplement()

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        self.f_define.close()
        self.f_typedef.close()

        self.load_constant()
        self.process_struct()

        self.f_cpp.close()
        self.f_struct.close()

        print(f"{self.name}_CommenType生成完毕")

    def process_struct(self) -> None:
        f_cpp_struct = open(self.filename)
        for line in f_cpp_struct:
            line = line.replace(";", "")
            line = line.replace("\n", "")

            if "struct" in line:
                self.process_declare(line)
            elif "{" in line:
                self.process_start(line)
            elif line.strip() == "}":
                self.process_end(line)
            elif "///<" in line:
                self.process_member(line)

        f_cpp_struct.close()

    def process_declare(self, line: str) -> None:
        """处理声明"""
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
        sector = line.split("///<")[0]
        words = sector.split("\t")
        words = [word for word in words if word != ""]

        if len(words) == 1:
            words = words[0].split(" ")
            words = [word for word in words if word != ""]

        if len(words) < 2:
            return
        type_ = words[0].strip()
        name = words[1].strip()
        if "[" in name:
            name = name.split("[")[0]
        if not name:
            return
        py_type = self.typedefs.get(type_, "dict")
        # 嵌套 struct 保留类型名，供 generate_api_functions 按字段展开
        if py_type == "dict":
            py_type = type_
        new_line = f"    \"{name}\": \"{py_type}\",\n"
        self.f_struct.write(new_line)

    def process_line(self, line: str) -> None:
        """处理每行"""
        line = line.replace("\n", "")
        line = line.replace(";", "")
        stripped = line.strip()
        if stripped.startswith("typedef char") or stripped.startswith("typedef TAPICHAR"):
            self.process_char_td(stripped)
        elif stripped.startswith("const"):
            self.process_const_td(line)

    def process_char_md(self, line: str) -> None:
        """处理类型定义"""
        if "\t\t\t\t" in line:
            name = line.split("\t\t\t\t")[1]
            new_line = f"{name} = \"char\"\n"
        else:
            name = line.split("\t")[1].split("[")[0]
            new_line = f"{name} = \"string\"\n"

        self.f_typedef.write(new_line)

    def process_char_td(self, line: str) -> None:
        words = line.split()
        if len(words) < 2:
            return
        name = words[-1]

        if "[" in name:
            name = name.split("[")[0]
            new_line = f"{name} = \"string\"\n"
            # print(new_line)
        else:
            new_line = f"{name} = \"char\"\n"

        self.f_typedef.write(new_line)

    def process_const_md(self, line: str) -> None:
        """"""
        sectors = line.split("=")
        value = sectors[1].replace("\'", "\"").strip()

        words = sectors[0].split("\t")
        words = [word for word in words if word != ""]
        name = words[1].strip()

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)

    def process_const_td(self, line: str) -> None:
        sectors = line.split("=", 1)
        if len(sectors) < 2:
            return
        value = sectors[1].replace("\'", "\"").strip()

        words = sectors[0].split()
        if not words:
            return
        name = words[-1].strip()
        if not name:
            return

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)

    def add_supplement(self) -> None:
        self.f_typedef.write("TAPIINT32 = \"int\"\n")
        self.f_typedef.write("TAPIUINT32 = \"unsigned int\"\n")
        self.f_typedef.write("TAPIINT64 = \"long long\"\n")
        self.f_typedef.write("TAPIUINT64 = \"unsigned long long\"\n")
        self.f_typedef.write("TAPIUINT16 = \"unsigned short\"\n")
        self.f_typedef.write("TAPIUINT8 = \"unsigned char\"\n")
        self.f_typedef.write("TAPIREAL64 = \"double\"\n")
        self.f_typedef.write("TAPIYNFLAG = \"char\"\n")
        self.f_typedef.write("TAPILOGLEVEL = \"char\"\n")
        self.f_typedef.write("TAPICommodityType = \"char\"\n")
        self.f_typedef.write("TAPICallOrPutFlagType = \"char\"\n")
        self.f_typedef.write("TAPIAuthTypeType = \"char\"\n")


if __name__ == "__main__":
    comm_generator = CommenTypeGenerator("../include/esunny/TapAPICommDef.h", "esunny", "comm")
    comm_generator.run()
