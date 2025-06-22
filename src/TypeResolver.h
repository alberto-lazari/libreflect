#pragma once

#include "DefaultResolverPolicy.h"

namespace reflect
{

struct TypeDescriptor;

template <typename T, typename Policy = DefaultResolverPolicy>
struct TypeResolver
{
    static TypeDescriptor* get() { return Policy::template get<T>(); }
};

} // namespace reflect
