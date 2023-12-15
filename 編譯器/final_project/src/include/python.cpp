#include "python.hpp"

PyCommand::PyCommand(std::string command, int indentation)
    : command(command), indentation(indentation) {}

Python::Python() = default;

void Python::indent_inc() { current_indent++; }

void Python::indent_dec() { current_indent--; }

void Python::append(std::string) {
}

void Python::commit(std::string command) {
    cmds.emplace(command, current_indent);
}

std::string Python::exec() {
    const std::string py_filename = "script.py";
    const std::string out_filename = "output.txt";

    // write python file and execute
    std::ofstream py_file(py_filename);
    while (!cmds.empty()) {
        for (int i = 0; i < cmds.front().indentation; i++)
            py_file << " ";
        py_file << cmds.front().command << "\n";
        cmds.pop();
    }
    py_file.close();
    system(("python " + py_filename + " > " + out_filename).c_str());

    // read output file
    std::ifstream out_file(out_filename);
    std::string line, result;
    while (getline(out_file, line)) result += line + "\n";
    out_file.close();

    // remove files
    system(("rm " + py_filename + " " + out_filename).c_str());

    return result;
}
