#pragma once

#include <concepts>

namespace reflect
{

struct TypeDescriptor;
template <typename T> TypeDescriptor* getPrimitiveDescriptor();


template <typename T>
struct AliasTag
{
    using type = void;
};

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
    static TypeDescriptor* get()
    {
        if constexpr (!std::is_void_v<typename AliasTag<T>::type>)
            return getPrimitiveDescriptor<typename AliasTag<T>::type>();
        else
            return getPrimitiveDescriptor<T>();
    }
};

} // namespace reflect
