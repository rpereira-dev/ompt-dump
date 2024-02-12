import sys
from pycparser import c_ast, c_generator, parse_file

CALLBACKS = []
GEN = c_generator.CGenerator()
BLACKLIST = ["ompt_callback_buffer_complete", "ompt_callback_buffer_request"]

class OmpCallback:

    def __init__(self, name, decl):
        self.name = name
        self.decl = decl

class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDecl(self, decl):
        if isinstance(decl.type, c_ast.TypeDecl):
            name = decl.type.declname
            if name.endswith("_t"):
                name = name[:-2:]
                if name.startswith("ompt_callback_"):
                    if name not in BLACKLIST:
                        CALLBACKS.append(OmpCallback(name, decl))

def export_files(dst):
    f = open("{}/callback-register.h".format(dst), "w")
    for callback in CALLBACKS:
        f.write("register_callback({});\n".format(callback.name))
    f.close()

    f = open("{}/callback-impl.h".format(dst), "w")
    for callback in CALLBACKS:
        callback.decl.type.declname = "on_{}".format(callback.name)
        f.write("\n")
        f.write("{} {{\n".format(GEN._generate_type(callback.decl)))
        f.write("    printf(\"{}\\n\");\n".format(callback.name))
        if not "void" in callback.decl.type.type.names:
            f.write("    return omp_control_tool_success;\n");
        f.write("}\n");
    f.close()

def main():
    if len(sys.argv) == 3:
        ast = parse_file(sys.argv[1], use_cpp=True, cpp_args=r'-Iutils/fake_libc_include')
        FuncDefVisitor().visit(ast)
        export_files(sys.argv[2])
    else:
        print("usage: {} [OMPT_HEADER] [EXPORT_DIR]".format(sys.argv[0]))

if __name__ == "__main__":
    main()
