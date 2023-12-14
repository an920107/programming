#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_

#include <iostream>
#include <string>

enum VarType {
    DYNAMIC,
    BOOLEAN,
    NUMBER,
    FUNCTION,
};

class Variable {
   public:
    std::string name;
    VarType type;

    Variable(std::string, VarType);
};

#endif