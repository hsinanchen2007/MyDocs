#ifndef DS2_HEAPTRANSFORM_COMMON_MOVEELEMENTDOWNTREE
#define DS2_HEAPTRANSFORM_COMMON_MOVEELEMENTDOWNTREE

#include <utility>

#include "ds2/heapTransform/common/getChildForComparison.h"
#include "ds2/heapTransform/common/relatives.h"

namespace ds2
{
namespace ht
{
template <class Node,
  class RanIt,
  class Size,
  class Predicate>
void moveElementDownTree(Node n,
  RanIt begin,
  Size size,
  Predicate predicate);

template <class Node,
  class RanIt,
  class Size,
  class Predicate>
void moveElementDownTree(Node n,
  RanIt begin,
  Size size,
  Predicate predicate)
{
  while (!isLeaf(n, size))
  {
    Node nChild = getChildForComparison(n,
      begin,
      size,
      predicate);

    if (predicate(begin[n], begin[nChild]))
    {
      std::swap(begin[n], begin[nChild]);
      n = nChild;
    }
    else
    {
      break;
    }
  }
}
};
};

#endif // DS2_HEAPTRANSFORM_COMMON_MOVEELEMENTDOWNTREE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.