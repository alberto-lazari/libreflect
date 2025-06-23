#include "reflect/Struct.h"

#include <format>

namespace reflect
{

TypeDescriptor_Struct::TypeDescriptor_Struct(
    const char* name,
    size_t size,
    const std::vector<Field>& fields
)
    : TypeDescriptor(name, size)
    , fields(std::move(fields))
{
}

std::string TypeDescriptor_Struct::toString(const void* obj, int indentLevel) const
{
    std::string fieldIndentation = indent(indentLevel + 1);
    std::string fieldsRepr;
    for (const Field& field : fields)
        fieldsRepr += std::format(
            "{}{}: {} = {}\n",
            fieldIndentation,
            field.name,
            field.typeDescriptor->getFullName(),
            field.typeDescriptor->toString(
                reinterpret_cast<const std::byte*>(obj) + field.offset,
                indentLevel + 1
            )
        );

    std::string indentation = indent(indentLevel);
    return std::format("\n{}{{\n{}{}}}", indentation, fieldsRepr, indentation);
}

const Field* TypeDescriptor_Struct::getField(std::string_view fieldName) const
{
    for (const Field& field : fields)
        if (field.getName() == fieldName)
            return &field;

    return nullptr;
}

} // namespace reflect
