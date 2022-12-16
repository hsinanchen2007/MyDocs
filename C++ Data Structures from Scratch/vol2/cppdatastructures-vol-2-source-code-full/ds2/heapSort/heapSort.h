#ifndef DS2_HEAPSORT_HEAPSORT
#define DS2_HEAPSORT_HEAPSORT

#include "ds2/heapTransform/3/heapTransform.h"

namespace ds2
{
template <class RanIt, class Predicate>
void heapSort(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void heapSort(RanIt begin, RanIt end, Predicate predicate)
{
  makeHeap(begin, end, predicate);

  while (end != begin)
  {
    popHeap(begin, end, predicate);
    --end;
  }
}
};

#endif // DS2_HEAPSORT_HEAPSORT

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.