#pragma once

#include "reflect.h"

#include <ctime>

struct TypeDescriptor_Tweet : reflect::TypeDescriptor_Struct
{
    TypeDescriptor_Tweet();
};

struct Tweet
{
    std::string text;
    std::string author;
    std::time_t timestamp;
    int likes;
    std::vector<Tweet> replies;

    static inline TypeDescriptor_Tweet Reflection;
};

template <>
reflect::TypeDescriptor* reflect::getPrimitiveDescriptor<std::vector<Tweet>>()
{
    static TypeDescriptor_StdVector<Tweet> typeDescriptor("Tweet");
    return &typeDescriptor;
}

TypeDescriptor_Tweet::TypeDescriptor_Tweet()
    : TypeDescriptor_Struct(
        "Tweet", sizeof(Tweet),
        std::vector<reflect::Field>
        {
            { "text", offsetof(Tweet, text), reflect::TypeResolver<decltype(Tweet::text)>::get() },
            { "author", offsetof(Tweet, author), reflect::TypeResolver<decltype(Tweet::author)>::get() },
            { "timestamp", offsetof(Tweet, timestamp), reflect::TypeResolver<decltype(Tweet::timestamp)>::get() },
            { "likes", offsetof(Tweet, likes), reflect::TypeResolver<decltype(Tweet::likes)>::get() },
            { "replies", offsetof(Tweet, replies), reflect::TypeResolver<decltype(Tweet::replies)>::get() },
        }
    )
{
}
