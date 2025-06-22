#pragma once

namespace reflect
{

struct TypeDescriptor;

template <typename T>
concept HasReflection = requires
{
    { &T::Reflection } -> std::convertible_to<TypeDescriptor*>;
};

struct DefaultResolverPolicy
{
    template <HasReflection T>
    static TypeDescriptor* get() { return &T::Reflection; }

    template <typename T>
    requires (!HasReflection<T>)
    static TypeDescriptor* get() { return getPrimitiveDescriptor<T>(); }
};

} // namespace reflect
