#pragma once

#include "reflect.h"

struct Node
{
    struct TypeDescriptor_Node : reflect::TypeDescriptor_Struct
    {
        using T = Node;
        TypeDescriptor_Node()
            : TypeDescriptor_Struct(
                "Node", sizeof(Node),
                std::vector<reflect::Field>
                {
                    { "key", offsetof(T, key), reflect::TypeResolver<decltype(T::key)>::get() },
                    { "value", offsetof(T, value), reflect::TypeResolver<decltype(T::value)>::get() },
                    { "children", offsetof(T, children), reflect::TypeResolver<decltype(T::children)>::get() },
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
