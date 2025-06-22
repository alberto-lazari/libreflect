#pragma once

#include "reflect.h"

#include <format>

struct TypeDescriptor_Node : reflect::TypeDescriptor_Struct
{
    TypeDescriptor_Node();
};

struct Node
{
    std::string key;
    int value;
    std::vector<Node> children;

    static inline TypeDescriptor_Node Reflection;
};

template <>
reflect::TypeDescriptor* reflect::getPrimitiveDescriptor<std::vector<Node>>()
{
    static TypeDescriptor_StdVector<Node> typeDescriptor("Node");
    return &typeDescriptor;
}

TypeDescriptor_Node::TypeDescriptor_Node()
    : TypeDescriptor_Struct(
        "Node", sizeof(Node),
        std::vector<reflect::Field>
        {
            { "key", offsetof(Node, key), reflect::TypeResolver<std::string>::get() },
            { "value", offsetof(Node, value), reflect::TypeResolver<int>::get() },
            { "children", offsetof(Node, children), reflect::TypeResolver<std::vector<Node>>::get() },
        }
    )
{
}
