#pragma once

#include "TypeDescriptor.h"
#include "TypeResolver.h"

#include <format>
#include <vector>

namespace reflect
{

template <typename T>
struct TypeDescriptor_StdVector : public TypeDescriptor
{
    TypeDescriptor_StdVector(std::string name);

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};


template <typename T>
TypeDescriptor_StdVector<T>::TypeDescriptor_StdVector(std::string name)
    : TypeDescriptor(
        std::format("std::vector<{}>", name),
        sizeof(std::vector<T>)
    )
{
}

template <typename T>
std::string TypeDescriptor_StdVector<T>::toString(const void* obj, int indentLevel) const
{
    std::string elements;
    const std::vector<T>& vec = *(std::vector<T>*)obj;

    if (vec.empty()) return "[]";

    for (const T& element : vec)
        elements += TypeResolver<T>::get()->dump(&element, indentLevel + 1);

    std::string indentation = indent(indentLevel);
    return std::format("\n{}[\n{}{}]", indentation, elements, indentation);
}

} // namespace reflect
