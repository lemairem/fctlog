// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <array>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace fctlog {

template <typename T> struct OstreamContainerInternal {
  static int maxElement;
};
template <typename T> int OstreamContainerInternal<T>::maxElement = 10;
struct OstreamContainer : public OstreamContainerInternal<void> {};

namespace internal {
template <typename T> std::ostream &printPtr(std::ostream &os, T *ptr) {
  os << reinterpret_cast<void *>(ptr);
  if (ptr) {
    os << " -> " << *ptr;
  }
  return os;
}
} // namespace internal

template <typename PT, typename DT>
std::ostream &operator<<(std::ostream &os, const std::unique_ptr<PT, DT> &ptr) {
  return internal::printPtr(os, ptr.get());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::shared_ptr<T> &ptr) {
  return internal::printPtr(os, ptr.get());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::weak_ptr<T> &ptr) {
  return os << ptr.lock();
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pair) {
  os << "[" << pair.first << ", " << pair.second << "]";
  return os;
}

namespace internal {
template <template <class, class...> class Container, class T1, class... T2>
std::ostream &printContainer(std::ostream &os,
                             const Container<T1, T2...> &container) {
  int count = 0;
  os << "[";
  for (const auto &e : container) {
    os << (count == 0 ? "" : ", ") << e;
    ++count;
    if (count >= OstreamContainer::maxElement) {
      os << ", ...";
      break;
    }
  }
  return os << "]";
}
} // namespace internal

#define FCTLOG_INTERNAL_CONTAINER_OSTREAM(CONTAINER)                           \
  template <typename T1, typename... T2>                                       \
  std::ostream &operator<<(std::ostream &os,                                   \
                           const CONTAINER<T1, T2...> &container) {            \
    return internal::printContainer(os, container);                            \
  }
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::vector)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::deque)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::forward_list)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::list)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::stack)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::queue)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::set)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::multiset)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::priority_queue)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::unordered_set)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::unordered_multiset)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::map)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::multimap)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::unordered_map)
FCTLOG_INTERNAL_CONTAINER_OSTREAM(std::unordered_multimap)
#undef FCTLOG_INTERNAL_CONTAINER_OSTREAM

template <typename T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &container) {
  return internal::printContainer(os, container);
}

namespace internal {
template <size_t N, typename... T>
typename std::enable_if<(N >= sizeof...(T))>::type
printTuple(std::ostream &, const std::tuple<T...> &) {}

template <size_t N, typename... T>
typename std::enable_if<(N < sizeof...(T))>::type
printTuple(std::ostream &os, const std::tuple<T...> &tuple) {
  if (N != 0) {
    os << ", ";
  }
  os << std::get<N>(tuple);
  printTuple<N + 1>(os, tuple);
}
} // namespace internal

template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tuple) {
  os << "[";
  internal::printTuple<0>(os, tuple);
  return os << "]";
}

inline std::ostream &operator<<(std::ostream &os, const std::uint8_t &val) {
  os << "0x" << std::hex << std::setw(2) << std::setfill('0') << +val;
  return os;
}

} // namespace fctlog
