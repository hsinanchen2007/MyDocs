#include "dss/bt/relatives.h"
#include "dss/bt/rotate.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
void BinaryTree<Key, Mapped, Predicate>::rotate(const_iterator rotationPoint)
{
  using namespace bt;

  Node* n = rotationPoint._i._node;

  if (isLeftChild(n))
    rotateRight(n, &_root);
  else if (isRightChild(n))
    rotateLeft(n, &_root);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.