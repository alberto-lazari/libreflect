#pragma once

#include "TypeResolver.h"

namespace reflect
{

template <typename T>
TypeDescriptor* Type() { return TypeResolver<T>::get(); }


struct TypeDescriptor_Struct;

template <typename T>
concept StructType = requires
{
    { &T::Type } -> std::convertible_to<TypeDescriptor_Struct*>;
};

template <StructType T>
TypeDescriptor_Struct* Struct() { return static_cast<TypeDescriptor_Struct*>(Type<T>()); }

} // namespace reflect
