#include "python.hpp"

#include <sstream>

Python::Python() = default;


void Python::commit(std::string command) {
    cmds.emplace(command);
}

std::string Python::exec() {
    const std::string py_filename = "script.py";
    const std::string out_filename = "output.txt";

    // write python file and execute
    std::ofstream py_file(py_filename);
    py_file << "try:\n";
    while (!cmds.empty()) {
        std::stringstream ss(cmds.front());
        std::string line;
        while (getline(ss, line))
            py_file << "\t" << line << "\n";
        cmds.pop();
    }
    py_file << "except Exception as e: print(e)\n";
    py_file.close();
    system(("python " + py_filename + " > " + out_filename).c_str());

    // read output file
    std::ifstream out_file(out_filename);
    std::string line, result;
    while (getline(out_file, line)) result += line + "\n";
    out_file.close();

    // remove files
    if (this->filename != "") {
        system("mkdir -p output_scripts");
        system(("cp " + py_filename + " output_scripts/" + this->filename + ".py").c_str());
    }
    system(("rm " + py_filename + " " + out_filename).c_str());

    return result;
}
