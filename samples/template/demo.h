// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <fctlog/define.h>
#include <string>
#include <vector>

namespace demo {
namespace internal {

template <typename T1, typename T2> class Demo {
public:
  virtual ~Demo() = default;
  FCTLOG_VIRTUAL void fv(const std::vector<T1> &) {}
  FCTLOG_VIRTUAL int f1(T1 x) { return x; }
  FCTLOG_VIRTUAL T1 f2Const(T2 x, T2 y) const { return x + y; }
};

#ifdef FCTLOG_ENABLE
#define FCTLOG_PARENT_CLASS Demo<T1, T2>
template <typename T1, typename T2> class DemoLog : public Demo<T1, T2> {
public:
  FCTLOG_METHOD1(void, fv, (const std::vector<T1> &v), v);
  FCTLOG_METHOD1(int, f1, (T1 x), x);
  FCTLOG_CONST_METHOD2(T1, f2Const, (T2 x, T2 y), x, y);
};
#undef FCTLOG_PARENT_CLASS
#endif
}

#ifdef FCTLOG_ENABLE
template <typename T1, typename T2> using Demo = internal::DemoLog<T1, T2>;
#else
template <typename T1, typename T2> using Demo = internal::Demo<T1, T2>;
#endif

} // namespace demo