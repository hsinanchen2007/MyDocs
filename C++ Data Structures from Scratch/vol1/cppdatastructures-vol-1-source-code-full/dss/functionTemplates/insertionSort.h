#ifndef DSS_FUNCTIONTEMPLATES_INSERTIONSORT
#define DSS_FUNCTIONTEMPLATES_INSERTIONSORT

#include "dss/swap/swap.h"

namespace dss
{
template <class Iter>
void insertionSort(Iter begin, Iter end);

template <class Iter>
void insertionSort(Iter begin, Iter end)
{
  for (Iter current = begin; current != end; ++current)
  {
    Iter y = current;
    Iter x = current;
    --x;

    while (y != begin && *y < *x)
    {
      swap(*y, *x);
      --y;
      --x;
    }
  }
}
};

#endif // DSS_FUNCTIONTEMPLATES_INSERTIONSORT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.