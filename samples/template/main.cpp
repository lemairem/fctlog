// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
#include "demolog.h"
#include <iostream>
#include <stdexcept>

int main() {
  using namespace fctlog;
  std::ostringstream myLogging;
  Outputter::set(myLogging);

  try {
#ifdef FCTLOG_ENABLE
    DemoLog<int, float> intance;
#else
    Demo<int, float> intance;
#endif
    Demo<int, float> &ref = intance;
    ref.fv();
    ref.f1(1);
    ref.f2Const(1, 2);
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "\nmyLogSystem content: \n" << myLogging.str() << "\n";
}
