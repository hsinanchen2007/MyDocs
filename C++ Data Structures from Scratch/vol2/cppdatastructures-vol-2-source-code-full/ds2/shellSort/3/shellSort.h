#ifndef DS2_SHELLSORT_3_SHELLSORT
#define DS2_SHELLSORT_3_SHELLSORT

#include <vector>

#include "ds2/shellSort/common/generateGapSizes.h"
#include "ds2/shellSort/common/sortAllSubsequences.h"

namespace ds2
{
template <class RanIt, class Predicate>
void shellSort(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void shellSort(RanIt begin, RanIt end, Predicate predicate)
{
  using namespace shell;

  typedef typename RanIt::difference_type GapSize;

  std::vector<GapSize> gapSizes;

  generateGapSizes(&gapSizes, end - begin);

  for (auto g = gapSizes.crbegin(); g != gapSizes.crend(); ++g)
    sortAllSubsequences(begin,
      end,
      *g,
      predicate);
}
};

#endif // DS2_SHELLSORT_3_SHELLSORT

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.