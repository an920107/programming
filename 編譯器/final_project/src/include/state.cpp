#include "state.hpp"

#include <iostream>

State::State(ASTNode* root) : std::vector<ASTNode*>(1, root) {}

ASTNode* State::append(ASTNode* node) {
    this->back()->append(node);
    this->push_back(node);
    return nullptr;
}

Function* State::find_nearest_function(ASTNode* node) {
    ASTNode* current = node;
    while (current != nullptr) {
        if (current->type == NodeType::OBJECT &&
            ((Object*)current)->type == DataType::FUNCTION) {
            return (Function*)current;
        }
        current = current->parent;
    }
    return nullptr;
}

Object* State::find(std::string name) {
    Function* current = find_nearest_function(this->back());
    while (current != nullptr) {
        auto iter = current->variables.find(name);
        if (iter != current->variables.end()) return iter->second;
        current = find_nearest_function(current->parent);
    }
    return nullptr;
}

void State::declare(Object* obj) {
    Function* func = find_nearest_function(this->back());
    if (func != nullptr) func->declare(obj);
}

void State::reset() {
    while (this->size() > 1) this->pop_back();
    this->back()->children.clear();
}
