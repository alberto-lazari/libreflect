#include "StdString.h"

namespace reflect
{

TypeDescriptor_StdString::TypeDescriptor_StdString()
    : TypeDescriptor("std::string", sizeof(std::string))
{
}

std::string TypeDescriptor_StdString::toString(const void* obj, int indentLevel) const
{
    // Mark as intentionally unused
    (void)indentLevel;
    return '"' + *(const std::string*)obj + '"';
}

template <>
TypeDescriptor* getPrimitiveDescriptor<std::string>()
{
    static TypeDescriptor_StdString typeDescriptor;
    return &typeDescriptor;
}

} //namespace reflect
