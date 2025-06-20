#include "reflect.h"

#include <string>
#include <vector>

namespace reflect
{

struct TypeDescriptor_Node : TypeDescriptor
{
    TypeDescriptor_Node();

    virtual std::string toString(const void* obj, int indentLevel = 0) const override;
};

} // namespace reflect

struct Node
{
    std::string key;
    int value;
    std::vector<Node> children;

    static inline reflect::TypeDescriptor_Node Reflection;
};

namespace reflect
{

TypeDescriptor_Node::TypeDescriptor_Node()
    : TypeDescriptor("Node", sizeof(Node))
{
}

std::string TypeDescriptor_Node::toString(const void* obj, int indentLevel) const
{
    std::string repr = "{\n";
    const Node& node = *(const Node*)obj;
    TypeDescriptor* descriptor;
    std::string nest = indent(indentLevel + 1);

    descriptor = TypeResolver<std::string>::get();
    repr += nest + "[" + descriptor->getFullName() + "] "
        + descriptor->toString(&node.key, indentLevel + 1)
        + '\n';

    descriptor = TypeResolver<int>::get();
    repr += nest + "[" + descriptor->getFullName() + "] "
        + descriptor->toString(&node.value, indentLevel + 1)
        + '\n';

    descriptor = TypeResolver<std::vector<Node>>::get();
    repr += nest + "[" + descriptor->getFullName() + "] "
        + descriptor->toString(&node.children, indentLevel + 1)
        + '\n';

    return repr + indent(indentLevel) + "}";
}

template <>
TypeDescriptor* getPrimitiveDescriptor<std::vector<Node>>()
{
    static TypeDescriptor_StdVector<Node> typeDescriptor;
    return &typeDescriptor;
}

} // namespace reflect

int main()
{
    Node node =
    {
        "Year",
        2025,
        std::vector<Node> {
            Node { "Month", 6, std::vector<Node>() },
        },
    };
    reflect::TypeResolver<Node>::get()->dump(&node);
}
