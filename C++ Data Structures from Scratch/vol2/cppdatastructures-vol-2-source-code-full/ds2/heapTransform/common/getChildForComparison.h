#ifndef DS2_HEAPTRANSFORM_COMMON_GETCHILDFORCOMPARISON
#define DS2_HEAPTRANSFORM_COMMON_GETCHILDFORCOMPARISON

#include "ds2/heapTransform/common/relatives.h"

namespace ds2
{
namespace ht
{
template <class Node,
  class RanIt,
  class Size,
  class Predicate>
Node getChildForComparison(Node n,
  RanIt begin,
  Size size,
  Predicate predicate);

template <class Node,
  class RanIt,
  class Size,
  class Predicate>
Node getChildForComparison(Node n,
  RanIt begin,
  Size size,
  Predicate predicate)
{
  Node nLeft = leftChild(n);
  Node nRight = rightChild(n);

  if (hasTwoChildren(n, size))
  {
    if (predicate(begin[nLeft], begin[nRight]))
      return nRight;
    else
      return nLeft;
  }
  else
  {
    return nLeft;
  }
}
};
};

#endif // DS2_HEAPTRANSFORM_COMMON_GETCHILDFORCOMPARISON

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.