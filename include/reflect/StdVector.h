#pragma once

#include "TypeDescriptor.h"
#include "TypeResolver.h"

namespace reflect
{

template <typename T>
struct TypeDescriptor_StdVector : public TypeDescriptor
{
    TypeDescriptor_StdVector(const char* name);

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect

#include "impl/StdVector.inl"
