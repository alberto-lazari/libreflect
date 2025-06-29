#pragma once

#include "reflect.h"
#include "reflect/Time_t.h"

struct Session
{
    REFLECT(Session,
        FIELD(uid)
        FIELD(username)
        FIELD(loginTime)
    );

    long uid;
    std::string username;
    reflect::time_t loginTime;
};
