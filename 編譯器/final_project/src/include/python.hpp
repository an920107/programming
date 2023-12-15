#ifndef _PYTHON_HPP_
#define _PYTHON_HPP_

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

class PyCommand {
   public:
    std::string command;
    int indentation;

    PyCommand(std::string, int);
};

class Python {
   private:
    std::queue<PyCommand> cmds;
    int current_indent = 0;

   public:
    Python();
    void indent_inc();
    void indent_dec();
    void append(std::string);
    void commit(std::string);
    std::string exec();
};

#endif