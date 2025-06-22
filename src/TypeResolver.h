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

template <typename T>
TypeDescriptor* Type() { return TypeResolver<T>::get(); }

} // namespace reflect
