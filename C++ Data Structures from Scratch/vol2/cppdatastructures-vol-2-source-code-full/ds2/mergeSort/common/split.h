#ifndef DS2_MERGESORT_COMMON_SPLIT
#define DS2_MERGESORT_COMMON_SPLIT

#include <cmath>

namespace ds2
{
namespace msCommon
{
template <class RanIt>
RanIt split(RanIt begin, RanIt end);

template <class RanIt>
RanIt split(RanIt begin, RanIt end)
{
  typedef typename RanIt::difference_type Distance;

  Distance midpointDistance = static_cast<Distance>(
    ceil((end - begin) / 2.0));

  return begin + midpointDistance;
}
};
};

#endif // DS2_MERGESORT_COMMON_SPLIT

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.