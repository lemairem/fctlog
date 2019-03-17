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

// TODO: ostream for map, multimap, unordered_map, unordered_multimap

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

namespace internal {
template <template <class, class...> class Container, class T1, class... T2>
std::ostream &printContainer(std::ostream &os,
                             const Container<T1, T2...> &container) {
  int count = 0;
  os << "[";
  for (const T1 &e : container) {
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

#define FCTLOG_INTERNAL_CONTAINER_OSTREAM2(CONTAINER)                          \
  template <typename T1, typename T2>                                          \
  std::ostream &operator<<(std::ostream &os,                                   \
                           const CONTAINER<T1, T2> &container) {               \
    return internal::printContainer(os, container);                            \
  }
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::vector)
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::deque)
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::forward_list)
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::list)
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::stack)
FCTLOG_INTERNAL_CONTAINER_OSTREAM2(std::queue)
#undef FCTLOG_INTERNAL_CONTAINER_OSTREAM2

#define FCTLOG_INTERNAL_CONTAINER_OSTREAM3(CONTAINER)                          \
  template <typename T1, typename T2, typename T3>                             \
  std::ostream &operator<<(std::ostream &os,                                   \
                           const CONTAINER<T1, T2, T3> &container) {           \
    return internal::printContainer(os, container);                            \
  }
FCTLOG_INTERNAL_CONTAINER_OSTREAM3(std::set)
FCTLOG_INTERNAL_CONTAINER_OSTREAM3(std::multiset)
FCTLOG_INTERNAL_CONTAINER_OSTREAM3(std::priority_queue)
#undef FCTLOG_INTERNAL_CONTAINER_OSTREAM3

#define FCTLOG_INTERNAL_CONTAINER_OSTREAM4(CONTAINER)                          \
  template <typename T1, typename T2, typename T3, typename T4>                \
  std::ostream &operator<<(std::ostream &os,                                   \
                           const CONTAINER<T1, T2, T3, T4> &container) {       \
    return internal::printContainer(os, container);                            \
  }
FCTLOG_INTERNAL_CONTAINER_OSTREAM4(std::unordered_set)
FCTLOG_INTERNAL_CONTAINER_OSTREAM4(std::unordered_multiset)
#undef FCTLOG_INTERNAL_CONTAINER_OSTREAM4

template <typename T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &container) {
  return internal::printContainer(os, container);
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pair) {
  os << "[" << pair.first << ", " << pair.second << "]";
  return os;
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
