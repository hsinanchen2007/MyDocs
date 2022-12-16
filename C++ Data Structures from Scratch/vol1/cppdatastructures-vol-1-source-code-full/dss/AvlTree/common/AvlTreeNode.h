#ifndef DSS_AVLTREE_COMMON_AVLTREENODE
#define DSS_AVLTREE_COMMON_AVLTREENODE

#include "dss/Pair/Pair.h"

namespace dss
{
template <class Key, class Mapped>
struct AvlTreeNode
{
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef Pair<const Key, Mapped> value_type;

  AvlTreeNode(const value_type& sourceElement);

  value_type element;

  AvlTreeNode* parent;
  AvlTreeNode* left;
  AvlTreeNode* right;

  AvlTreeNode* predecessor;
  AvlTreeNode* successor;

  int balanceFactor;
};

template <class Key, class Mapped>
AvlTreeNode<Key, Mapped>::AvlTreeNode(const value_type& sourceElement):
  element(sourceElement),
  parent(nullptr),
  left(nullptr),
  right(nullptr),
  predecessor(nullptr),
  successor(nullptr),
  balanceFactor(0)
{
  // ...
}
};

#endif // DSS_AVLTREE_COMMON_AVLTREENODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.