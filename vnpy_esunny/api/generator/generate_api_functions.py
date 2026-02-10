""""""
import importlib
from typing import TextIO


class ApiGenerator:
    """API生成器"""""

    def __init__(self, filename: str, prefix: str, name: str, class_name: str):
        """Constructor"""
        self.filename = filename
        self.prefix = prefix
        self.name = name
        self.class_name = class_name

        self.callbacks: dict[str, dict] = {}
        self.functions: dict[str, dict] = {}
        self.lines: dict[str, str] = {}

        self.structs: dict[str, dict] = {}
        self.typedefs: dict[str, str] = {}
        self.load_constant()
        self.load_struct()

    def load_constant(self) -> None:
        """"""
        if self.name == "md":
            module_names = ["esunny_commen_typedef", "esunny_md_data_typedef"]
#            module_names = ["tap_md_commen_typedef", "tap_md_data_typedef"]
        elif self.name == "td":
            module_names = ["esunny_commen_typedef", "esunny_td_data_typedef"]
#            module_names = ["tap_td_commen_typedef", "tap_td_data_typedef"]

        for module_name in module_names:
            module = importlib.import_module(module_name)

            for name in dir(module):
                if "__" not in name:
                    self.typedefs[name] = getattr(module, name)

    def load_struct(self) -> None:
        """加载Struct"""
        module_names = ["esunny_md_data_struct", "esunny_commen_struct", "esunny_td_data_struct"]
        # module_names = ["tap_md_data_struct", "tap_md_commen_struct", "tap_td_data_struct", "tap_td_commen_struct"]

        for module_name in module_names:
            module = importlib.import_module(module_name)

            for name in dir(module):
                if "__" not in name:
                    self.structs[name] = getattr(module, name)

    def run(self) -> None:
        """运行生成"""
        self.f_cpp = open(self.filename)

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        # print("self.callbacks=",self.callbacks,"\n\n")
        # print("self.functions=", self.functions,"\n\n")
        # print("self.lines=", self.lines,"\n\n")

        # print("self.structs=", self.structs,"\n\n")
        # print("self.typedefs=", self.typedefs,"\n\n")

        self.generate_header_define()
        self.generate_header_process()
        self.generate_header_on()
        self.generate_header_function()

        self.generate_source_task()
        self.generate_source_switch()
        self.generate_source_process()
        self.generate_source_function()
        self.generate_source_on()
        self.generate_source_module()

        print(f"{self.name}_API生成成功")

    def process_line(self, line: str) -> None:
        """处理每行"""
        line = line.replace(";", "")
        line = line.replace("\n", "")
        line = line.replace("\t", "")
        line = line.replace("{}", "")

        if self.name == "md":
            if "virtual void TAP_CDECL On" in line:
                self.process_callback(line)
            elif "virtual TAPIINT32 ES_CDECL Qry" in line:
                self.process_function(line)
            elif "virtual TAPIINT32 TAP_CDECL Qry" in line:
                self.process_function(line)
        elif self.name == "td":
            if "virtual void TAP_CDECL On" in line or "virtual void ES_CDECL On" in line:
                self.process_callback(line)
            elif "virtual TAPIINT32 ES_CDECL Qry" in line:
                self.process_function(line)
            elif "virtual TAPIINT32 TAP_CDECL Qry" in line:
                self.process_function(line)

    def process_callback(self, line: str) -> None:
        """处理回调函数"""
        name = line[line.index("On"):line.index("(")]
        line = line.replace("        ", "")
        new_line = self.standard_format(line)
        self.lines[name] = new_line

        d = self.generate_arg_dict(line)
        self.callbacks[name] = d

    def standard_format(self, line: str) -> str:
        """"""
        line = line.split("=")[0]
        if self.name == "md":
            line = line.replace("virtual void TAP_CDECL", "virtual void")
        elif self.name == "td":
            line = line.replace("virtual void TAP_CDECL", "virtual void")
            line = line.replace("virtual void ES_CDECL", "virtual void")
        header = line.split("(")[0]

        args_str = line[line.index("(") + 1:line.index(")")]
        if not args_str:
            f_content = ""
        else:
            args = args_str.split(",")
            content = ""
            simple_types = ("int", "unsigned int", "char", "string", "unsigned short")
            for arg in args:
                words = [w for w in arg.split(" ") if w]
                if len(words) > 2:
                    tap_type = words[-2].replace("*", "")
                    if tap_type == "" and len(words) >= 3:
                        tap_type = words[-3]
                    name = words[-1].replace("*", "").strip()
                    if "::" in tap_type:
                        tap_type = tap_type.split("::")[1]

                    cpp_type = self.typedefs.get(tap_type, "dict")
                    if cpp_type == "dict":
                        cpp_type = tap_type
                    out_type = tap_type if tap_type.startswith("TAPISTR_") else cpp_type

                    is_const = "const" in arg
                    is_pointer = "*" in arg
                    if cpp_type not in simple_types and is_pointer:
                        if is_const:
                            item = f"const {out_type} *{name}, "
                        else:
                            item = f"{out_type} *{name}, "
                    elif is_const:
                        item = f"const {out_type} {name}, "
                    else:
                        item = f"{out_type} {name}, "
                    content = content + item
                elif len(words) == 2:
                    tap_type = words[0].replace("*", "")
                    name = words[1].replace("*", "").strip()

                    if "::" in tap_type:
                        tap_type = tap_type.split("::")[1]
                    cpp_type = self.typedefs.get(tap_type, tap_type)
                    if cpp_type == "dict":
                        cpp_type = tap_type
                    out_type = tap_type if tap_type.startswith("TAPISTR_") else cpp_type

                    is_const = "const" in arg
                    is_pointer = "*" in arg
                    if cpp_type not in simple_types and is_pointer:
                        if is_const:
                            item = f"const {out_type} *{name}, "
                        else:
                            item = f"{out_type} *{name}, "
                    elif is_const:
                        item = f"const {out_type} {name}, "
                    else:
                        item = f"{out_type} {name}, "
                    content = content + item
            f_content = content[:-2]

        new_line = f"{header}({f_content})"
        return new_line

    def process_function(self, line: str) -> None:
        """处理主动函数"""
        name = line[line.index("Qry"):line.index("(")]

        d = self.generate_arg_dict(line)
        self.functions[name] = d

    def _task_field_for_unsigned_int(self, param_name: str) -> str:
        """unsigned int 参数名映射到 Task 字段名。sessionID -> task_id，errorCode -> task_error。"""
        if param_name == "errorCode":
            return "task_error"
        return "task_id"

    def _get_pointer_members(self, struct_type: str) -> list[tuple[str, str]]:
        """返回需要深拷贝的指针成员列表 [(字段名, 指向类型)]，仅当指向类型在 self.structs 中时。"""
        result: list[tuple[str, str]] = []
        for field_name, field_type in self.structs.get(struct_type, {}).items():
            if not field_name:
                continue
            if not field_type.endswith("*"):
                continue
            pointee_type = field_type[:-1].strip()
            if pointee_type in self.structs:
                result.append((field_name, pointee_type))
        return result

    def generate_arg_dict(self, line: str) -> dict:
        """生成参数字典"""
        args_str = line[line.index("(") + 1:line.index(")")]
        if not args_str:
            return {}
        args = args_str.split(",")

        d = {}
        for arg in args:
            words = arg.split(" ")
            words = [word for word in words if word]
            if len(words) < 2:
                continue
            name = words[-1].replace("*", "")
            type_word = words[-2].replace("*", "")
            if type_word == "" and len(words) >= 3:
                tap_type = words[-3]
            else:
                tap_type = type_word
            if "::" in tap_type:
                tap_type = tap_type.split("::")[1]

            cpp_type = self.typedefs.get(tap_type, tap_type)
            if cpp_type == "dict":
                cpp_type = tap_type
            d[name] = cpp_type
        return d

    def generate_header_define(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_header_define.h"
        with open(filename, "w") as f:
            for n, name in enumerate(self.callbacks.keys()):
                line = f"#define {name.upper()} {n}\n"
                f.write(line)

    def generate_header_process(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_header_process.h"
        with open(filename, "w") as f:
            for name in self.callbacks.keys():
                name = name.replace("On", "process")
                line = f"void {name}(Task *task);\n\n"
                f.write(line)

    def generate_header_on(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_header_on.h"
        with open(filename, "w") as f:
            for function_name, d in self.callbacks.items():
                function_name = function_name.replace("On", "on")

                args_list = []
                for name, type_ in d.items():
                    if type_ == "unsigned int":
                        args_list.append(f"unsigned int {name}")
                    elif type_ == "int":
                        if name == "errorCode":
                            args_list.append("int error")
                        elif name == "reasonCode":
                            args_list.append("int reason")
                        else:
                            args_list.append(f"int {name}")
                    elif type_ == "char":
                        args_list.append("char last")
                    elif type_ == "string":
                        args_list.append(f"string {name}")
                    else:
                        args_list.append("const dict &data")

                args_str = ", ".join(args_list)
                line = f"virtual void {function_name}({args_str}) {{}};\n\n"

                f.write(line)

    def generate_header_function(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_header_function.h"
        with open(filename, "w") as f:
            for function_name, d in self.functions.items():
                function_name = function_name.replace("Qry", "qry")

                args_list = []
                for name, type_ in d.items():
                    if type_ == "unsigned int":
                        args_list.append(f"int {name}")
                    else:
                        args_list.append("const dict &req")

                args_str = ", ".join(args_list)
                line = f"int {function_name}({args_str});\n\n"
                f.write(line)

    def generate_source_task(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_task.cpp"
        with open(filename, "w") as f:
            for name, d in self.callbacks.items():
                line = self.lines[name]

                f.write(line.replace("virtual void ",
                                     f"void {self.class_name}::") + "\n")
                f.write("{\n")
                f.write("\tTask task = Task();\n")
                f.write(f"\ttask.task_name = {name.upper()};\n")

                for field, type_ in d.items():
                    if type_ == "unsigned int":
                        task_field = self._task_field_for_unsigned_int(field)
                        f.write(f"\ttask.{task_field} = {field};\n")
                    elif type_ == "int":
                        f.write(f"\ttask.task_int = {field};\n")
                    elif type_ == "char":
                        f.write(f"\ttask.task_last = {field};\n")
                    elif type_ == "string":
                        f.write(f"\ttask.task_string = {field};\n")
                    else:
                        f.write(f"\tif ({field})\n")
                        f.write("\t{\n")
                        f.write(f"\t\t{type_} *task_data = new {type_}();\n")
                        f.write(f"\t\t*task_data = *{field};\n")
                        for ptr_field, pointee_type in self._get_pointer_members(type_):
                            f.write(f"\t\tif ({field}->{ptr_field})\n")
                            f.write("\t\t{\n")
                            f.write(f"\t\t\ttask_data->{ptr_field} = new {pointee_type}();\n")
                            f.write(f"\t\t\t*task_data->{ptr_field} = *{field}->{ptr_field};\n")
                            f.write("\t\t}\n")
                        f.write("\t\ttask.task_data = task_data;\n")
                        f.write("\t}\n")

                f.write("\tthis->task_queue.push(task);\n")
                f.write("};\n\n")

    def _flatten_key_suffix(
        self, struct_field: str, first_nested: bool
    ) -> str:
        """同名加 suffix：第一个嵌套无后缀；后续仅当成员名有尾数字时用该数字做后缀，无尾数字不加。"""
        if first_nested:
            return ""
        tail_digits = ""
        i = len(struct_field) - 1
        while i >= 0 and struct_field[i].isdigit():
            tail_digits = struct_field[i] + tail_digits
            i -= 1
        if tail_digits:
            return tail_digits
        return ""

    def _write_nested_struct(
        self,
        f: TextIO,
        struct_field: str,
        struct_type: str,
        member_prefix: str,
        parent_var: str = "data",
        flatten: bool = True,
        key_suffix: str = "",
        use_arrow: bool = False,
    ) -> None:
        """展开嵌套 struct。flatten=True 时仅用 suffix 区分同名；use_arrow=True 时用 -> 访问首层（指针）。"""
        sep = "->" if use_arrow else "."
        if flatten:
            for nf, nt in self.structs.get(struct_type, {}).items():
                if not nf:
                    continue
                if nt in self.structs:
                    sub_suffix = "_" + nf
                    self._write_nested_struct(
                        f,
                        nf,
                        nt,
                        f"{member_prefix}{sep}{nf}",
                        parent_var=parent_var,
                        flatten=True,
                        key_suffix=sub_suffix,
                        use_arrow=False,
                    )
                    continue
                key = nf + key_suffix
                access = f"{member_prefix}{sep}{nf}"
                if nt == "string":
                    f.write(
                        f"\t\t{parent_var}[\"{key}\"] = toUtf({access});\n"
                    )
                else:
                    f.write(
                        f"\t\t{parent_var}[\"{key}\"] = {access};\n"
                    )
            return
        f.write(f"\t\tdict {struct_field};\n")
        for nf, nt in self.structs.get(struct_type, {}).items():
            if not nf:
                continue
            if nt in self.structs:
                self._write_nested_struct(
                    f, nf, nt, f"{member_prefix}.{nf}", parent_var=struct_field
                )
                continue
            if nt == "string":
                f.write(
                    f"\t\t{struct_field}[\"{nf}\"] = toUtf({member_prefix}.{nf});\n"
                )
            else:
                f.write(f"\t\t{struct_field}[\"{nf}\"] = {member_prefix}.{nf};\n")
        f.write(f"\t\t{parent_var}[\"{struct_field}\"] = {struct_field};\n")

    def generate_source_switch(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_switch.cpp"
        with open(filename, "w") as f:
            for name in self.callbacks.keys():
                process_name = name.replace("On", "process")
                f.write(f"case {name.upper()}:\n")
                f.write("{\n")
                f.write(f"\tthis->{process_name}(&task);\n")
                f.write("\tbreak;\n")
                f.write("}\n\n")

    def generate_source_process(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_process.cpp"
        with open(filename, "w") as f:
            for name, d in self.callbacks.items():
                process_name = name.replace("On", "process")
                on_name = name.replace("On", "on")

                f.write(
                    f"void {self.class_name}::{process_name}(Task *task)\n")
                f.write("{\n")
                if len(d.keys()) == 0:
                    f.write(f"\tthis->{on_name}();\n")
                    f.write("};\n\n")
                else:
                    f.write("\tgil_scoped_acquire acquire;\n")
                    args = []
                    for field, type_ in d.items():
                        if type_ == "unsigned int":
                            task_field = self._task_field_for_unsigned_int(field)
                            args.append(f"task->{task_field}")
                        elif type_ == "int":
                            args.append("task->task_int")
                        elif type_ == "string":
                            args.append("task->task_string")
                        elif type_ == "char":
                            args.append("task->task_last")
                        else:
                            args.append("data")
                            f.write("\tdict data;\n")
                            f.write("\tif (task->task_data)\n")
                            f.write("\t{\n")
                            f.write(
                                f"\t\t{type_} *task_data = ({type_}*)task->task_data;\n")

                            struct_fields = self.structs.get(type_, {})
                            first_nested = True
                            for struct_field, struct_type in struct_fields.items():
                                if not struct_field:
                                    continue
                                if type_ == "TapAPIBillQryRsp" and struct_field == "BillText":
                                    f.write(
                                        "\t\tdata[\"BillText\"] = toUtf(std::string(task_data->BillText, task_data->BillLen));\n"
                                    )
                                    continue
                                base_type = struct_type[:-1] if struct_type.endswith("*") else struct_type
                                if base_type in self.structs:
                                    sk = self._flatten_key_suffix(
                                        struct_field, first_nested
                                    )
                                    self._write_nested_struct(
                                        f,
                                        struct_field,
                                        base_type,
                                        f"task_data->{struct_field}",
                                        parent_var="data",
                                        flatten=True,
                                        key_suffix=sk,
                                        use_arrow=struct_type.endswith("*"),
                                    )
                                    first_nested = False
                                    continue
                                if struct_type == "string":
                                    f.write(
                                        f"\t\tdata[\"{struct_field}\"] = toUtf(task_data->{struct_field});\n")
                                else:
                                    f.write(
                                        f"\t\tdata[\"{struct_field}\"] = task_data->{struct_field};\n")

                            for ptr_field, _ in self._get_pointer_members(type_):
                                f.write(
                                    f"\t\tif (task_data->{ptr_field}) delete task_data->{ptr_field};\n"
                                )
                            f.write("\t\tdelete task_data;\n")
                            f.write("\t}\n")

                    args_str = ", ".join(args)
                    f.write(f"\tthis->{on_name}({args_str});\n")
                    f.write("};\n\n")

    def _getter_name(self, struct_type: str) -> str:
        """类型名转 getXXX 中的后缀，如 'unsigned int' -> 'UnsignedInt'。"""
        return "".join(s.capitalize() for s in struct_type.split())

    def _write_req_struct_getters(
        self,
        f: TextIO,
        req_var: str,
        key_prefix: str,
        var_prefix: str,
        struct_type: str,
    ) -> None:
        """递归展开嵌套 struct，对每个叶子字段生成 getXXX。"""
        for nf, nt in self.structs.get(struct_type, {}).items():
            if not nf:
                continue
            key = f"{key_prefix}.{nf}" if key_prefix else nf
            var = f"{var_prefix}.{nf}" if var_prefix else f"myreq.{nf}"
            if nt in self.structs:
                self._write_req_struct_getters(f, req_var, key, var, nt)
            elif nt == "string":
                f.write(f'\tgetString({req_var}, "{key}", {var});\n')
            else:
                getter = self._getter_name(nt)
                f.write(f'\tget{getter}({req_var}, "{key}", &{var});\n')

    def generate_source_function(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_function.cpp"
        with open(filename, "w") as f:
            for name, d in self.functions.items():
                req_name = name.replace("Qry", "qry")
                session_param = next(
                    (k for k, t in d.items() if t == "unsigned int"), None
                )
                if session_param is None and d:
                    session_param = list(d.keys())[0]

                length = len(d.keys())
                if length == 1:
                    f.write(
                        f"int {self.class_name}::{req_name}(int {session_param})\n"
                    )
                    f.write("{\n")
                    f.write(
                        f"\tTAPIUINT32 session_id = static_cast<TAPIUINT32>({session_param});\n"
                    )
                    f.write(f"\tint i = this->api->{name}(&session_id);\n")
                    f.write("\treturn i;\n")
                    f.write("};\n\n")
                else:
                    type_ = list(d.values())[-1]
                    if not type_:
                        continue
                    struct_fields = self.structs.get(type_, {})
                    f.write(
                        f"int {self.class_name}::{req_name}(int {session_param}, const dict &req)\n"
                    )
                    f.write("{\n")
                    f.write(f"\t{type_} myreq = {type_}();\n")
                    f.write("\tmemset(&myreq, 0, sizeof(myreq));\n")

                    for struct_field, struct_type in struct_fields.items():
                        if not struct_field:
                            continue
                        if struct_type == "string":
                            f.write(
                                f'\tgetString(req, "{struct_field}", myreq.{struct_field});\n'
                            )
                        elif struct_type in self.structs:
                            self._write_req_struct_getters(
                                f,
                                "req",
                                struct_field,
                                f"myreq.{struct_field}",
                                struct_type,
                            )
                        else:
                            getter = self._getter_name(struct_type)
                            f.write(
                                f'\tget{getter}(req, "{struct_field}", &myreq.{struct_field});\n'
                            )

                    f.write(
                        f"\tTAPIUINT32 session_id = static_cast<TAPIUINT32>({session_param});\n"
                    )
                    f.write(f"\tint i = this->api->{name}(&session_id, &myreq);\n")
                    f.write("\treturn i;\n")
                    f.write("};\n\n")

    def generate_source_on(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_on.cpp"
        with open(filename, "w") as f:
            for name, d in self.callbacks.items():
                on_name = name.replace("On", "on")

                args = []
                bind_args = ["void", self.class_name, on_name]
                for field, type_ in d.items():
                    if type_ == "unsigned int":
                        args.append(f"unsigned int {field}")
                        bind_args.append(field)
                    elif type_ == "char":
                        args.append("char last")
                        bind_args.append("last")
                    elif type_ == "int":
                        if field == "errorCode":
                            args.append("int error")
                            bind_args.append("error")
                        else:
                            args.append(f"int {field}")
                            bind_args.append(f"{field}")
                    elif type_ == "string":
                        args.append(f"string {field}")
                        bind_args.append(f"{field}")
                    else:
                        args.append("const dict &data")
                        bind_args.append("data")

                args_str = ", ".join(args)
                bind_args_str = ", ".join(bind_args)

                f.write(f"void {on_name}({args_str}) override\n")
                f.write("{\n")
                f.write("\ttry\n")
                f.write("\t{\n")
                f.write(f"\t\tPYBIND11_OVERLOAD({bind_args_str});\n")
                f.write("\t}\n")
                f.write("\tcatch (const error_already_set &e)\n")
                f.write("\t{\n")
                f.write("\t\tcout << e.what() << endl;\n")
                f.write("\t}\n")
                f.write("};\n\n")

    def generate_source_module(self) -> None:
        """"""
        filename = f"{self.prefix}_{self.name}_source_module.cpp"
        with open(filename, "w") as f:
            for name in self.functions.keys():
                name = name.replace("Qry", "qry")
                f.write(f".def(\"{name}\", &{self.class_name}::{name})\n")

            f.write("\n")

            for name in self.callbacks.keys():
                name = name.replace("On", "on")
                f.write(f".def(\"{name}\", &{self.class_name}::{name})\n")

            f.write(";\n")


if __name__ == "__main__":
    md_generator = ApiGenerator("../include/esunny/TapQuoteAPI.h", "esunny", "md", "MdApi")
    md_generator.run()

    td_generator = ApiGenerator("../include/esunny/TapTradeAPI.h", "esunny", "td", "TdApi")
    td_generator.run()
