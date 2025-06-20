#include "reflect.h"

namespace reflect
{

TypeDescriptor::TypeDescriptor(std::string name, size_t size)
    : name(name)
    , size(size)
{
}

void TypeDescriptor::dump(const void* obj, int indentLevel) const
{
    std::cout << indent(indentLevel)
        << "[" << name << "] "
        << toString(obj, indentLevel)
        << std::endl;
}


TypeDescriptor_Int::TypeDescriptor_Int()
    : TypeDescriptor("int", sizeof(int))
{
}

std::string TypeDescriptor_Int::toString(const void* obj, int indentLevel) const
{
    // Mark as intentionally unused
    (void)indentLevel;
    return std::to_string(*(const int*)obj);
}

template <>
TypeDescriptor* getPrimitiveDescriptor<int>()
{
    static TypeDescriptor_Int typeDescriptor;
    return &typeDescriptor;
}


TypeDescriptor_StdString::TypeDescriptor_StdString()
    : TypeDescriptor("std::string", sizeof(std::string))
{
}

std::string TypeDescriptor_StdString::toString(const void* obj, int indentLevel) const
{
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
