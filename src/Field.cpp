#include "Field.h"

namespace reflect
{

Field::Field(const char* name, size_t offset, const TypeDescriptor* typeDescriptor)
    : name(name)
    , offset(offset)
    , typeDescriptor(typeDescriptor)
{
}

} // namespace reflect
