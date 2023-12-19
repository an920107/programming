#include "ast.hpp"

#include <functional>
#include <iostream>
#include <unordered_map>

#include "operator.hpp"

ASTNode::ASTNode(NodeType type) : type(type), parent(nullptr) {}

void ASTNode::append(ASTNode* node) {
    children.push_back(node);
    node->parent = this;
}

std::vector<ASTNode*> ASTNode::traverse() {
    std::vector<ASTNode*> result;
    std::unordered_map<ASTNode*, bool> visited;
    std::function<void(ASTNode*)> dfs = [&](ASTNode* root) {
        if (visited[root]) return;
        visited[root] = true;
        result.push_back(root);

        std::cout << root->parent << " " << root << " ";
        if (root->type == NodeType::OPERATOR)
            std::cout << ((Operator*)root)->symbol << " ";
        else {
            if (((Object*)root)->type == DataType::FUNCTION) {
                std::cout << ((Object*)root)->name << ": ";
                for (auto [name, obj] : ((Function*)root)->variables)
                    std::cout << obj->name << " ";
            } else if (((Object*)root)->type == DataType::NUMBER) {
                std::cout << ((Number*)root)->name << ": " << ((Number*)root)->value << " ";
            } else {
                std::cout << ((Number*)root)->name << " ";
            }
        }
        std::cout << "\n";

        for (auto child : root->children) dfs(child);
    };
    dfs(this);
    return result;
}
