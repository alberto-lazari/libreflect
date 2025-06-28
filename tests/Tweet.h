#pragma once

#include "reflect.h"

#include <ctime>

struct Tweet
{
    REFLECT_STRUCT(Tweet,
        REFLECT_FIELD(text)
        REFLECT_FIELD(author)
        REFLECT_FIELD(timestamp)
        REFLECT_FIELD(likes)
        REFLECT_FIELD(replies)
    );

    std::string text;
    std::string author;
    std::time_t timestamp;
    int likes;
    std::vector<Tweet> replies;
};
