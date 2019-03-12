// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

namespace fctlog {

template <typename T> struct OstreamContainerInternal {
  static int maxElement;
};

template <typename T> int OstreamContainerInternal<T>::maxElement = 10;

struct OstreamContainer : public OstreamContainerInternal<void> {};

template <typename PT, typename DT>
std::ostream &operator<<(std::ostream &os, const std::unique_ptr<PT, DT> &ptr) {
  return os << reinterpret_cast<void *>(ptr.get());
}

template <typename PT, typename DT>
std::ostream &operator<<(std::ostream &os, const std::vector<PT, DT> &vector) {
  int count = 0;
  os << "[";
  for (const PT &e : vector) {
    os << (count == 0 ? "" : ", ") << e;
    ++count;
    if (count >= OstreamContainer::maxElement) {
      os << ", ...";
      break;
    }
  }
  return os << "]";
}

inline std::ostream &operator<<(std::ostream &os, const std::uint8_t &val) {
  os << "0x" << std::hex << std::setw(2) << std::setfill('0') << +val;
  return os;
}

} // namespace fctlog
