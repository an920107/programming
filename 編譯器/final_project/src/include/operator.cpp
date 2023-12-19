#include "operator.hpp"

Operator::Operator(DataType type, std::string symbol)
    : ASTNode(NodeType::OPERATOR), type(type), symbol(symbol) {}
