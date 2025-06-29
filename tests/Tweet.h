#pragma once

#include "reflect.h"
#include "reflect/Time_t.h"

struct Tweet
{
    REFLECT(Tweet,
        FIELD(text)
        FIELD(author)
        FIELD(timestamp)
        FIELD(likes)
        FIELD(replies)
    );

    std::string text;
    std::string author;
    reflect::time_t timestamp;
    int likes;
    std::vector<Tweet> replies;
};
