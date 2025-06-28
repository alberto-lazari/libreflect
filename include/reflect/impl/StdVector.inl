#pragma once

#include "reflect/StdVector.h"

#include <vector>

namespace reflect
{

template <typename T>
TypeDescriptor_StdVector<T>::TypeDescriptor_StdVector()
    : TypeDescriptor(
        "std::vector<?>",
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

// Cannot partially-specialize getPrimitiveDescriptor(), because it's a function.
// Standard C++ only allows struct/class partial template specialization.
template <typename T, typename Policy>
struct TypeResolver<std::vector<T>, Policy>
{
    static TypeDescriptor* get()
    {
        static TypeDescriptor_StdVector<T> typeDescriptor;
        return &typeDescriptor;
    }
};

} // namespace reflect
