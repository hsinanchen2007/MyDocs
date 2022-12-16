#ifndef DS2_BINARYSEARCH_BINARYSEARCH
#define DS2_BINARYSEARCH_BINARYSEARCH

#include <functional>

#include "ds2/bound/bound.h"

namespace ds2
{
template <class Iter, class T>
Iter binarySearch(Iter begin, Iter end, const T& value);

template <class Iter, class T, class Predicate>
Iter binarySearch(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate);

template <class Iter, class T>
inline Iter binarySearch(Iter begin, Iter end, const T& value)
{
  return binarySearch(begin, end, value, std::less<T>());
}

template <class Iter, class T, class Predicate>
Iter binarySearch(Iter begin,
  Iter end,
  const T& value,
  Predicate predicate)
{
  Iter _lowerBound = lowerBound(begin, end, value, predicate);

  if (_lowerBound != end && !predicate(value, *_lowerBound))
    return _lowerBound;
  else
    return end;
}
};

#endif // DS2_BINARYSEARCH_BINARYSEARCH

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.