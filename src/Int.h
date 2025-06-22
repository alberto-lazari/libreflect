#pragma once

#include "TypeDescriptor.h"

namespace reflect
{

struct TypeDescriptor_Int : public TypeDescriptor
{
    TypeDescriptor_Int();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
