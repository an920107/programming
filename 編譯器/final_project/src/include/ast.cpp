#include "ast.hpp"

ASTNode::ASTNode() : parent(nullptr) {}

void ASTNode::append(ASTNode* node) {
    node->parent = this;
    this->children.push_back(node);
}
