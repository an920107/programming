#include <bits/stdc++.h>

#include "include/ast.hpp"
#include "include/object.hpp"
#include "include/operator.hpp"
#include "include/state.hpp"
using namespace std;

int main() {
    Function main_func;
    State scope(&main_func);
    scope.append(new Operator(DataType::NONE, "pn"));
    scope.append(new Operator(DataType::NUMBER, "-"));
    scope.append(new Operator(DataType::NUMBER, "+"));
    scope.back()->append(new Number(1));
    scope.back()->append(new Number(2));
    scope.back()->append(new Number(3));
    scope.pop_back();
    scope.append(new Operator(DataType::NUMBER, "*"));
    scope.back()->append(new Number(4));
    scope.back()->append(new Number(5));
    scope.pop_back();
    scope.pop_back();
    scope.pop_back();

    unordered_map<ASTNode*, bool> visited;
    function<Object*(ASTNode*)> dfs = [&](ASTNode* root) -> Object* {
        if (root->type == NodeType::OPERATOR) {
            auto opr = (Operator*)root;
            if (opr->symbol == "+") {
                int result = 0;
                for (auto node : opr->children) {
                    Object* obj = dfs(node);
                    if (obj->type != DataType::NUMBER)
                        throw runtime_error("Type error.");
                    result += ((Number*)obj)->value;
                }
                return new Number(result);
            } else if (opr->symbol == "-") {
                int result = 0;
                for (auto node : opr->children) {
                    Object* obj = dfs(node);
                    if (obj->type != DataType::NUMBER)
                        throw runtime_error("Type error.");
                    result -= ((Number*)obj)->value;
                }
                return new Number(result);
            } else if (opr->symbol == "*") {
                int result = 1;
                for (auto node : opr->children) {
                    Object* obj = dfs(node);
                    if (obj->type != DataType::NUMBER)
                        throw runtime_error("Type error.");
                    result *= ((Number*)obj)->value;
                }
                return new Number(result);
            } else if (opr->symbol == "pn") {
                Object* obj = dfs(opr->children.front());
                if (obj->type != DataType::NUMBER)
                    throw runtime_error("Type error.");
                cout << ((Number*)obj)->value << "\n";
                return new Object(DataType::NONE);
            }
        } else if (((Object*)root)->type == DataType::FUNCTION) {
        }
        return (Object*)root;
    };
    dfs(scope.back()->children.front());

    return 0;
}
