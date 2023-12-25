#include "object.hpp"

Object::Object(DataType type, std::string name) : type(type), name(name) {}

Object::Object(DataType type) : Object(type, "") {}

Object::Object(std::string name) : Object(DataType::SYMBOL, name) {}

Object::Object() : Object(DataType::SYMBOL, "") {}

Number::Number(std::string name, int value)
    : Object(DataType::NUMBER, name), value(value) {}

Number::Number(int value) : Number("", value) {}

Boolean::Boolean(std::string name, bool value)
    : Object(DataType::BOOLEAN, name), value(value) {}

Boolean::Boolean(int value) : Boolean("", value) {}

Function::Function(std::string name, std::vector<std::string> params)
    : Object(DataType::FUNCTION, name),
      params(params),
      infinity_params(false) {}

Function::Function(std::string name) : Function(name, {}) {}

Function::Function() : Function("") {}

Call::Call(Function* func, std::vector<Object*> args)
    : func(func), args(args) {}
