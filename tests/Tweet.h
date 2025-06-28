#pragma once

#include "reflect.h"

#include <ctime>

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
    std::time_t timestamp;
    int likes;
    std::vector<Tweet> replies;
};
