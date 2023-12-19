#ifndef _OPERATOR_HPP_
#define _OPERATOR_HPP_

#include <string>
#include <vector>
#include "object.hpp"

class Operator : public ASTNode {
   public:
    DataType type;
    std::string symbol;

    Operator(DataType type, std::string symbol);
};

#endif