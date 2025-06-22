#pragma once

#include "TypeDescriptor.h"
#include "Field.h"
#include "TypeResolver.h"

#include <vector>
#include <string_view>

namespace reflect
{

struct TypeDescriptor_Struct : public TypeDescriptor
{
    std::vector<Field> fields;

    TypeDescriptor_Struct(const char* name, size_t size, const std::vector<Field>& fields);

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;

    const Field* getField(std::string_view fieldName) const;
};


template <typename T>
concept StructType = requires
{
    { &T::Reflection } -> std::convertible_to<TypeDescriptor_Struct*>;
};

template <StructType T>
TypeDescriptor_Struct* Struct()
{
    return static_cast<TypeDescriptor_Struct*>(TypeResolver<T>::get());
}

} // namespace reflect
