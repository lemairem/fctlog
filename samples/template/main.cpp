// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#include "demo.h"
// for cout
#include <iostream>
// for stringstream
#include <sstream>
#include <stdexcept>
#include <vector>

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
#ifdef FCTLOG_ENABLE
    OstreamContainer::maxElement = 5;
#endif
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
