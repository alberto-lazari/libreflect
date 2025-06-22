#include "Node.h"

#include <iostream>
#include <vector>

int main()
{
    Node date =
    {
        "Year",
        2025,
        std::vector<Node>
        {
            Node { "Month", 6, std::vector<Node> {} },
        },
    };

    // JSON-like dump
    std::cout << reflect::TypeResolver<Node>::get()->dump(&date);

    // Type definition reconstruction
    auto* NodeStruct = reflect::Struct<Node>();
    std::cout << "\nstruct Node\n{\n";
    for (const auto& field : NodeStruct->fields)
        std::cout << std::format("    {} {};\n", field.getType(), field.getName());
    std::cout << "};" << std::endl;

    // Field access
    std::string* key = NodeStruct
        ->getField("key")
        ->get<std::string>(&date);
    std::cout << std::format("\nNode date.key = \"{}\"\n", *key);

    // Field manipulation
    int* value = NodeStruct
        ->getField("value")
        ->get<int>(&date);
    (*value)++;
    std::cout << "\nYear incremented:\n"
        // Shorthand for TypeResolver::get()
        << reflect::Type<Node>()->dump(&date);

    return 0;
}
