#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_

#include <iostream>
#include <string>
#include <unordered_map>

enum DataType {
    DYNAMIC,
    BOOLEAN,
    NUMBER,
};

class Symbol {
   public:
    std::string name;
    DataType type;
    std::string command;

    // < 0: not function
    int func_params_count = -1;
    std::unordered_map<std::string, Symbol> symbols;

    Symbol(std::string, DataType, std::string);
    Symbol(std::string);
    Symbol(DataType, std::string);
    Symbol();
};

#endif