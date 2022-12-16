#ifndef DSS_PAIR_PAIRIO
#define DSS_PAIR_PAIRIO

#include <iostream>

#include "dss/Pair/Pair.h"

namespace dss
{
template <class A, class B>
std::ostream& operator<<(std::ostream& lhs, const Pair<A, B>& rhs);

template <class A, class B>
std::istream& operator>>(std::istream& lhs, Pair<A, B>& rhs);

template <class A, class B>
inline std::ostream& operator<<(std::ostream& lhs, const Pair<A, B>& rhs)
{
  lhs << '(' << rhs.first << ',' << rhs.second << ')';

  return lhs;
}

template <class A, class B>
std::istream& operator>>(std::istream& lhs, Pair<A, B>& rhs)
{
  lhs >> rhs.first >> rhs.second;

  return lhs;
}
};

#endif // DSS_PAIR_PAIRIO

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.