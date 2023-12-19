#ifndef _AST_HPP_
#define _AST_HPP_

#include <vector>

enum NodeType {
    OBJECT,
    OPERATOR,
};

class ASTNode {
   public:
    NodeType type;
    ASTNode* parent;
    std::vector<ASTNode*> children;

    ASTNode(NodeType type);
    void append(ASTNode* node);
    std::vector<ASTNode*> traverse();
};

#endif