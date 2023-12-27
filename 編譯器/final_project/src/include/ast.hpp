#ifndef _AST_HPP_
#define _AST_HPP_

#include <string>
#include <unordered_map>
#include <vector>

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
    void* data;

   public:
    ASTNode(NodeType type, void* data);
    ASTNode(NodeType type);
    void append(ASTNode* node);
    void append(int index, ASTNode* node);
    ASTNode* find(std::string str);
    ASTNode* traverse();
    std::string to_string();
    void check(NodeType type);
};

namespace ast {
extern std::unordered_map<std::string, ASTNode*> global;
}  // namespace ast

#endif