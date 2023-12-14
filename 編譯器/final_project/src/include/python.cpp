#include "python.hpp"

Python::Python() = default;

void Python::commit(std::string command) { cmds.push(command); }

std::string Python::exec() {
    const std::string py_filename = "script.py";
    const std::string out_filename = "output.txt";

    // write python file and execute
    std::ofstream py_file(py_filename);
    while (!cmds.empty()) {
        py_file << cmds.front() << "\n";
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