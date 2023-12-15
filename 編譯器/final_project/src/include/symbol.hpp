#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_

#include <iostream>
#include <string>

enum DataType {
    DYNAMIC,
    BOOLEAN,
    NUMBER,
    FUNCTION,
};

class Symbol {
   public:
    std::string name;
    DataType type;
    std::string command;

    Symbol(std::string, DataType, std::string);
    Symbol(std::string);
    Symbol(DataType, std::string);
    Symbol();
};

#endif