#pragma once

#include <concepts>

namespace reflect
{

struct TypeDescriptor;
template <typename T> TypeDescriptor* getPrimitiveDescriptor();


template <typename T>
concept HasTypeDescriptor = requires
{
    { &T::Type } -> std::convertible_to<TypeDescriptor*>;
};

struct DefaultResolverPolicy
{
    template <HasTypeDescriptor T>
    static TypeDescriptor* get() { return &T::Type; }

    template <typename T>
    requires (!HasTypeDescriptor<T>)
    static TypeDescriptor* get()
    {
        return getPrimitiveDescriptor<T>();
    }
};

} // namespace reflect
