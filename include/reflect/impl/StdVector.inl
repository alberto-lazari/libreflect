#pragma once

#include "reflect/StdVector.h"

#include <format>
#include <vector>

namespace reflect
{

template <typename T>
TypeDescriptor_StdVector<T>::TypeDescriptor_StdVector(const char* name)
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
    const std::vector<T>& vec = *reinterpret_cast<const std::vector<T>*>(obj);

    if (vec.empty()) return "[]";

    for (const T& element : vec)
        elements += TypeResolver<T>::get()->dump(&element, indentLevel + 1);

    std::string indentation = indent(indentLevel);
    return std::format("\n{}[\n{}{}]", indentation, elements, indentation);
}

} // namespace reflect
