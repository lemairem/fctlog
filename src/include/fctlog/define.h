// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc
#pragma once

#define FCTLOG_STR(s) #s
#define FCTLOG_CLASS_NAME(name) FCTLOG_STR(name)
#define FCTLOG_PARENT_CLASS_NAME FCTLOG_CLASS_NAME(FCTLOG_PARENT_CLASS)

#define FCTLOG_METHOD0(result, name)                                           \
  result name() override {                                                     \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(); };                  \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct())>(fctName.str(), fct)();      \
  }

#define FCTLOG_METHOD1(result, name, arguments, arg1)                          \
  result name arguments override {                                             \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1); };              \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1)>(            \
        fctName.str(), fct, arg1)();                                           \
  }

#define FCTLOG_METHOD2(result, name, arguments, arg1, arg2)                    \
  result name arguments override {                                             \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2); };        \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2)>(fctName.str(), fct, arg1,    \
                                                  arg2)();                     \
  }

#define FCTLOG_METHOD3(result, name, arguments, arg1, arg2, arg3)              \
  result name arguments override {                                             \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2, arg3); };  \
    std::stringstream fctName;                                                 \
    fctName << FCTLOG_PARENT_CLASS_NAME << "::" << __func__;                   \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2), decltype(arg3)>(             \
        fctName.str(), fct, arg1, arg2, arg3)();                               \
  }

#define FCTLOG_METHOD4(result, name, arguments, arg1, arg2, arg3, arg4)        \
  result name arguments override {                                             \
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

#define FCTLOG_METHOD5(result, name, arguments, arg1, arg2, arg3, arg4, arg5)  \
  result name arguments override {                                             \
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

#define FCTLOG_METHOD6(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6)                                                   \
  result name arguments override {                                             \
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

#define FCTLOG_METHOD7(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6, arg7)                                             \
  result name arguments override {                                             \
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

#define FCTLOG_METHOD8(result, name, arguments, arg1, arg2, arg3, arg4, arg5,  \
                       arg6, arg7, arg8)                                       \
  result name arguments override {                                             \
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
