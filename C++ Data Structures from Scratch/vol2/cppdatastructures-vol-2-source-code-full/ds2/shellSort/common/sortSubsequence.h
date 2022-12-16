#ifndef DS2_SHELLSORT_COMMON_SORTSUBSEQUENCE
#define DS2_SHELLSORT_COMMON_SORTSUBSEQUENCE

#include <utility>

namespace ds2
{
namespace shell
{
template <class RanIt, class Predicate>
void sortSubsequence(RanIt subsequenceBegin,
  RanIt sequenceEnd,
  typename RanIt::difference_type gapSize,
  Predicate predicate);

template <class RanIt, class Predicate>
void moveElement(RanIt element,
  RanIt subsequenceBegin,
  typename RanIt::difference_type gapSize,
  Predicate predicate);

template <class RanIt, class Predicate>
void sortSubsequence(RanIt subsequenceBegin,
  RanIt sequenceEnd,
  typename RanIt::difference_type gapSize,
  Predicate predicate)
{
  for (RanIt element = subsequenceBegin + gapSize;
    element < sequenceEnd;
    element += gapSize)
  {
    moveElement(element,
      subsequenceBegin,
      gapSize,
      predicate);
  }
}

template <class RanIt, class Predicate>
void moveElement(RanIt element,
  RanIt subsequenceBegin,
  typename RanIt::difference_type gapSize,
  Predicate predicate)
{
  while (element != subsequenceBegin)
  {
    RanIt leftNeighbor = element - gapSize;

    if (predicate(*element, *leftNeighbor))
    {
      std::swap(*element, *leftNeighbor);
      element = leftNeighbor;
    }
    else
    {
      break;
    }
  }
}
};
};

#endif // DS2_SHELLSORT_COMMON_SORTSUBSEQUENCE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.