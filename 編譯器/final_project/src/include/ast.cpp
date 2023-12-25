#include "ast.hpp"

ASTNode::ASTNode(NodeType type, void* data) : type(type), data(data), parent(nullptr) {}

ASTNode::ASTNode(NodeType type) : ASTNode(type, nullptr) {}

void ASTNode::append(ASTNode* node) {
    node->parent = this;
    this->children.push_back(node);
}

ASTNode* ASTNode::traverse() {
    ASTNode* node = nullptr;
    
    return node;
}
