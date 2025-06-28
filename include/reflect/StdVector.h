#pragma once

#include "TypeDescriptor.h"
#include "TypeResolver.h"

#include <format>

namespace reflect
{

template <typename T>
struct TypeDescriptor_StdVector : public TypeDescriptor
{
    TypeDescriptor_StdVector();

    virtual std::string getFullName() const override
    {
        return std::format("std::vector<{}>", TypeResolver<T>::get()->getFullName());
    }
    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect

#include "impl/StdVector.inl"
