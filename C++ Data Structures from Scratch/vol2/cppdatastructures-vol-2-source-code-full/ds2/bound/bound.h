#ifndef DS2_BOUND_BOUND
#define DS2_BOUND_BOUND

#include <functional>
#include <iterator>

#include "ds2/advance/advance.h"
#include "ds2/bound/UpperBoundPredicate.h"
#include "ds2/distance/distance.h"

namespace ds2
{
template <class Iter, class T>
Iter lowerBound(Iter begin, Iter end, const T& value);

template <class Iter, class T, class Predicate>
Iter lowerBound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate);

template <class Iter, class T>
Iter upperBound(Iter begin, Iter end, const T& value);

template <class Iter, class T, class Predicate>
Iter upperBound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate);

template <class Iter, class T, class Predicate>
Iter bound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate);

template <class Iter, class T>
inline Iter lowerBound(Iter begin, Iter end, const T& value)
{
  return bound(begin, end, value, std::less<T>());
}

template <class Iter, class T, class Predicate>
inline Iter lowerBound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate)
{
  return bound(begin, end, value, predicate);
}

template <class Iter, class T>
inline Iter upperBound(Iter begin, Iter end, const T& value)
{
  return bound(begin, end, value, UpperBoundPredicate<std::less<T>>());
}

template <class Iter, class T, class Predicate>
inline Iter upperBound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate)
{
  return bound(begin, end, value, UpperBoundPredicate<Predicate>(predicate));
}

template <class Iter, class T, class Predicate>
Iter bound(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate)
{
  typedef typename std::iterator_traits<Iter>::difference_type Length;
  Length subsequenceLength = ds2::distance(begin, end);

  while (subsequenceLength > 0)
  {
    Length midpointDistance = subsequenceLength / 2;

    Iter midpoint = begin;
    ds2::advance(midpoint, midpointDistance);

    if (predicate(*midpoint, value))
    {
      begin = midpoint;
      ++begin;
      subsequenceLength -= midpointDistance + 1;
    }
    else
    {
      subsequenceLength = midpointDistance;
    }
  }

  return begin;
}
};

#endif // DS2_BOUND_BOUND

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.