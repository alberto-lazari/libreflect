#pragma once

#include "macro-unroller.h"

#define REFLECT_STRUCT(Struct, fields...) \
    SELECT(REFLECT_STRUCT_1, REFLECT_STRUCT_2, Struct, fields)


#define REFLECT_FIELD(Type, name) \
    { #name, offsetof(Type, name), reflect::TypeResolver<decltype(Type::name)>::get() },

#define REFLECT_STRUCT_BASE(Struct, FIELDS_PASSING_METHOD) \
    struct TypeDescriptor_##Struct : reflect::TypeDescriptor_Struct \
    { \
        TypeDescriptor_##Struct() : TypeDescriptor_Struct( \
                #Struct, sizeof(Struct), \
                std::vector<reflect::Field> { FIELDS_PASSING_METHOD } \
            ) \
        { \
        } \
    }; \
    static inline TypeDescriptor_##Struct Reflection

#define REFLECT_STRUCT_1(Struct) \
    REFLECT_STRUCT_BASE(Struct, REFLECT_FIELDS(Struct))
#define REFLECT_STRUCT_2(Struct, fields...) \
    REFLECT_STRUCT_BASE(Struct, MAP(REFLECT_FIELD, Struct, fields))
