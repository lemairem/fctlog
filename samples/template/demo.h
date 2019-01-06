// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <string>
#include <vector>

namespace fctlog {

template <typename T1, typename T2>
class Demo {
public:
  virtual ~Demo() = default;
  virtual void fv(const std::vector<T1> &) {}
  virtual int f1(T1 x) { return x; }
  virtual T1 f2Const(T2 x, T2 y) const { return x + y; }
};

} // namespace fctlog