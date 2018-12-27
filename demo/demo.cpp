// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
#include <stdexcept>

namespace fctlog {

void Demo::fv() {
  // do something
}

int Demo::f0() { return 0; }

int Demo::f1(int val) { return val; }

int Demo::f2(int val, const std::string &) {
  if (val == 123) {
    throw std::runtime_error("MyException");
  }
  return val;
}

} // namespace fctlog