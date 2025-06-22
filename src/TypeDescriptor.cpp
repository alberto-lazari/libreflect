#include "TypeDescriptor.h"

#include <format>

namespace reflect
{

TypeDescriptor::TypeDescriptor(std::string name, size_t size)
    : name(name)
    , size(size)
{
}

std::string TypeDescriptor::dump(const void* obj, int indentLevel) const
{
    return std::format("{}{} = {}\n", indent(indentLevel), name, toString(obj, indentLevel));
}

} // namespace reflect
