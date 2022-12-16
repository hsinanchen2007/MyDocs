#ifndef DSS_BT_DETACHLEAFNODE
#define DSS_BT_DETACHLEAFNODE

#include "dss/bt/relatives.h"

namespace dss
{
namespace bt
{
template <class Node>
void detachLeafNode(Node* n, Node** root);

template <class Node>
void detachLeafNode(Node* n, Node** root)
{
  if (hasPredecessor(n))
    n->predecessor->successor = n->successor;

  if (hasSuccessor(n))
    n->successor->predecessor = n->predecessor;

  if (isLeftChild(n))
    n->parent->left = nullptr;
  else if (isRightChild(n))
    n->parent->right = nullptr;
  else
    *root = nullptr;

  n->parent = nullptr;
}
};
};

#endif // DSS_BT_DETACHLEAFNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.