#pragma once

#include "TypeDescriptor.h"

#include <vector>

namespace reflect
{

struct Field
{
    std::string name;
    size_t offset;
    const TypeDescriptor* typeDescriptor;

    Field(std::string name, size_t offset, const TypeDescriptor* typeDescriptor);
};

struct TypeDescriptor_Struct : public TypeDescriptor
{
    std::vector<Field> fields;

    TypeDescriptor_Struct(std::string name, size_t size, std::vector<Field> fields);

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect
