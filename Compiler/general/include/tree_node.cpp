#include "tree_node.hpp"

TreeNode::TreeNode() = default;

TreeNode::TreeNode(const Token &token, const std::string &code)
    : token(token), code(code) {}

TreeNode *TreeNode::get(LR lr) const {
    if (lr == LR::LEFT)
        return this->left;
    else
        return this->right;
}

void TreeNode::set(LR lr, TreeNode *node) {
    if (lr == LR::LEFT)
        this->left = node;
    else
        this->right = node;
}

void TreeNode::remove(LR lr) {
    if (lr == LR::LEFT)
        this->left = nullptr;
    else
        this->right = nullptr;
}
