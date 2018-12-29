// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
#include "demolog.h"
#include <iostream>
#include <stdexcept>

#define FCTLOG_ENABLE
int main() {
  using namespace fctlog;
  std::ostringstream myLogSystem;
  Outputter::set(myLogSystem);
  try {
#ifdef FCTLOG_ENABLE
    DemoLog intance;
#else
    Demo intance;
#endif
    Demo &ref = intance;
    ref.fv();
    ref.f0();
    ref.f1(1);
    ref.f2();
    ref.f2(1, "Hello");
    ref.f2(123, "World");
    ref.f2();
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }
  std::cout << "myLogSystem content: " << myLogSystem.str() << "\n";
}
#undef FCTLOG_ENABLE