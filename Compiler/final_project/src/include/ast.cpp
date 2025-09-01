#include "ast.hpp"

#include <iostream>
#include <regex>
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

std::string ASTNode::traverse() {
    std::stringstream ss;
    std::string pre_def;

    if (is_debug) std::cout << this->to_string() << "\n";

    if (this->type == NodeType::DEFINE) {
        auto child = this->children.front();
        auto var = *(std::string*)this->data;
        std::regex re("\\-");
        var = std::regex_replace(var, re, "_");
        if (child->type == NodeType::FUNCTION) {
            child->traverse();
            pre_def = ast::pre_ss.str();
            ast::pre_ss.str("");
            ss << pre_def << var << " = f_"
               << child << "\n";
        } else {
            pre_def = ast::pre_ss.str();
            ast::pre_ss.str("");
            ss << pre_def << var << " = "
               << child->traverse() << "\n";
        }
        return ss.str();

    } else if (this->type == NodeType::OPERATOR) {
        const auto opr = *(char*)this->data;
        const auto param_count = this->children.size();
        auto param_count_check = [&](int target) {
            if (param_count != target)
                throw std::runtime_error("Operation argument error.");
        };

        // 三元運算子
        if (opr == '?') {
            param_count_check(3);
            auto first = this->children[0]->traverse();
            ss << "(" << this->children[1]->traverse()
               << " if (" << first
               << " if type(" << first << ") == bool else error_())"
               << " else " << this->children[2]->traverse()
               << ")";
            return ss.str();
        }

        // 單元運算子
        if (param_count < 1)
            throw std::runtime_error("Operation argument error.");
        auto first = this->children[0]->traverse();

        if (opr == '!') {
            param_count_check(1);
            return "(not(" + first + " if type(" + first + ") == bool else error_()))";

        } else if (opr == 'b') {
            param_count_check(1);
            pre_def = ast::pre_ss.str();
            ast::pre_ss.str("");
            return pre_def + "print('#t' if (" + first +
                   " if type(" + first + ") == bool else error_()) else '#f')\n";

        } else if (opr == 'n') {
            param_count_check(1);
            pre_def = ast::pre_ss.str();
            ast::pre_ss.str("");
            return pre_def + "print(" + first + " if type(" + first + ") == int else error_())\n";
        }

        // 二元運算子
        if (param_count < 2)
            throw std::runtime_error("Operation argument error.");
        auto second = this->children[1]->traverse();

        if (opr == '-' || opr == '/' || opr == '%' || opr == '>' || opr == '<') {
            param_count_check(2);
            std::string py_opr;
            switch (opr) {
                case '-':
                case '%':
                case '>':
                case '<':
                    py_opr = std::string(1, opr);
                    break;
                case '/':
                    py_opr = "//";
                    break;
            }
            ss << "(" << first << " " << py_opr << " " << second
               << " if type(" << first << ") == type(" << second
               << ") == int else error_())";
            return ss.str();
        }

        // 多元運算子
        if (opr == '+' || opr == '*' || opr == '&' || opr == '|' || opr == '=') {
            std::string py_opr;
            switch (opr) {
                case '+':
                case '*':
                    py_opr = std::string(1, opr);
                    break;
                case '&':
                    py_opr = "and";
                    break;
                case '|':
                    py_opr = "or";
                    break;
                case '=':
                    py_opr = "==";
                    break;
            }
            std::stringstream type_ss;
            ss << "(" << first << " " << py_opr << " " << second;
            type_ss << " if type(" << first << ") == type(" << second << ")";
            for (int i = 2; i < param_count; i++) {
                auto param = this->children[i]->traverse();
                ss << " " << py_opr << " " << param;
                type_ss << " == type(" << param << ")";
            }
            if (opr == '+' || opr == '*')
                type_ss << " == int";
            else if (opr == '&' || opr == '|')
                type_ss << " == bool";
            type_ss << " else error_())";
            ss << type_ss.str();
            return ss.str();
        }

    } else if (this->type == NodeType::VARIABLE) {
        auto var = *(std::string*)this->data;
        std::regex re("\\-");
        var = std::regex_replace(var, re, "_");
        return var;

    } else if (this->type == NodeType::FUNCTION) {
        if (ast::pre_vis[this]) return "";
        ast::pre_vis[this] = true;

        ss << "def f_" << this << "(";
        auto params = *(std::vector<ASTNode*>*)this->data;
        for (int i = 0; i < params.size(); i++) {
            if (i > 0) ss << ", ";
            ss << *(std::string*)params[i]->data;
        }
        ss << "):\n";
        for (int i = 0; i < this->children.size() - 1; i++) {
            if (this->children[i]->type != NodeType::DEFINE)
                throw std::runtime_error("Function expression error.");
            std::stringstream def_ss(((ASTNode*)this->children[i])->traverse());
            std::string def;
            while (getline(def_ss, def))
                ss << "\t" << def << "\n";
        }

        auto ret = this->children.back()->traverse();
        if (this->children.back()->type == NodeType::FUNCTION) {
            std::stringstream def_ss(ast::pre_ss.str());
            ast::pre_ss.str("");
            std::string def;
            while (getline(def_ss, def))
                ss << "\t" << def << "\n";
        }
        ss << "\treturn " << ret << "\n";
        ast::pre_ss << ss.str();
        ss.str("");

        ss << "f_" << this;
        return ss.str();

    } else if (this->type == NodeType::BOOL_VAL) {
        return *(bool*)this->data ? "True" : "False";

    } else if (this->type == NodeType::NUMBER_VAL) {
        return std::to_string(*(int*)this->data);

    } else if (this->type == NodeType::CALL) {
        auto data = (ASTNode*)this->data;
        if (data->type == NodeType::FUNCTION)
            ss << data->traverse() << "(";
        else {
            auto var = *(std::string*)(ASTNode*)data->data;
            std::regex re("\\-");
            ss << std::regex_replace(var, re, "_") << "(";
        }
        auto args = this->children;
        for (int i = 0; i < args.size(); i++) {
            if (i > 0) ss << ", ";
            ss << args[i]->traverse();
        }
        ss << ")";
        return ss.str();
    }

    return "";
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

namespace ast {
std::stringstream pre_ss;
std::unordered_map<ASTNode*, bool> pre_vis;
}  // namespace ast
