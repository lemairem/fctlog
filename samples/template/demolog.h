// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include "demo.h"
#include <fctlog/functionlogger.h>

#define FCTLOG_PARENT_CLASS Demo<T1, T2>
namespace fctlog {

template <typename T1, typename T2>
class DemoLog : public Demo<T1, T2> {
  FCTLOG_METHOD1(void, fv, (const std::vector<T1> &v), v);
  FCTLOG_METHOD1(int, f1, (T1 x), x);
  FCTLOG_CONST_METHOD2(T1, f2Const, (T2 x, T2 y), x, y);
};

} // namespace fctlog
#undef FCTLOG_PARENT_CLASS
