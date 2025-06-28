#pragma once

#include "reflect.h"

struct Node
{
    struct TypeDescriptor_Node : reflect::TypeDescriptor_Struct
    {
        TypeDescriptor_Node()
            : TypeDescriptor_Struct(
                "Node", sizeof(Node),
                std::vector<reflect::Field>
                {
                    { "key", offsetof(Node, key), reflect::TypeResolver<decltype(Node::key)>::get() },
                    { "value", offsetof(Node, value), reflect::TypeResolver<decltype(Node::value)>::get() },
                    { "children", offsetof(Node, children), reflect::TypeResolver<decltype(Node::children)>::get() },
                }
            )
        {
        }
    };
    static inline TypeDescriptor_Node Type;

    std::string key;
    int value;
    std::vector<Node> children;
};
