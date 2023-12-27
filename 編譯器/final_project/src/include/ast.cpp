#include "ast.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

#ifdef _DEBUG_
const bool is_debug = true;
#else
const bool is_debug = false;
#endif

ASTNode::ASTNode(NodeType type, void* data) : type(type), data(data), parent(nullptr) {}

ASTNode::ASTNode(NodeType type) : ASTNode(type, nullptr) {}

void ASTNode::append(ASTNode* node) {
    node->parent = this;
    this->children.push_back(node);
}

void ASTNode::append(int index, ASTNode* node) {
    node->parent = this;
    this->children.insert(this->children.begin(), node);
}

ASTNode* ASTNode::find(std::string str) {
    if (this->vars[str] != nullptr) return this->vars[str];
    if (this->parent == nullptr) return ast::global[str];
    return this->parent->find(str);
}

ASTNode* ASTNode::traverse() {
    ASTNode* result = nullptr;

    if (is_debug) std::cout << this->to_string() << "\n";

    if (this->type == NodeType::DEFINE) {
        auto vars = (this->parent == nullptr) ? &ast::global : &this->parent->vars;
        (*vars)[*(std::string*)this->data] = this->children.front();

    } else if (this->type == NodeType::OPERATOR) {
        const auto opr = *(char*)this->data;
        const auto param_count = this->children.size();
        auto param_check = [&](int target) {
            if (param_count != target)
                throw std::runtime_error("Operation argument error.");
        };

        // 三元運算子
        if (opr == '?') {
            if (param_count < 3)
                throw std::runtime_error("Operation argument error.");
            auto first = this->children[0]->traverse();
            param_check(3);
            first->check(NodeType::BOOL_VAL);
            if (*(bool*)first->data)
                return this->children[1]->traverse();
            else return this->children[2]->traverse();
        }

        // 單元運算子
        if (param_count < 1)
            throw std::runtime_error("Operation argument error.");
        auto first = this->children[0]->traverse();

        if (opr == '!') {
            param_check(1);
            first->check(NodeType::BOOL_VAL);
            result = new ASTNode(
                NodeType::BOOL_VAL, new bool(!*(bool*)first->data));
            return result;

        } else if (opr == 'b') {
            param_check(1);
            first->check(NodeType::BOOL_VAL);
            std::cout << (*(bool*)first->data ? "#t" : "#f") << "\n";
            return nullptr;

        } else if (opr == 'n') {
            param_check(1);
            first->check(NodeType::NUMBER_VAL);
            std::cout << *(int*)first->data << "\n";
            return nullptr;
        }

        // 二元運算子
        if (param_count < 2)
            throw std::runtime_error("Operation argument error.");
        auto second = this->children[1]->traverse();

        if (opr == '-') {
            param_check(2);
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(
                NodeType::NUMBER_VAL,
                new int(*(int*)first->data - *(int*)second->data));
            return result;

        } else if (opr == '/') {
            param_check(2);
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(
                NodeType::NUMBER_VAL,
                new int(*(int*)first->data / *(int*)second->data));
            return result;

        } else if (opr == '%') {
            param_check(2);
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(
                NodeType::NUMBER_VAL,
                new int(*(int*)first->data % *(int*)second->data));
            return result;

        } else if (opr == '>') {
            param_check(2);
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(NodeType::BOOL_VAL,
                                 new bool(*(int*)first->data > *(int*)second->data));
            return result;

        } else if (opr == '<') {
            param_check(2);
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(NodeType::BOOL_VAL,
                                 new bool(*(int*)first->data < *(int*)second->data));
            return result;
        }

        // 多元運算子
        if (opr == '+') {
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(NodeType::NUMBER_VAL,
                                 new int(*(int*)first->data + *(int*)second->data));
            for (int i = 2; i < param_count; i++) {
                auto node = this->children[i]->traverse();
                node->check(NodeType::NUMBER_VAL);
                *(int*)result->data += *(int*)node->data;
            }
            return result;

        } else if (opr == '*') {
            first->check(NodeType::NUMBER_VAL);
            second->check(NodeType::NUMBER_VAL);
            result = new ASTNode(NodeType::NUMBER_VAL,
                                 new int(*(int*)first->data * *(int*)second->data));
            for (int i = 2; i < param_count; i++) {
                auto node = this->children[i]->traverse();
                node->check(NodeType::NUMBER_VAL);
                *(int*)result->data *= *(int*)node->data;
            }
            return result;

        } else if (opr == '&') {
            first->check(NodeType::BOOL_VAL);
            second->check(NodeType::BOOL_VAL);
            result = new ASTNode(NodeType::BOOL_VAL,
                                 new bool(*(bool*)first->data && *(bool*)second->data));
            for (int i = 2; i < param_count; i++) {
                auto node = this->children[i]->traverse();
                node->check(NodeType::BOOL_VAL);
                *(bool*)result->data &= *(bool*)node->data;
            }
            return result;

        } else if (opr == '|') {
            first->check(NodeType::BOOL_VAL);
            second->check(NodeType::BOOL_VAL);
            result = new ASTNode(NodeType::BOOL_VAL,
                                 new bool(*(bool*)first->data || *(bool*)second->data));
            for (int i = 2; i < param_count; i++) {
                auto node = this->children[i]->traverse();
                node->check(NodeType::BOOL_VAL);
                *(bool*)result->data |= *(bool*)node->data;
            }
            return result;

        } else if (opr == '=') {
            if (first->type != second->type)
                throw std::runtime_error("Operand type error.");
            result = new ASTNode(NodeType::BOOL_VAL,
                                 new bool(*(int*)first->data == *(int*)second->data));
            auto last = second;
            for (int i = 2; i < param_count; i++) {
                auto current = this->children[i]->traverse();
                if (last->type != current->type)
                    throw std::runtime_error("Operand type error.");
                *(bool*)result->data = *(int*)last->data == *(int*)current->data;
                last = current;
            }
            return result;
        }
    } else if (this->type == NodeType::VARIABLE) {
        return this->find(*(std::string*)this->data)->traverse();

    } else if (this->type == NodeType::FUNCTION) {
        return this;

    } else if (this->type == NodeType::BOOL_VAL) {
        return new ASTNode(this->type, new bool(*(bool*)this->data));

    } else if (this->type == NodeType::NUMBER_VAL) {
        return new ASTNode(this->type, new int(*(int*)this->data));

    } else if (this->type == NodeType::CALL) {
        auto func = ((ASTNode*)this->data)->traverse();
        auto params = *(std::vector<ASTNode*>*)func->data;
        auto args = this->children;

        if (params.size() != args.size())
            throw std::runtime_error("Function argument error.");
        for (int i = 0; i < params.size(); i++) {
            auto def = new ASTNode(NodeType::DEFINE, params[i]->data);
            def->parent = this;
            def->append(args[i]->traverse());
            def->traverse();
        }

        for (int i = 0; i < func->children.size() - 1; i++) {
            if (func->children[i]->type != NodeType::DEFINE)
                throw std::runtime_error("Function expression error.");
            auto def = new ASTNode(NodeType::DEFINE, func->children[i]->data);
            def->parent = this;
            def->traverse();
        }
        
        auto original_parent = func->children.back()->parent;
        func->children.back()->parent = this;
        auto result = func->children.back()->traverse();
        func->children.back()->parent = original_parent;
        return result;
    }

    return nullptr;
}

std::string ASTNode::to_string() {
    std::stringstream ss;
    ss << this->parent << " "
       << this << " ";

    switch (this->type) {
        case NodeType::DEFINE:
            ss << "DEFINE "
               << *(std::string*)this->data;
            break;
        case NodeType::OPERATOR:
            ss << "OPERATOR "
               << *(char*)this->data;
            break;
        case NodeType::VARIABLE:
            ss << "VARIABLE "
               << *(std::string*)this->data;
            break;
        case NodeType::FUNCTION:
            ss << "FUNCTION ";
            for (auto node : *(std::vector<ASTNode*>*)this->data)
                ss << *(std::string*)node->data << " ";
            break;
        case NodeType::BOOL_VAL:
            ss << "BOOL_VAL "
               << *(bool*)this->data;
            break;
        case NodeType::NUMBER_VAL:
            ss << "NUMBER_VAL "
               << *(int*)this->data;
            break;
        case NodeType::CALL:
            ss << "CALL "
               << this->data;
            break;
    }

    return ss.str();
}

void ASTNode::check(NodeType type) {
    if (this->type != type)
        throw std::runtime_error("Operand type error.");
}

namespace ast {
std::unordered_map<std::string, ASTNode*> global;
}  // namespace ast
