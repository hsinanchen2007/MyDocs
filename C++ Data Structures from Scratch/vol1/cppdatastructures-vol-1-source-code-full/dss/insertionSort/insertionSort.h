#ifndef DSS_INSERTIONSORT_INSERTIONSORT
#define DSS_INSERTIONSORT_INSERTIONSORT

#include "dss/swap/swap.h"

namespace dss
{
template <class Iter, class Predicate>
void insertionSort(Iter begin, Iter end, Predicate predicate);

template <class Iter, class Predicate>
void insertionSort(Iter begin, Iter end, Predicate predicate)
{
  for (Iter current = begin; current != end; ++current)
  {
    Iter y = current;
    Iter x = current;
    --x;

    while (y != begin && predicate(*y, *x))
    {
      swap(*y, *x);
      --y;
      --x;
    }
  }
}
};

#endif // DSS_INSERTIONSORT_INSERTIONSORT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.