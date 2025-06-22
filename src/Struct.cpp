#include "Struct.h"

#include <format>

namespace reflect
{

Field::Field(std::string name, size_t offset, const TypeDescriptor* typeDescriptor)
    : name(name)
    , offset(offset)
    , typeDescriptor(typeDescriptor)
{
}


TypeDescriptor_Struct::TypeDescriptor_Struct(
    std::string name,
    size_t size,
    std::vector<Field> fields
)
    : TypeDescriptor(name, size)
    , fields(fields)
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
            field.typeDescriptor->toString((char*)obj + field.offset, indentLevel + 1)
        );

    std::string indentation = indent(indentLevel);
    return std::format("\n{}{{\n{}{}}}", indentation, fieldsRepr, indentation);
}

} // namespace reflect
