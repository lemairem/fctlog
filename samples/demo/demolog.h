// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include "demo.h"
#include <fctlog/functionlogger.h>

#define FCTLOG_PARENT_CLASS Demo
namespace fctlog {

class DemoLog : public Demo {
  FCTLOG_METHOD0(void, fv);
  FCTLOG_METHOD0(int, f0);
  FCTLOG_CONST_METHOD0(int, f0Const);
  FCTLOG_METHOD1(int, f1, (int val = 0), val);
  FCTLOG_METHOD2(int, f2, (int val = 0, const std::string &str = ""), val, str);
  FCTLOG_CONST_METHOD2(int, f2Const, (int x, int y), x, y);
  FCTLOG_CONST_METHOD1(int, f3, (std::unique_ptr<int>& foo), foo);
};

} // namespace fctlog
#undef FCTLOG_PARENT_CLASS
