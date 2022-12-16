#ifndef DS2_SELECTIONSORT_SELECTIONSORT
#define DS2_SELECTIONSORT_SELECTIONSORT

#include <utility>

#include "ds2/findExtreme/findExtreme.h"

namespace ds2
{
template <class Iter, class Predicate>
void selectionSort(Iter begin, Iter end, Predicate predicate);

template <class Iter, class Predicate>
void selectionSort(Iter begin, Iter end, Predicate predicate)
{
  using std::swap;

  Iter back = end;
  --back;

  for (Iter front = begin; front != back; ++front)
    swap(*findExtreme(front, end, predicate), *front);
}
};

#endif // DS2_SELECTIONSORT_SELECTIONSORT

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.