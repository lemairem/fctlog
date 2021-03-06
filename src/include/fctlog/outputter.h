// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <functional>
#include <iostream>
#include <memory>

namespace fctlog {

template <typename T> class OutputterInternal {
public:
  static void set(const std::ostream &stream) {
    output->rdbuf(stream.rdbuf());
    fctOutput = []() { return output; };
  }

  static void
  set(const std::function<std::shared_ptr<std::ostream>()> &fctStream) {
    fctOutput = fctStream;
  }

  static std::shared_ptr<std::ostream> get() { return fctOutput(); }
  static void setSeparator(const std::string &s) { separator = s; }
  static const std::string &getSeparator() { return separator; }
  static void enable(bool flag = true) { enableFlag = flag; }
  static bool isEnable() { return enableFlag; }

private:
  static std::shared_ptr<std::ostream> output;
  static std::function<std::shared_ptr<std::ostream>()> fctOutput;
  static std::string separator;
  static bool enableFlag;
};

template <typename T>
std::shared_ptr<std::ostream> OutputterInternal<T>::output =
    std::make_shared<std::ostream>(std::cout.rdbuf());
template <typename T>
std::function<std::shared_ptr<std::ostream>()> OutputterInternal<T>::fctOutput =
    []() { return OutputterInternal<T>::output; };
template <typename T> std::string OutputterInternal<T>::separator(" ; ");
template <typename T> bool OutputterInternal<T>::enableFlag = true;

class Outputter : public OutputterInternal<void> {};

} // namespace fctlog
