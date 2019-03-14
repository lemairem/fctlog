// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
#include <fctlog/outputter.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

int main() {
  using namespace demo;
  std::ostringstream myLogging;
  fctlog::Outputter::set(myLogging);

  try {
    fctlog::OstreamContainer::maxElement = 5;
    Demo<int, float> ref;
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    ref.fv(v);
    ref.f1(1);
    ref.f2Const(1, 2);
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }

  std::cout << "\nmyLogSystem content: \n" << myLogging.str() << "\n";
}
