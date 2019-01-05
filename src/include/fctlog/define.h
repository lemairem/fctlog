// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc
#pragma once

#define FCTLOG_STR(s) #s
#define FCTLOG_CLASS_NAME(name) FCTLOG_STR(name)
#define FCTLOG_PARENT_CLASS_NAME FCTLOG_CLASS_NAME(FCTLOG_PARENT_CLASS)

#define FCTLOG_METHOD0_INTERNAL(result, name, constant)                        \
  result name() constant override {                                            \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(); };                  \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct())>(fctName.str(), fct)();      \
  }

#define FCTLOG_METHOD1_INTERNAL(result, name, constant, arguments, arg1)       \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1); };              \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1)>(            \
        fctName.str(), fct, arg1)();                                           \
  }

#define FCTLOG_METHOD2_INTERNAL(result, name, constant, arguments, arg1, arg2) \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2); };        \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2)>(fctName.str(), fct, arg1,    \
                                                  arg2)();                     \
  }

#define FCTLOG_METHOD3_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3)                                          \
  result name arguments constant override {                                    \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3); };  \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3)>(             \
        fctName.str(), fct, arg1, arg2, arg3)();                               \
  }

#define FCTLOG_METHOD4_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4)                                    \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4);                \
    };                                                                         \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3),              \
                                  decltype(arg4)>(fctName, fct, arg1, arg2,    \
                                                  arg3, arg4)();               \
  }

#define FCTLOG_METHOD5_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5)                              \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5);          \
    };                                                                         \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3),              \
                                  decltype(arg4), decltype(arg5)>(             \
        fctName, fct, arg1, arg2, arg3, arg4, arg5)();                         \
  }

#define FCTLOG_METHOD6_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6)                        \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6);    \
    };                                                                         \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6)>(                       \
        fctName, fct, arg1, arg2, arg3, arg4, arg5, arg6)();                   \
  }

#define FCTLOG_METHOD7_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6, arg7)                  \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6,     \
                                       arg7);                                  \
    };                                                                         \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6), decltype(arg7)>(       \
        fctName, fct, arg1, arg2, arg3, arg4, arg5, arg6, arg7)();             \
  }

#define FCTLOG_METHOD8_INTERNAL(result, name, constant, arguments, arg1, arg2, \
                                arg3, arg4, arg5, arg6, arg7, arg8)            \
  result name arguments constant override {                                    \
    auto fct = [&]() {                                                         \
      return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3, arg4, arg5, arg6,     \
                                       arg7, arg8);                            \
    };                                                                         \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<                                             \
        decltype(fct()), decltype(arg1), decltype(arg2), decltype(arg3),       \
        decltype(arg4), decltype(arg5), decltype(arg6), decltype(arg7),        \
        decltype(arg8)>(fctName, fct, arg1, arg2, arg3, arg4, arg5, arg6,      \
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
