// MIT License (see file 'LICENSE' for details)
// Copyright (c) 2018 Lemaire Marc

#pragma once
#include <iostream>
#include <memory>

namespace fctlog {

template <typename T> struct OstreamContainerInternal {
    static int maxElement;
};

template <typename T>
int OstreamContainerInternal<T>::maxElement = 10;

struct OstreamContainer : public OstreamContainerInternal<void> {};

template <template <class, class> class Container, class T, class Alloc = std::allocator <T> >
std::ostream& operator << ( 
std::ostream& os,
const Container <T, Alloc> & container )
{
int count = 0;
os << "[";
for (const T& e : container) {
    os << (count == 0 ? "" : ", ") << e;
    ++count;
    if(count >= OstreamContainer::maxElement) {
        os << ", ...";
        break;
    }
}
return os << "]";
}

} // namespace fctlog    