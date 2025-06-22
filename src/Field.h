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

    template <typename T>
    T* get(void* obj) const
    {
        if (getType() != TypeResolver<T>::get()->getFullName()) return nullptr;
        return reinterpret_cast<T*>((char*)obj + offset);
    }

    template <typename T>
    const T* get(const void* obj) const
    {
        if (getType() != TypeResolver<T>::get()->getFullName()) return nullptr;
        return reinterpret_cast<const T*>((const char*)obj + offset);
    }
};

} // namespace reflect
