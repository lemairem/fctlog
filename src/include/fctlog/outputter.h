// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <iostream>
#include <memory>

namespace fctlog {

template <typename T> class OutputterInternal {
public:
  static void set(const std::ostream &stream) {
    if (!output) {
      createOutput(stream);
    } else {
      output->rdbuf(stream.rdbuf());
    }
  }

  static std::ostream &get() {
    if (!output) {
      createOutput(std::cout);
    }
    return *output;
  }

private:
  static std::unique_ptr<std::ostream> output;
  static void createOutput(const std::ostream &stream) {
    output = std::unique_ptr<std::ostream>(new std::ostream(stream.rdbuf()));
  }
};

template <typename T>
std::unique_ptr<std::ostream> OutputterInternal<T>::output;

class Outputter : public OutputterInternal<void> {};

} // namespace fctlog
