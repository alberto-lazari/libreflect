#pragma once

#include "TypeDescriptor.h"
#include "DefaultResolverPolicy.h"

#include <ctime>

namespace reflect
{

struct time_t
{
    using underlying_type = std::time_t;

    time_t() = default;
    time_t(underlying_type v) : value(v) {}

    operator underlying_type() const { return value; }
    underlying_type* operator&() { return &value; }
    const underlying_type* operator&() const { return &value; }

private:
    underlying_type value;
};

struct TypeDescriptor_Time_t : public TypeDescriptor
{
    TypeDescriptor_Time_t();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
