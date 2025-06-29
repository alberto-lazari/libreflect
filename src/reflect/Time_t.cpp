#include "reflect/Time_t.h"

#include <format>

namespace reflect
{

TypeDescriptor_Time_t::TypeDescriptor_Time_t()
    : TypeDescriptor("reflect::time_t", sizeof(time_t))
{
}

std::string TypeDescriptor_Time_t::toString(const void* obj, int indentLevel) const
{
    // Mark as intentionally unused
    (void)indentLevel;
    const std::time_t* ptr = &*reinterpret_cast<const time_t*>(obj);
    std::tm localTime = *std::localtime(ptr);

    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "%b %d, %Y %H:%M", &localTime);
    return std::string(buffer);
}

template <>
TypeDescriptor* getPrimitiveDescriptor<time_t>()
{
    static TypeDescriptor_Time_t typeDescriptor;
    return &typeDescriptor;
}

} // namespace reflect
