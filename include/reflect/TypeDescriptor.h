#pragma once

#include <string>
#include <string_view>

namespace reflect
{

struct TypeDescriptor
{
    std::string name;
    size_t size;

    TypeDescriptor(std::string_view name, size_t size);
    virtual ~TypeDescriptor() = default;

    virtual std::string_view getFullName() const { return name; }
    virtual std::string dump(const void* obj, int indentLevel = 0) const;
    virtual std::string toString(const void* obj, int indentLevel = 0) const = 0;

protected:
    static std::string indent(int level) { return std::string(level * indentSpaces, ' '); }

private:
    static constexpr int indentSpaces = 4;
};

template <typename T>
TypeDescriptor* getPrimitiveDescriptor();

} // namespace reflect
