#pragma once

#include "TypeDescriptor.h"

namespace reflect
{

struct TypeDescriptor_Long : public TypeDescriptor
{
    TypeDescriptor_Long();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
