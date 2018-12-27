// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "fctlog/define.h"

namespace fctlog {
template <typename Tfct, typename... Targs> class FunctionLoggerBase {
public:
  FunctionLoggerBase(const std::string &name, Tfct fct, Targs... args)
      : function(fct), name(name) {
    std::cout << ">> " << name << " " << getEntryMsg(args...) << "\n";
  }

  ~FunctionLoggerBase() {
    std::cout << "<< " << name << " " << exitMsg << "\n";
  }

protected:
  Tfct function;
  void setExitMsg(const std::string &msg) { exitMsg = msg; }

private:
  std::string name;
  std::string exitMsg;
  void getEntryMsgInternal(std::stringstream &) {}

  template <typename T, typename... Ts>
  void getEntryMsgInternal(std::stringstream &s, T arg, Ts... args) {
    s << (s.str().empty() ? "args: " : ", ") << arg;
    getEntryMsgInternal(s, args...);
  }

  template <typename... Ts> std::string getEntryMsg(Ts... args) {
    std::stringstream s;
    getEntryMsgInternal(s, args...);
    return s.str();
  }
};

template <typename Tret, typename... Targs>
class FunctionLogger
    : public FunctionLoggerBase<std::function<Tret()>, Targs...> {
public:
  typedef std::function<Tret()> Tfct;
  FunctionLogger(const std::string &name, Tfct fct, Targs... args)
      : FunctionLoggerBase<Tfct, Targs...>(name, fct, args...) {}

  Tret operator()() {
    std::stringstream s;
    try {
      auto ret = FunctionLoggerBase<Tfct, Targs...>::function();
      s << "return: " << ret;
      FunctionLoggerBase<Tfct, Targs...>::setExitMsg(s.str());
      return ret;
    } catch (std::exception &e) {
      s << "throw: " << typeid(e).name() << " '" << e.what() << "'";
      FunctionLoggerBase<Tfct, Targs...>::setExitMsg(s.str());
      throw;
    }
  }
};

template <typename... Targs>
class FunctionLogger<void, Targs...>
    : public FunctionLoggerBase<std::function<void(Targs...)>, Targs...> {
public:
  typedef std::function<void(Targs...)> Tfct;
  FunctionLogger(const std::string &name, Tfct fct, Targs... args)
      : FunctionLoggerBase<Tfct, Targs...>(name, fct, args...) {}

  void operator()() {
    std::stringstream s;
    try {
      FunctionLoggerBase<Tfct, Targs...>::function();
      FunctionLoggerBase<Tfct, Targs...>::setExitMsg("return");
      return;
    } catch (std::exception &e) {
      s << "throw: " << typeid(e).name() << " '" << e.what() << "'";
      FunctionLoggerBase<Tfct, Targs...>::setExitMsg(s.str());
      throw;
    }
  }
};
} // namespace fctlog
