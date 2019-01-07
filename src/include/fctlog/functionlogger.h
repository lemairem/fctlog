// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include "fctlog/define.h"
#include "fctlog/outputter.h"

#ifdef FCTLOG_OSTREAM_CONTAINER
#include "fctlog/ostream.h"
#endif

#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>

namespace fctlog {

template <typename Tret, typename... Targs> class FunctionLoggerBase {
public:
  typedef typename std::function<Tret()> Tfct;
  FunctionLoggerBase(const std::string &className, const std::string &fctName, Tfct fct, Targs... args)
      : function(fct) {
    fullName = className.substr(1, className.size() - 2);
    fullName.append("::");
    fullName.append(fctName);
    Outputter::get() << ">> " << fullName << " " << getEntryMsg(args...) << "\n";
  }

  ~FunctionLoggerBase() {
    Outputter::get() << "<< " << fullName << " " << exitMsg << "\n";
  }

protected:
  Tfct function;
  void setExitMsg(const std::string &msg) { exitMsg = msg; }

private:
  std::string fullName;
  std::string exitMsg;
  void getEntryMsgInternal(std::stringstream &s) {
    if (s.str().empty()) {
      s << "no_args";
    }
  }

  template <typename T, typename... Ts>
  void getEntryMsgInternal(std::stringstream &s, T arg, Ts... args) {
    s << (s.str().empty() ? "args: " : " ; ") << arg;
    getEntryMsgInternal(s, args...);
  }

  template <typename... Ts> std::string getEntryMsg(Ts... args) {
    std::stringstream s;
    getEntryMsgInternal(s, args...);
    return s.str();
  }
};

template <typename Tret, typename... Targs>
class FunctionLogger : public FunctionLoggerBase<Tret, Targs...> {
  typedef typename FunctionLoggerBase<Tret, Targs...>::Tfct Tfct;

public:
  FunctionLogger(const std::string &className, const std::string &fctName, Tfct fct, Targs... args)
      : FunctionLoggerBase<Tret, Targs...>(className, fctName, fct, args...) {}

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
  FunctionLogger(const std::string &className, const std::string &fctName, Tfct fct, Targs... args)
      : FunctionLoggerBase<void, Targs...>(className, fctName, fct, args...) {}

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
