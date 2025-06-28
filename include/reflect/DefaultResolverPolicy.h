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
        if constexpr (!std::is_void_v<typename AliasTag<T>::type>)
            return getPrimitiveDescriptor<typename AliasTag<T>::type>();
        else
            return getPrimitiveDescriptor<T>();
    }
};

} // namespace reflect
