#ifndef _AST_HPP_
#define _AST_HPP_

#include <vector>

enum class NodeType {
    DEFINE,
    OPERATOR,
    VARIABLE,
    FUNCTION,
    BOOL_VAL,
    NUMBER_VAL,
    CALL,
};

class ASTNode {
   public:
    NodeType type;
    ASTNode* parent;
    std::vector<ASTNode*> children;
    void* data;

   public:
    ASTNode(NodeType type, void* data);
    ASTNode(NodeType type);
    void append(ASTNode* node);
    ASTNode* traverse();
};

#endif