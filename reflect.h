#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace reflect
{

struct TypeDescriptor
{
    std::string name;
    size_t size;

    TypeDescriptor(std::string name, size_t size);
    virtual ~TypeDescriptor() = default;

    virtual std::string getFullName() const { return name; }
    virtual void dump(const void* obj, int indentLevel = 0) const;
    virtual std::string toString(const void* obj, int indentLevel = 0) const = 0;

protected:
    static std::string indent(int level) { return std::string(level * indentSpaces, ' '); }

private:
    static const int indentSpaces = 2;
};

template <typename T> TypeDescriptor* getPrimitiveDescriptor();
template <typename T> struct TypeResolver;

 
struct TypeDescriptor_Int : public TypeDescriptor
{
    TypeDescriptor_Int();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};


struct TypeDescriptor_StdString : public TypeDescriptor
{
    TypeDescriptor_StdString();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};


template <typename T>
struct TypeDescriptor_StdVector : public TypeDescriptor
{
    TypeDescriptor_StdVector();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

template <typename T>
TypeDescriptor_StdVector<T>::TypeDescriptor_StdVector()
    : TypeDescriptor(
        std::format("std::vector<{}>", TypeResolver<T>::get()->getFullName()),
        sizeof(std::vector<T>)
    )
{
}

template <typename T>
concept Printable = requires(std::ostream& os, T a)
{
    { os << a } -> std::same_as<std::ostream&>;
};

template <typename T>
std::string TypeDescriptor_StdVector<T>::toString(const void* obj, int indentLevel) const
{
    TypeDescriptor* descriptor = TypeResolver<T>::get();

    std::string repr = "{";
    const std::vector<T>& vec = *(std::vector<T>*)obj;
    repr += vec.empty() ? ' ' : '\n';

    std::string nest = indent(indentLevel + 1);
    for (const T& element : vec)
    {
        repr += nest + "[" + descriptor->getFullName() + "] "
            + descriptor->toString(&element, indentLevel + 1)
            + '\n';
    }

    if (!vec.empty())
    {
        repr += indent(indentLevel);
    }
    return repr + "}";
}


template <typename T>
concept HasReflection = requires
{
    { &T::Reflection } -> std::convertible_to<reflect::TypeDescriptor*>;
};

struct DefaultResolver
{
    template <HasReflection T>
    static TypeDescriptor* get() { return &T::Reflection; }

    template <typename T>
    requires (!HasReflection<T>)
    static TypeDescriptor* get() { return getPrimitiveDescriptor<T>(); }
};


template <typename T>
struct TypeResolver
{
    static TypeDescriptor* get() { return DefaultResolver::get<T>(); }
};

} // namespace reflect
