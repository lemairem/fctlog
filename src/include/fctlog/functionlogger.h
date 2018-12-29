// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>
#include "fctlog/define.h"
#include "fctlog/outputter.h"

namespace fctlog {

template <typename Tret, typename... Targs> class FunctionLoggerBase {
public:
  typedef typename std::function<Tret()> Tfct;
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
    : public FunctionLoggerBase<Tret, Targs...> {
  typedef typename FunctionLoggerBase<Tret, Targs...>::Tfct Tfct;

public:
  FunctionLogger(const std::string &name, Tfct fct, Targs... args)
      : FunctionLoggerBase<Tret, Targs...>(name, fct, args...) {}

  Tret operator()() {
    std::stringstream s;
    try {
      auto ret = this->function();
      s << "return: " << ret;
      this->setExitMsg(s.str());
      return ret;
    } catch (std::exception &e) {
      s << "throw: " << typeid(e).name() << " '" << e.what() << "'";
      this->setExitMsg(s.str());
      throw;
    }
  }
};

template <typename... Targs>
class FunctionLogger<void, Targs...>
    : public FunctionLoggerBase<void, Targs...> {
  typedef typename FunctionLoggerBase<void, Targs...>::Tfct Tfct;

public:
  FunctionLogger(const std::string &name, Tfct fct, Targs... args)
      : FunctionLoggerBase<void, Targs...>(name, fct, args...) {}

  void operator()() {
    std::stringstream s;
    try {
      this->function();
      this->setExitMsg("return");
      return;
    } catch (std::exception &e) {
      s << "throw: " << typeid(e).name() << " '" << e.what() << "'";
      this->setExitMsg(s.str());
      throw;
    }
  }
};

} // namespace fctlog