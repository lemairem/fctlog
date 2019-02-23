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
    DemoLog intance;
#else
    Demo intance;
#endif
    Demo &ref = intance;
    ref.fv();
    ref.f0();
    ref.f0Const();
    ref.f1(1);
    ref.f2();
    ref.f2Const(1, 2);
    ref.f2(1, "Hello");
    std::unique_ptr<int> int_unique_ptr = std::unique_ptr<int>(new int(5));
    ref.f3(int_unique_ptr);
    ref.f2(123, "World");
    ref.f2();
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "\nmyLogSystem content: \n" << myLogging.str() << "\n";
}
