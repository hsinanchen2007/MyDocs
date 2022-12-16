#ifndef DS2_HEAPTRANSFORM_COMMON_MAKEHEAP
#define DS2_HEAPTRANSFORM_COMMON_MAKEHEAP

#include "ds2/heapTransform/common/moveElementDownTree.h"
#include "ds2/heapTransform/common/relatives.h"

namespace ds2
{
template <class RanIt, class Predicate>
void makeHeap(RanIt begin, RanIt end, Predicate predicate);

template <class RanIt, class Predicate>
void makeHeap(RanIt begin, RanIt end, Predicate predicate)
{
  using namespace ht;

  typedef typename RanIt::difference_type Node;

  Node bottom = end - begin - 1;

  for (Node n = parent(bottom); n >= 0; --n)
  {
    moveElementDownTree(n,
      begin,
      end - begin,
      predicate);
  }
}
};

#endif // DS2_HEAPTRANSFORM_COMMON_MAKEHEAP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.