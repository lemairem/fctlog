// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
#include <iostream>
#include <stdexcept>

namespace fctlog {
namespace internal {

void Demo::fv() {
  // do something
}

int Demo::f0() { return 0; }

int Demo::f0Const() const { return 0; }

int Demo::f1(int val) { return val; }

int Demo::f2(int val, const std::string &) {
  if (val == 123) {
    throw std::runtime_error("MyException");
  }
  return val;
}

int Demo::f3(std::unique_ptr<int> &ptr) const {
  int retVal = *ptr;
  return retVal;
}

int Demo::f2Const(int x, int y) const { return x + y; }
}
} // namespace fctlog
