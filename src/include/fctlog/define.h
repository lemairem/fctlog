// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc
#pragma once

#include "fctlog/functionlogger.h"

#define FCTLOG_STR(s) #s
#define FCTLOG_CLASS_NAME(name) FCTLOG_STR((name))
#define FCTLOG_PARENT_CLASS_NAME FCTLOG_CLASS_NAME(FCTLOG_PARENT_CLASS)

#define FCTLOG_METHOD0_INTERNAL(result, name, constant)                        \
  result name() constant override {                                            \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(); };                  \
    return fctlog::FunctionLogger<decltype(fct())>(FCTLOG_PARENT_CLASS_NAME, __func__, fct)();      \
  }

#define FCTLOG_METHOD1_INTERNAL(result, name, constant, arguments, arg1)       \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1); };              \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1)>(            \
        FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1)();                                           \
  }

#define FCTLOG_METHOD2_INTERNAL(result, name, constant, arguments, arg1, arg2) \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2); };        \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2)>(FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1,    \
                                                  arg2)();                     \
  }

#define FCTLOG_METHOD3_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3)                                          \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3); };  \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3)>(             \
        FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2, arg3)();                               \
  }

#define FCTLOG_METHOD4_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4)                                    \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4);                \
    };                                                                         \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3),              \
                                  decltype(arg4)>(FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2,    \
                                                  arg3, arg4)();               \
  }

#define FCTLOG_METHOD5_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5)                              \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5);          \
    };                                                                         \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3),              \
                                  decltype(arg4), decltype(arg5)>(             \
        FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2, arg3, arg4, arg5)();                         \
  }

#define FCTLOG_METHOD6_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6)                        \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6);    \
    };                                                                         \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6)>(                       \
        FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2, arg3, arg4, arg5, arg6)();                   \
  }

#define FCTLOG_METHOD7_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6, arg7)                  \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6,     \
                                       arg7);                                  \
    };                                                                         \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6), decltype(arg7)>(       \
        FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2, arg3, arg4, arg5, arg6, arg7)();             \
  }

#define FCTLOG_METHOD8_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6, arg7, arg8)            \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6,     \
                                       arg7, arg8);                            \
    };                                                                         \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6), decltype(arg7),        \
        decltype(arg8)>(FCTLOG_PARENT_CLASS_NAME, __func__, fct, arg1, arg2, arg3, arg4, arg5, arg6,      \
                        arg7, arg8)();                                         \
  }

#define FCTLOG_METHOD0(result, name) FCTLOG_METHOD0_INTERNAL(result, name, )

#define FCTLOG_METHOD1(result, name, arguments, arg1)                          \
  FCTLOG_METHOD1_INTERNAL(result, name, , arguments, arg1)

#define FCTLOG_METHOD2(result, name, arguments, arg1, arg2)                    \
  FCTLOG_METHOD2_INTERNAL(result, name, , arguments, arg1, arg2)

#define FCTLOG_METHOD3(result, name, arguments, arg1, arg2, arg3)              \
  FCTLOG_METHOD3_INTERNAL(result, name, , arguments, arg1, arg2, arg3)

#define FCTLOG_METHOD4(result, name, arguments, arg1, arg2, arg3, arg4)        \
  FCTLOG_METHOD4_INTERNAL(result, name, , arguments, arg1, arg2, arg3, arg4)

#define FCTLOG_METHOD5(result, name, arguments, arg1, arg2, arg3, arg4, arg5)  \
  FCTLOG_METHOD5_INTERNAL(result, name, , arguments, arg1, arg2, arg3, arg4,   \
                          arg5)

#define FCTLOG_METHOD6(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6)                                                   \
  FCTLOG_METHOD6_INTERNAL(result, name, , arguments, arg1, arg2, arg3, arg4,   \
                          arg5, arg6)

#define FCTLOG_METHOD7(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6, arg7)                                             \
  FCTLOG_METHOD7_INTERNAL(result, name, , arguments, arg1, arg2, arg3, arg4,   \
                          arg5, arg6, arg7)

#define FCTLOG_METHOD8(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6, arg7, arg8)                                       \
  FCTLOG_METHOD7_INTERNAL(result, name, , arguments, arg1, arg2, arg3, arg4,   \
                          arg5, arg6, arg7, arg8)

#define FCTLOG_CONST_METHOD0(result, name)                                     \
  FCTLOG_METHOD0_INTERNAL(result, name, const)

#define FCTLOG_CONST_METHOD1(result, name, arguments, arg1)                    \
  FCTLOG_METHOD1_INTERNAL(result, name, const, arguments, arg1)

#define FCTLOG_CONST_METHOD2(result, name, arguments, arg1, arg2)              \
  FCTLOG_METHOD2_INTERNAL(result, name, const, arguments, arg1, arg2)

#define FCTLOG_CONST_METHOD3(result, name, arguments, arg1, arg2, arg3)        \
  FCTLOG_METHOD3_INTERNAL(result, name, const, arguments, arg1, arg2, arg3)

#define FCTLOG_CONST_METHOD4(result, name, arguments, arg1, arg2, arg3, arg4)  \
  FCTLOG_METHOD4_INTERNAL(result, name, const, arguments, arg1, arg2, arg3,    \
                          arg4)

#define FCTLOG_CONST_METHOD5(result, name, arguments, arg1, arg2, arg3, arg4,  \
                             arg5)                                             \
  FCTLOG_METHOD5_INTERNAL(result, name, const, arguments, arg1, arg2, arg3,    \
                          arg4, arg5)

#define FCTLOG_CONST_METHOD6(result, name, arguments, arg1, arg2, arg3, arg4,  \
                             arg5, arg6)                                       \
  FCTLOG_METHOD6_INTERNAL(result, name, const, arguments, arg1, arg2, arg3,    \
                          arg4, arg5, arg6)

#define FCTLOG_CONST_METHOD7(result, name, arguments, arg1, arg2, arg3, arg4,  \
                             arg5, arg6, arg7)                                 \
  FCTLOG_METHOD7_INTERNAL(result, name, const, arguments, arg1, arg2, arg3,    \
                          arg4, arg5, arg6, arg7)

#define FCTLOG_CONST_METHOD8(result, name, arguments, arg1, arg2, arg3, arg4,  \
                             arg5, arg6, arg7, arg8)                           \
  FCTLOG_METHOD7_INTERNAL(result, name, const, arguments, arg1, arg2, arg3,    \
                          arg4, arg5, arg6, arg7, arg8)
