#ifndef DSS_INORDERITERATIVE_INORDERITERATIVE
#define DSS_INORDERITERATIVE_INORDERITERATIVE

#include "dss/bt/relatives.h"

namespace dss
{
template <class Node>
Node* inOrderPredecessor(Node* n);

template <class Node>
Node* inOrderSuccessor(Node* n);

template <class Node>
Node* inOrderPredecessor(Node* n)
{
  using namespace bt;

  if (hasLeftChild(n))
  {
    return rightmostNode(n->left);
  }
  else if (isRightChild(n))
  {
    return n->parent;
  }
  else
  {
    for (Node* p = n->parent; p != nullptr; p = p->parent)
      if (isRightChild(p))
        return p->parent;

    return nullptr;
  }
}

template <class Node>
Node* inOrderSuccessor(Node* n)
{
  using namespace bt;

  if (hasRightChild(n))
  {
    return leftmostNode(n->right);
  }
  else if (isLeftChild(n))
  {
    return n->parent;
  }
  else
  {
    for (Node* p = n->parent; p != nullptr; p = p->parent)
      if (isLeftChild(p))
        return p->parent;

    return nullptr;
  }
}
};

#endif // DSS_INORDERITERATIVE_INORDERITERATIVE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.