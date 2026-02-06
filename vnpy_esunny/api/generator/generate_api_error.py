""""""


class ErrorTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str, name: str) -> None:
        """Constructor"""
        self.filename: str = filename
        self.prefix: str = prefix
        self.name: str = name

    def run(self) -> None:
        """主函数"""
        self.f_cpp = open(self.filename)
        self.f_define = open(f"{self.prefix}_error_constant.py", "w")

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        self.f_define.close()

        print("ErrorType生成完毕")

    def process_line(self, line: str) -> None:
        """处理每行"""
        line = line.replace("\n", "")
        line = line.replace(";", "")
        if line.startswith("const int"):
            self.process_int(line)

    def process_int(self, line: str) -> None:
        """处理类型定义"""
        sectors = line.split("=")
        value = sectors[1].strip()

        words = sectors[0].split(" ")
        words = [word for word in words if word != ""]
        name = words[-1].strip()
        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)


if __name__ == "__main__":
    error_generator = ErrorTypeGenerator("../include/esunny/TapAPIError.h", "esunny", "")
    error_generator.run()
