#ifndef DSS_QUICKSORT_QUICKSORT
#define DSS_QUICKSORT_QUICKSORT

#include "dss/swap/swap.h"

namespace dss
{
template <class Iter, class Predicate>
void quickSort(Iter begin, Iter end, Predicate predicate);

template <class Iter, class Predicate>
Iter _partition(Iter begin, Iter end, Predicate predicate);

template <class Iter>
Iter _xNextElement(Iter x, Iter begin, Iter end);

template <class Iter, class Predicate>
void quickSort(Iter begin, Iter end, Predicate predicate)
{
  if (begin != end)
  {
    Iter pivot = _partition(begin, end, predicate);

    quickSort(begin, pivot, predicate);
    quickSort(++pivot, end, predicate);
  }
}

template <class Iter, class Predicate>
Iter _partition(Iter begin, Iter end, Predicate predicate)
{
  Iter pivot = end;
  Iter x = end;

  --pivot;

  for (Iter y = begin; y != pivot; ++y)
  {
    if (predicate(*y, *pivot))
    {
      x = _xNextElement(x, begin, end);
      swap(*x, *y);
    }
  }

  x = _xNextElement(x, begin, end);
  swap(*x, *pivot);

  return x;
}

template <class Iter>
Iter _xNextElement(Iter x, Iter begin, Iter end)
{
  if (x == end)
    return begin;
  else
    return ++x;
}
};

#endif // DSS_QUICKSORT_QUICKSORT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.