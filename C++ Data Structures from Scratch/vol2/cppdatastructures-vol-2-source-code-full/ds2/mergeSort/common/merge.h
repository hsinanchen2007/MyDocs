#ifndef DS2_MERGESORT_COMMON_MERGE
#define DS2_MERGESORT_COMMON_MERGE

#include <vector>

namespace ds2
{
namespace msCommon
{
template <class RanIt, class Predicate>
void merge(RanIt begin,
  RanIt midpoint,
  RanIt end,
  Predicate predicate);

template <class RanIt, class Predicate>
void merge(RanIt begin,
  RanIt midpoint,
  RanIt end,
  Predicate predicate)
{
  typedef typename RanIt::value_type Element;

  std::vector<Element> buffer;
  buffer.reserve(end - begin);

  RanIt x = begin;
  RanIt y = midpoint;

  while (x != midpoint && y != end)
  {
    if (predicate(*x, *y))
      buffer.push_back(*x++);
    else
      buffer.push_back(*y++);
  }

  while (x != midpoint)
    buffer.push_back(*x++);

  while (y != end)
    buffer.push_back(*y++);

  for (const Element& e : buffer)
    *begin++ = e;
}
};
};

#endif // DS2_MERGESORT_COMMON_MERGE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.