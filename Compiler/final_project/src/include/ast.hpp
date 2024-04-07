#ifndef _AST_HPP_
#define _AST_HPP_

#include <string>
#include <unordered_map>
#include <vector>
#include "python.hpp"

enum class NodeType {
    DEFINE,      // name: str, node
    OPERATOR,    // symbol: char, [params]
    VARIABLE,    // name: str, -
    FUNCTION,    // [params]: list, [[defines], return]
    BOOL_VAL,    // val: bool, -
    NUMBER_VAL,  // val: int, -
    CALL,        // addr, [params]
};

class ASTNode {
   public:
    NodeType type;
    ASTNode* parent;
    std::vector<ASTNode*> children;
    std::unordered_map<std::string, ASTNode*> vars;
    int indent;
    void* data;

   public:
    ASTNode(NodeType type, void* data);
    ASTNode(NodeType type);
    void append(ASTNode* node);
    void append(int index, ASTNode* node);
    std::string traverse();
    std::string to_string();
};

namespace ast {
extern std::stringstream pre_ss;
extern std::unordered_map<ASTNode*, bool> pre_vis;
}  // namespace ast

#endif