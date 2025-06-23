#pragma once

#include "TypeDescriptor.h"
#include "DefaultResolverPolicy.h"

namespace reflect
{

struct StdTime_t {};

template <>
struct AliasTag<std::time_t>
{
    using type = StdTime_t;
};

struct TypeDescriptor_StdTime_t : public TypeDescriptor
{
    TypeDescriptor_StdTime_t();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
