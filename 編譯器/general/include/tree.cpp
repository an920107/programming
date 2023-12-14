#include "tree.hpp"

#include <map>
#include <stack>

Tree::Tree() = default;

std::vector<const TreeNode> Tree::dfs() const {
    std::vector<const TreeNode> result;
    std::stack<const TreeNode*> dfs_stack;
    std::map<const TreeNode*, bool> visited;

    dfs_stack.push(&this->root);
    visited[&this->root] = true;
    while (!dfs_stack.empty()) {
        auto current = dfs_stack.top();
        dfs_stack.pop();
        result.push_back(*current);

        auto left = current->get(TreeNode::LEFT);
        if (left != nullptr && !visited[left]) {
            visited[left] = true;
            dfs_stack.push(left);
        }

        auto right = current->get(TreeNode::RIGHT);
        if (right != nullptr && !visited[right]) {
            visited[right] = true;
            dfs_stack.push(right);
        }
    }
    return result;
}
