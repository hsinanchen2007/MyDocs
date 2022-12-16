#ifndef DS2_MERGESORT_3_MERGESORT
#define DS2_MERGESORT_3_MERGESORT

#include "ds2/mergeSort/common/merge.h"
#include "ds2/mergeSort/common/split.h"

namespace ds2
{
template <class RanIt, class Predicate>
void mergeSort(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void mergeSort(RanIt begin, RanIt end, Predicate predicate)
{
  using namespace msCommon;

  if (end - begin > 1)
  {
    RanIt midpoint = split(begin, end);

    mergeSort(begin, midpoint, predicate);
    mergeSort(midpoint, end, predicate);

    merge(begin, midpoint, end, predicate);
  }
}
};

#endif // DS2_MERGESORT_3_MERGESORT

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.