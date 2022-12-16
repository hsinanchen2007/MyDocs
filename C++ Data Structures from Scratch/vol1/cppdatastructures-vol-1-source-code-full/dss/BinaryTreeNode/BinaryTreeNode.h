#ifndef DSS_BINARYTREENODE_BINARYTREENODE
#define DSS_BINARYTREENODE_BINARYTREENODE

#include "dss/Pair/Pair.h"

namespace dss
{
template <class Key, class Mapped>
struct BinaryTreeNode
{
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef Pair<const Key, Mapped> value_type;

  BinaryTreeNode(const value_type& sourceElement);

  value_type element;

  BinaryTreeNode* parent;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode* predecessor;
  BinaryTreeNode* successor;
};

template <class Key, class Mapped>
BinaryTreeNode<Key, Mapped>::BinaryTreeNode(const value_type& sourceElement):
  element(sourceElement),
  parent(nullptr),
  left(nullptr),
  right(nullptr),
  predecessor(nullptr),
  successor(nullptr)
{
  // ...
}
};

#endif // DSS_BINARYTREENODE_BINARYTREENODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.