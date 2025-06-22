#pragma once

#include "reflect.h"

#include <format>

struct TypeDescriptor_Node : reflect::TypeDescriptor
{
    TypeDescriptor_Node();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

struct Node
{
    std::string key;
    int value;
    std::vector<Node> children;

    static inline TypeDescriptor_Node Reflection;
};

TypeDescriptor_Node::TypeDescriptor_Node()
    : TypeDescriptor("Node", sizeof(Node))
{
}

std::string TypeDescriptor_Node::toString(const void* obj, int indentLevel) const
{
    std::string fields;
    const Node& node = *(const Node*)obj;
    fields += reflect::TypeResolver<std::string>::get()->dump(&node.key, indentLevel + 1);
    fields += reflect::TypeResolver<int>::get()->dump(&node.value, indentLevel + 1);
    fields += reflect::TypeResolver<std::vector<Node>>::get()->dump(&node.children, indentLevel + 1);

    std::string indentation = indent(indentLevel);
    return std::format("\n{}{{\n{}{}}}", indentation, fields, indentation);
}

template <>
reflect::TypeDescriptor* reflect::getPrimitiveDescriptor<std::vector<Node>>()
{
    static TypeDescriptor_StdVector<Node> typeDescriptor;
    return &typeDescriptor;
}
