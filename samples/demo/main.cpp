// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
// for cout
#include <iostream>
// for stringstream
#include <sstream>
#include <stdexcept>

#ifdef FCTLOG_ENABLE
#include "fctlog/outputter.h"
#endif

int main() {
  using namespace fctlog;
  std::ostringstream myLogging;
#ifdef FCTLOG_ENABLE
  Outputter::set(myLogging);
#endif

  try {
    Demo ref;
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
