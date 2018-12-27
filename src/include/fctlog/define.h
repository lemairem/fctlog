// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc
#pragma once

#define FCTLOG_METHOD0(result, name)                                           \
  result name() override {                                                     \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(); };                  \
    return fctlog::FunctionLogger<decltype(fct())>(__func__, fct)();           \
  }
#define FCTLOG_METHOD1(result, name, arguments, arg1)                          \
  result name arguments override {                                             \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1); };              \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1)>(            \
        __func__, fct, arg1)();                                                \
  }
#define FCTLOG_METHOD2(result, name, arguments, arg1, arg2)                    \
  result name arguments override {                                             \
    auto fct = [&]() { return FCTLOG_PARENT_CLASS::name(arg1, arg2); };        \
    return fctlog::FunctionLogger<decltype(fct()), decltype(arg1),             \
                                  decltype(arg2)>(__func__, fct, arg1,         \
                                                  arg2)();                     \
  }
