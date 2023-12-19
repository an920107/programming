#include "object.hpp"

#include <iostream>

#include "operator.hpp"

Object::Object(DataType type, std::string name)
    : ASTNode(NodeType::OBJECT), type(type), name(name) {}

Object::Object(DataType type) : Object(type, "") {}

Object::Object(std::string name) : Object(DataType::DYNAMIC, name) {}

Object::Object() : Object(DataType::DYNAMIC, "") {}

Object* Object::from_ast_node(ASTNode* node) {
    Object* obj = nullptr;
    switch (node->type) {
        case NodeType::OBJECT:
            obj = (Object*)node;
            break;
        case NodeType::OPERATOR:
            obj = new Function();
            obj->append(node);
            break;
    }
    return obj;
}

Function::Function() : Object(DataType::FUNCTION, "") {}

void Function::declare(Object* obj) { variables[obj->name] = obj; }

Number::Number(int value) : Object(DataType::NUMBER, ""), value(value) {}

Boolean::Boolean(bool value) : Object(DataType::BOOLEAN, ""), value(value) {}
