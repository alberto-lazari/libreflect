#include "reflect/Long.h"

namespace reflect
{

TypeDescriptor_Long::TypeDescriptor_Long()
    : TypeDescriptor("long", sizeof(long))
{
}

std::string TypeDescriptor_Long::toString(const void* obj, int indentLevel) const
{
    // Mark as intentionally unused
    (void)indentLevel;
    return std::to_string(*reinterpret_cast<const long*>(obj));
}

template <>
TypeDescriptor* getPrimitiveDescriptor<long>()
{
    static TypeDescriptor_Long typeDescriptor;
    return &typeDescriptor;
}

} // namespace reflect
