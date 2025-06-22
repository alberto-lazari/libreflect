#include "reflect/Int.h"

namespace reflect
{

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

} // namespace reflect
