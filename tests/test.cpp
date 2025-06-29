#include "Node.h"
#include "Tweet.h"
#include "Session.h"

#include <iostream>
#include <vector>

void NodeTests()
{
    Node date =
    {
        "Year",
        2025,
        {
            { "Month", 6, {} },
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
}

void TweetTests()
{
    Tweet myTweet =
    {
        .text = "This is a good day to write a reflection system",
        .author = "@laz",
        .timestamp = std::time(nullptr),
        .likes = 13,
        .replies =
        {
            {
                .text = "This is so inspiring, looking forward to hear updates! "
                    "I would be glad to hear which AI agents you are leveraging for this project.",
                .author = "John Dean | AI Expert @ MacroSoftware Corp.",
                .timestamp = std::time(nullptr),
                .likes = 2,
                .replies =
                {
                    {
                        .text = "This is not Linkedin John, go away",
                        .author = "@dan",
                        .timestamp = std::time(nullptr),
                        .likes = 9,
                        .replies = {},
                    },
                },
            },
            {
                .text = "Based",
                .author = "@rob",
                .timestamp = std::time(nullptr),
                .likes = 34,
                .replies = {},
            },
        },
    };

    std::cout << reflect::Type<Tweet>()->dump(&myTweet);
}

void SessionTests()
{
    Session origin { .uid = 0L, .username = "root", .loginTime = 0L };
    std::cout << reflect::Type<Session>()->dump(&origin);
}

int main()
{
    NodeTests();
    TweetTests();
    SessionTests();

    return 0;
}
