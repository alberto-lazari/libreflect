#pragma once

#include <string>

namespace reflect
{

struct TypeDescriptor
{
    std::string name;
    size_t size;

    TypeDescriptor(std::string name, size_t size);
    virtual ~TypeDescriptor() = default;

    virtual std::string getFullName() const { return name; }
    virtual std::string dump(const void* obj, int indentLevel = 0) const;
    virtual std::string toString(const void* obj, int indentLevel = 0) const = 0;

protected:
    static std::string indent(int level) { return std::string(level * indentSpaces, ' '); }

private:
    static const int indentSpaces = 2;
};

template <typename T>
TypeDescriptor* getPrimitiveDescriptor();

} // namespace reflect
