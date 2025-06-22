#pragma once

#include "TypeDescriptor.h"

namespace reflect
{

struct TypeDescriptor_StdString : public TypeDescriptor
{
    TypeDescriptor_StdString();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
