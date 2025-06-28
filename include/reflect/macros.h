#pragma once

#define REFLECT_FIELD(name) \
    { #name, offsetof(T, name), reflect::TypeResolver<decltype(T::name)>::get() },

#define REFLECT_STRUCT(Struct, fields) \
    struct TypeDescriptor_##Struct : reflect::TypeDescriptor_Struct \
    { \
        using T = Struct; \
        TypeDescriptor_##Struct() : TypeDescriptor_Struct( \
                #Struct, sizeof(Struct), \
                std::vector<reflect::Field> { fields } \
            ) \
        { \
        } \
    }; \
    static inline TypeDescriptor_##Struct Type
