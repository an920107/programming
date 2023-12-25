#ifndef _AST_HPP_
#define _AST_HPP_

#include <vector>

class ASTNode {
   public:
    ASTNode* parent;
    std::vector<ASTNode*> children;

   public:
    ASTNode();
    void append(ASTNode* node);
};

#endif