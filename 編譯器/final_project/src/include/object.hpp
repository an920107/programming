#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <string>
#include <vector>
#include <unordered_map>
#include "ast.hpp"

enum DataType {
    SYMBOL = 1,
    NONE = 2,
    NUMBER = 4,
    BOOLEAN = 8,
    FUNCTION = 16,
};

class Object : public ASTNode {
   public:
    DataType type;
    std::string name;

   public:
    Object(DataType type, std::string name);
    Object(DataType type);
    Object(std::string name);
    Object();
};

class Number : public Object {
   public:
    int value;

   public:
    Number(std::string name, int value);
    Number(int value);
};

class Boolean : public Object {
   public:
    bool value;

   public:
    Boolean(std::string name, bool value);
    Boolean(int value);
};

class Function : public Object {
   public:
    bool infinity_params;
    std::vector<std::string> params;
    std::unordered_map<std::string, Object*> vars;

   public:
    Function(std::string name, std::vector<std::string> params);
    Function(std::string name);
    Function();
};

class Call : public Object {
   public:
    Function* func;
    std::vector<Object*> args;
   
   public:
    Call(Function* func, std::vector<Object*> args);
};

#endif