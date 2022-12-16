#ifndef DSS_BT_DETACHONECHILDNODE
#define DSS_BT_DETACHONECHILDNODE

#include "dss/bt/relatives.h"

namespace dss
{
namespace bt
{
template <class Node>
void detachOneChildNode(Node* n, Node** root);

template <class Node>
void detachOneChildNode(Node* n, Node** root)
{
  if (hasPredecessor(n))
    n->predecessor->successor = n->successor;

  if (hasSuccessor(n))
    n->successor->predecessor = n->predecessor;

  Node* nOrphan;

  if (hasLeftChild(n))
    nOrphan = n->left;
  else
    nOrphan = n->right;

  nOrphan->parent = n->parent;

  if (isLeftChild(n))
    n->parent->left = nOrphan;
  else if (isRightChild(n))
    n->parent->right = nOrphan;
  else
    *root = nOrphan;

  n->parent = nullptr;
  n->left = nullptr;
  n->right = nullptr;
}
};
};

#endif // DSS_BT_DETACHONECHILDNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.