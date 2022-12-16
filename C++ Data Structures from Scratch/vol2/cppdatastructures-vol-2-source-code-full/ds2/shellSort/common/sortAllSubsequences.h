#ifndef DS2_SHELLSORT_COMMON_SORTALLSUBSEQUENCES
#define DS2_SHELLSORT_COMMON_SORTALLSUBSEQUENCES

#include "ds2/shellSort/common/sortSubsequence.h"

namespace ds2
{
namespace shell
{
template <class RanIt, class Predicate>
void sortAllSubsequences(RanIt sequenceBegin,
  RanIt sequenceEnd,
  typename RanIt::difference_type gapSize,
  Predicate predicate);

template <class RanIt, class Predicate>
void sortAllSubsequences(RanIt sequenceBegin,
  RanIt sequenceEnd,
  typename RanIt::difference_type gapSize,
  Predicate predicate)
{
  for (typename RanIt::difference_type s = 0; s != gapSize; ++s)
    sortSubsequence(sequenceBegin + s,
      sequenceEnd,
      gapSize,
      predicate);
}
};
};

#endif // DS2_SHELLSORT_COMMON_SORTALLSUBSEQUENCES

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.