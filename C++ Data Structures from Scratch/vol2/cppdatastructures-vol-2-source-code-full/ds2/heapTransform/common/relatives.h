#ifndef DS2_HEAPTRANSFORM_COMMON_RELATIVES
#define DS2_HEAPTRANSFORM_COMMON_RELATIVES

#include <cmath>

namespace ds2
{
namespace ht
{
template <class Node>
Node parent(Node n);

template <class Node>
Node leftChild(Node n);

template <class Node>
Node rightChild(Node n);

template <class Node, class Size>
bool isLeaf(Node n, Size size);

template <class Node, class Size>
bool hasTwoChildren(Node n, Size size);

template <class Node>
inline Node parent(Node n)
{
  return static_cast<Node>(std::ceil(n / 2.0)) - 1;
};

template <class Node>
inline Node leftChild(Node n)
{
  return 2*n + 1;
}

template <class Node>
inline Node rightChild(Node n)
{
  return leftChild(n) + 1;
}

template <class Node, class Size>
inline bool isLeaf(Node n, Size size)
{
  return leftChild(n) >= size;
}

template <class Node, class Size>
inline bool hasTwoChildren(Node n, Size size)
{
  return rightChild(n) < size;
}
};
};

#endif // DS2_HEAPTRANSFORM_COMMON_RELATIVES

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.