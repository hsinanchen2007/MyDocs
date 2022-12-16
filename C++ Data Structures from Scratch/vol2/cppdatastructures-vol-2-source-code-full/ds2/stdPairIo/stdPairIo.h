#ifndef DS2_STDPAIRIO_STDPAIRIO
#define DS2_STDPAIRIO_STDPAIRIO

#include <iostream>
#include <utility>

namespace std
{
template <class A, class B>
std::ostream& operator<<(std::ostream& lhs, const std::pair<A, B>& rhs);

template <class A, class B>
std::istream& operator>>(std::istream& lhs, std::pair<A, B>& rhs);

template <class A, class B>
inline std::ostream& operator<<(std::ostream& lhs, const std::pair<A, B>& rhs)
{
  lhs << '(' << rhs.first << ',' << rhs.second << ')';

  return lhs;
}

template <class A, class B>
inline std::istream& operator>>(std::istream& lhs, std::pair<A, B>& rhs)
{
  lhs >> rhs.first >> rhs.second;

  return lhs;
}
};

#endif // DS2_STDPAIRIO_STDPAIRIO

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.