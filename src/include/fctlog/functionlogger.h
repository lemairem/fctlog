// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include "fctlog/config.h"
#include "fctlog/outputter.h"

#ifdef FCTLOG_OSTREAM_CONTAINER
#include "fctlog/ostream.h"
#endif

#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#ifdef CONFIG_FCTLOG_DEMANGLE
#include <cxxabi.h>
#endif
#ifdef CONFIG_FCTLOG_BOOST_EXCEPTION
#include <boost/exception/all.hpp>
#endif

namespace fctlog {

template <typename Tret, typename... Targs> class FunctionLoggerBase {
public:
  typedef typename std::function<Tret()> Tfct;
  FunctionLoggerBase(const std::string &className, const std::string &fctName,
                     Tfct fct, Targs const &... args)
      : function(fct) {
    fullName = className.substr(1, className.size() - 2);
    fullName.append("::");
    fullName.append(fctName);
    Outputter::get() << ">> " << fullName << " " << getEntryMsg(args...)
                     << "\n";
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
  void getEntryMsgInternal(std::stringstream &s, T const &arg,
                           Ts const &... args) {
    s << (s.str().empty() ? "args: " : Outputter::getSeparator()) << arg;
    getEntryMsgInternal(s, args...);
  }

  template <typename... Ts> std::string getEntryMsg(Ts const &... args) {
    std::stringstream s;
    getEntryMsgInternal(s, args...);
    return s.str();
  }
};

template <typename Tret, typename... Targs>
class FunctionLogger : public FunctionLoggerBase<Tret, Targs...> {
  typedef typename FunctionLoggerBase<Tret, Targs...>::Tfct Tfct;

public:
  FunctionLogger(const std::string &className, const std::string &fctName,
                 Tfct fct, Targs... args)
      : FunctionLoggerBase<Tret, Targs...>(className, fctName, fct, args...) {}

  /**
   * Overload for void as return type
   *
   * Executes the internal method and prints either the exception or that the
   * method returned
   */
  template <typename TReturnType = Tret>
  typename std::enable_if<std::is_void<TReturnType>::value, TReturnType>::type
  operator()() {
    std::stringstream s;
    try {
      this->function();
      s << "return";
      this->setExitMsg(s.str());
      return;
    } catch (std::exception &e) {
      this->handle_exception(e, s);
      throw;
    }
#ifdef CONFIG_FCTLOG_BOOST_EXCEPTION
    catch (boost::exception &e) {
      this->handle_exception(e, s);
      throw;
    }
#endif
    catch (...) {
      this->setExitMsg("throw: unknown exception");
      throw;
    }
  }

  /**
   * Overload for non void return types
   *
   * Executes the internal method and prints either the exception or that the
   * method returned with the specific value
   * it returned.
   *
   * @return value of the internally wrapped function.
   */
  template <typename TReturnType = Tret>
  typename std::enable_if<!std::is_void<TReturnType>::value, TReturnType>::type
  operator()() {
    std::stringstream s;
    try {
      auto ret = this->function();
      s << "return: " << ret;
      this->setExitMsg(s.str());
      return ret;
    } catch (std::exception &e) {
      this->handle_exception(e, s);
      throw;
    }
#ifdef CONFIG_FCTLOG_BOOST_EXCEPTION
    catch (boost::exception &e) {
      this->handle_exception(e, s);
      throw;
    }
#endif
    catch (...) {
      this->setExitMsg("throw: unknown exception");
      throw;
    }
  }

private:
  std::string getExceptionMessage(std::exception const &e) { return e.what(); }

#ifdef CONFIG_FCTLOG_BOOST_EXCEPTION
  std::string getExceptionMessage(boost::exception const &e) {
    return boost::diagnostic_information(e);
  }
#endif

  /**
   * Handles the given exception by printing the type and the ::what value to
   * the given stringstream.
   *
   * Demangles the type name if demangling could be found during compile time.
   */
  template <class T> void handle_exception(T const &e, std::stringstream &s) {
    auto const type_id_name = typeid(e).name();
#ifdef CONFIG_FCTLOG_DEMANGLE
    int status = 0;
    auto const demangled_name =
        abi::__cxa_demangle(type_id_name, 0, 0, &status);
    if (demangled_name == nullptr) {
#endif
      s << "throw: " << type_id_name << " '" << getExceptionMessage(e) << "'";
#ifdef CONFIG_FCTLOG_DEMANGLE
    } else {
      // Use a destructor in case something goes wrong during printing, in order
      // to ascertain proper deletion of the demangled name.
      auto deleter = [](char *const ptr) { free(ptr); };
      auto const demangled_unique_ptr =
          std::unique_ptr<char, decltype(deleter)>(demangled_name, deleter);
      s << "throw: " << demangled_name << " '" << getExceptionMessage(e) << "'";
    }
#endif
    this->setExitMsg(s.str());
  }
};

} // namespace fctlog
