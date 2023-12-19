#include "execute.hpp"

#include <functional>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

Object* execute(State& scope) {
    if (scope.back()->children.empty()) return new Object();

    std::unordered_map<ASTNode*, bool> visited;
    std::function<Object*(ASTNode*)> dfs = [&](ASTNode* root) -> Object* {
        visited[root] = true;
        if (root->type == NodeType::OPERATOR) {
            auto opr = (Operator*)root;
            auto get_operands_with_type =
                [&](DataType type) -> std::vector<Object*> {
                std::vector<Object*> operands;
                for (auto node : opr->children) {
                    if (visited[node]) continue;
                    Object* obj = dfs(node);
                    if (type & obj->type == 0)
                        throw std::runtime_error("Type error.");
                    operands.push_back(obj);
                }
                return operands;
            };

            if (opr->symbol == "+") {
                int result = 0;
                for (auto obj : get_operands_with_type(DataType::NUMBER))
                    result += ((Number*)obj)->value;
                return new Number(result);
            } else if (opr->symbol == "-") {
                auto operands = get_operands_with_type(DataType::NUMBER);
                return new Number(((Number*)operands[0])->value -
                                  ((Number*)operands[1])->value);
            } else if (opr->symbol == "*") {
                int result = 1;
                for (auto obj : get_operands_with_type(DataType::NUMBER))
                    result *= ((Number*)obj)->value;
                return new Number(result);
            } else if (opr->symbol == "/") {
                auto operands = get_operands_with_type(DataType::NUMBER);
                return new Number(((Number*)operands[0])->value /
                                  ((Number*)operands[1])->value);
            } else if (opr->symbol == "%") {
                auto operands = get_operands_with_type(DataType::NUMBER);
                return new Number(((Number*)operands[0])->value %
                                  ((Number*)operands[1])->value);
            } else if (opr->symbol == ">") {
                auto operands = get_operands_with_type(DataType::NUMBER);
                return new Boolean(((Number*)operands[0])->value >
                                   ((Number*)operands[1])->value);
            } else if (opr->symbol == "<") {
                auto operands = get_operands_with_type(DataType::NUMBER);
                return new Boolean(((Number*)operands[0])->value <
                                   ((Number*)operands[1])->value);
            } else if (opr->symbol == "==") {
                auto operands = get_operands_with_type(
                    (DataType)(DataType::NUMBER | DataType::BOOLEAN));
                for (int i = 1; i < operands.size(); i++) {
                    if (operands[i - 1]->type != operands[i]->type)
                        throw std::runtime_error("Type error.");
                    if (operands[i - 1]->type == DataType::NUMBER) {
                        if (((Number*)operands[i - 1])->value !=
                            ((Number*)operands[i])->value)
                            return new Boolean(false);
                    } else if (((Boolean*)operands[i - 1])->value !=
                               ((Boolean*)operands[i])->value) {
                        return new Boolean(false);
                    }
                }
                return new Boolean(true);
            } else if (opr->symbol == "&&") {
                bool result = true;
                for (auto obj : get_operands_with_type(DataType::BOOLEAN))
                    result &= ((Boolean*)obj)->value;
                return new Boolean(result);
            } else if (opr->symbol == "||") {
                bool result = false;
                for (auto obj : get_operands_with_type(DataType::BOOLEAN))
                    result |= ((Boolean*)obj)->value;
                return new Boolean(result);
            } else if (opr->symbol == "!") {
                auto obj = get_operands_with_type(DataType::BOOLEAN)[0];
                return new Boolean(!((Boolean*)obj)->value);
            } else if (opr->symbol == "?:") {
                auto operands = get_operands_with_type(
                    (DataType)(DataType::NUMBER | DataType::BOOLEAN));
                if (operands[0]->type != DataType::BOOLEAN)
                    throw std::runtime_error("Type error.");
                return ((Boolean*)operands[0])->value ? operands[1]
                                                      : operands[2];
            } else if (opr->symbol == "pn") {
                auto obj = get_operands_with_type(DataType::NUMBER)[0];
                std::cout << ((Number*)obj)->value << "\n";
                return new Object(DataType::NONE);
            } else if (opr->symbol == "pb") {
                Object* obj = get_operands_with_type(DataType::BOOLEAN)[0];
                std::cout << (((Boolean*)obj)->value ? "#t" : "#f") << "\n";
                return new Object(DataType::NONE);
            }
        } else if (((Object*)root)->type == DataType::FUNCTION) {
            auto func = (Function*)root;
            scope.append(func);
            Object* result = execute(scope);
            scope.pop_back();
            return result;
        }

        auto var_name = ((Object*)root)->name;
        if (var_name != "") {
            auto var_val = scope.find(var_name);
            if (var_val == nullptr)
                throw std::runtime_error("'" + var_name +
                                         "' has not been defined.");
            if (var_val->type == DataType::FUNCTION) {
                scope.append((Function*)var_val);
                auto result = execute(scope);
                scope.pop_back();
                return result;
            }
            return var_val;
        }
        return (Object*)root;
    };
    Object* result = dfs(scope.back()->children.front());
    return result;
}
