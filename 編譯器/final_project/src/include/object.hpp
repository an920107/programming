#ifndef _TYPING_HPP_
#define _TYPING_HPP_

#include <string>
#include <unordered_map>
#include <vector>

#include "ast.hpp"

enum DataType {
    NONE = 1, // void
    DYNAMIC = 2, // 未知
    FUNCTION = 4,
    NUMBER = 8,
    BOOLEAN = 16,
};

class Object : public ASTNode {
   public:
    DataType type;
    std::string name;

    Object(DataType type, std::string name);
    Object(DataType type);
    Object(std::string name);
    Object();

    static Object* from_ast_node(ASTNode* node);
};

class Function : public Object {
   public:
    std::vector<std::string> params;
    std::unordered_map<std::string, Object*> variables;

    Function();
    void declare(Object* obj);
};

class Number : public Object {
   public:
    int value;

    Number(int value);
};

class Boolean : public Object {
   public:
    bool value;

    Boolean(bool value);
};

#endif