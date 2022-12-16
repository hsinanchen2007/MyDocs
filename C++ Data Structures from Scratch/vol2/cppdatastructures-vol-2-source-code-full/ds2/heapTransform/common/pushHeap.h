#ifndef DS2_HEAPTRANSFORM_COMMON_PUSHHEAP
#define DS2_HEAPTRANSFORM_COMMON_PUSHHEAP

#include <utility>

#include "ds2/heapTransform/common/relatives.h"

namespace ds2
{
template <class RanIt, class Predicate>
void pushHeap(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void pushHeap(RanIt begin, RanIt end, Predicate predicate)
{
  typedef typename RanIt::difference_type Node;

  for (Node n = end - begin - 1; n > 0; true)
  {
    Node nParent = ht::parent(n);

    if (predicate(begin[n], begin[nParent]))
    {
      break;
    }
    else
    {
      std::swap(begin[n], begin[nParent]);
      n = nParent;
    }
  }
}
};

#endif // DS2_HEAPTRANSFORM_COMMON_PUSHHEAP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.