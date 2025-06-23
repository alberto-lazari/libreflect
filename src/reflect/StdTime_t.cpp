#include "reflect/StdTime_t.h"

#include <format>

namespace reflect
{

TypeDescriptor_StdTime_t::TypeDescriptor_StdTime_t()
    : TypeDescriptor("std::time_t", sizeof(std::time_t))
{
}

std::string TypeDescriptor_StdTime_t::toString(const void* obj, int indentLevel) const
{
    // Mark as intentionally unused
    (void)indentLevel;
    const std::time_t* ptr = reinterpret_cast<const std::time_t*>(obj);
    std::tm localTime = *std::localtime(ptr);

    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "%b %d, %Y %H:%M", &localTime);
    return std::string(buffer);
}

template <>
TypeDescriptor* getPrimitiveDescriptor<StdTime_t>()
{
    static TypeDescriptor_StdTime_t typeDescriptor;
    return &typeDescriptor;
}

} // namespace reflect
