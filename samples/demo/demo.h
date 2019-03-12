// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <string>
#include <memory>

namespace fctlog {

class Demo {
public:
  virtual ~Demo() = default;
  virtual void fv();
  virtual int f0();
  virtual int f0Const() const;
  virtual int f1(int val = 0);
  virtual int f2(int val = 0, const std::string &str = "");
  virtual int f2Const(int x, int y) const;
  virtual int f3(std::unique_ptr<int>& foo) const;
};

} // namespace fctlog
