#ifndef DS2_HEAPTRANSFORM_COMMON_POPHEAP
#define DS2_HEAPTRANSFORM_COMMON_POPHEAP

#include <utility>

#include "ds2/heapTransform/common/moveElementDownTree.h"

namespace ds2
{
template <class RanIt, class Predicate>
void popHeap(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void popHeap(RanIt begin, RanIt end, Predicate predicate)
{
  typedef typename RanIt::difference_type Node;

  Node bottom = end - begin - 1;

  std::swap(begin[0], begin[bottom]);

  ht::moveElementDownTree(0,
    begin,
    bottom,
    predicate);
}
};

#endif // DS2_HEAPTRANSFORM_COMMON_POPHEAP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.