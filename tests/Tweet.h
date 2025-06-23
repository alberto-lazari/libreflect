#pragma once

#include "reflect.h"

#include <ctime>

struct Tweet
{
    REFLECT_STRUCT(Tweet, text, author, timestamp, likes, replies);

    std::string text;
    std::string author;
    std::time_t timestamp;
    int likes;
    std::vector<Tweet> replies;
};

template <>
reflect::TypeDescriptor* reflect::getPrimitiveDescriptor<std::vector<Tweet>>()
{
    static TypeDescriptor_StdVector<Tweet> typeDescriptor("Tweet");
    return &typeDescriptor;
}
