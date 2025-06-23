#pragma once

#define UNROLL_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME

#define MAP_1(M, T, X1) \
    M(T, X1)
#define MAP_2(M, T, X1, X2) \
    M(T, X1) M(T, X2)
#define MAP_3(M, T, X1, X2, X3) \
    M(T, X1) M(T, X2) M(T, X3)
#define MAP_4(M, T, X1, X2, X3, X4) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4)
#define MAP_5(M, T, X1, X2, X3, X4, X5) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5)
#define MAP_6(M, T, X1, X2, X3, X4, X5, X6) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5) M(T, X6)
#define MAP_7(M, T, X1, X2, X3, X4, X5, X6, X7) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5) M(T, X6) M(T, X7)
#define MAP_8(M, T, X1, X2, X3, X4, X5, X6, X7, X8) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5) M(T, X6) M(T, X7) M(T, X8)
#define MAP_9(M, T, X1, X2, X3, X4, X5, X6, X7, X8, X9) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5) M(T, X6) M(T, X7) M(T, X8) M(T, X9)
#define MAP_10(M, T, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10) \
    M(T, X1) M(T, X2) M(T, X3) M(T, X4) M(T, X5) M(T, X6) M(T, X7) M(T, X8) M(T, X9) M(T, X10)
#define MAP(M, T, args...) \
    UNROLL_10(args, MAP_10, MAP_9, MAP_8, MAP_7, MAP_6, MAP_5, MAP_4, MAP_3, MAP_2, MAP_1)(M, T, args)

#define SELECT_1(M1, M2, T) \
    M1(T)
#define SELECT_2(M1, M2, T, X1) \
    M2(T, X1)
#define SELECT_3(M1, M2, T, X1, X2) \
    M2(T, X1, X2)
#define SELECT_4(M1, M2, T, X1, X2, X3) \
    M2(T, X1, X2, X3)
#define SELECT_5(M1, M2, T, X1, X2, X3, X4) \
    M2(T, X1, X2, X3, X4)
#define SELECT_6(M1, M2, T, X1, X2, X3, X4, X5) \
    M2(T, X1, X2, X3, X4, X5)
#define SELECT_7(M1, M2, T, X1, X2, X3, X4, X5, X6) \
    M2(T, X1, X2, X3, X4, X5, X6)
#define SELECT_8(M1, M2, T, X1, X2, X3, X4, X5, X6, X7) \
    M2(T, X1, X2, X3, X4, X5, X6, X7)
#define SELECT_9(M1, M2, T, X1, X2, X3, X4, X5, X6, X7, X8) \
    M2(T, X1, X2, X3, X4, X5, X6, X7, X8)
#define SELECT_10(M1, M2, T, X1, X2, X3, X4, X5, X6, X7, X8, X9) \
    M2(T, X1, X2, X3, X4, X5, X6, X7, X8, X9)
#define SELECT(M1, M2, args...) \
    UNROLL_10(args, SELECT_10, SELECT_9, SELECT_8, SELECT_7, SELECT_6, SELECT_5, SELECT_4, SELECT_3, SELECT_2, SELECT_1)(M1, M2, args)
