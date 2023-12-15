#include "symbol.hpp"

Symbol::Symbol(std::string name, DataType type, std::string command)
    : name(name), type(type), command(command) {}

Symbol::Symbol(std::string name)
    : Symbol(name, DataType::DYNAMIC, name) {}


Symbol::Symbol(DataType type, std::string command)
    : Symbol("", type, command) {}

Symbol::Symbol()
    : Symbol("", DataType::DYNAMIC, "") {}
