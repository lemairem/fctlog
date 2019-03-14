// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <fctlog/define.h>
#include <memory>
#include <string>

namespace demo {
namespace internal {

class Demo {
public:
  virtual ~Demo() = default;
  virtual void fv();
  virtual int f0();
  virtual int f0Const() const;
  virtual int f1(int val = 0);
  virtual int f2(int val = 0, const std::string &str = "");
  virtual int f2Const(int x, int y) const;
  virtual int f3(std::unique_ptr<int> &foo) const;
};

#ifdef FCTLOG_ENABLE
#define FCTLOG_PARENT_CLASS Demo
class DemoLog : public Demo {
public:
  FCTLOG_METHOD0(void, fv);
  FCTLOG_METHOD0(int, f0);
  FCTLOG_CONST_METHOD0(int, f0Const);
  FCTLOG_METHOD1(int, f1, (int val = 0), val);
  FCTLOG_METHOD2(int, f2, (int val = 0, const std::string &str = ""), val, str);
  FCTLOG_CONST_METHOD2(int, f2Const, (int x, int y), x, y);
  FCTLOG_CONST_METHOD1(int, f3, (std::unique_ptr<int> & foo), foo);
};
#undef FCTLOG_PARENT_CLASS
#endif

} // namespace internal

#ifdef FCTLOG_ENABLE
using Demo = internal::DemoLog;
#else
using Demo = internal::Demo;
#endif

} // namespace demo
