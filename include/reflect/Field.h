#pragma once

#include "TypeDescriptor.h"
#include "TypeResolver.h"

namespace reflect
{

struct Field
{
    const char* name;
    size_t offset;
    const TypeDescriptor* typeDescriptor;

    Field(const char* name, size_t offset, const TypeDescriptor* typeDescriptor);

    const char* getName() const { return name; }
    std::string_view getType() const { return typeDescriptor->getFullName(); }


    const void* get(const void* obj) const { return reinterpret_cast<const std::byte*>(obj) + offset; }
    void* get(void* obj) const { return reinterpret_cast<std::byte*>(obj) + offset; }

    template <typename T>
    const T* get(const void* obj) const
    {
        return getType() == TypeResolver<T>::get()->getFullName()
            ? reinterpret_cast<const T*>(get(obj))
            : nullptr;
    }

    template <typename T>
    T* get(void* obj) const
    {
        return getType() == TypeResolver<T>::get()->getFullName()
            ? reinterpret_cast<T*>(get(obj))
            : nullptr;
    }
};

} // namespace reflect
