#include "Node.h"

#include <iostream>
#include <vector>

int main()
{
    Node node =
    {
        "Year",
        2025,
        std::vector<Node>
        {
            Node { "Month", 6, std::vector<Node> {} },
        },
    };
    std::cout << reflect::TypeResolver<Node>::get()->dump(&node);
}
