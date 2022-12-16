#include "dss/bt/findNode.h"

namespace dss
{
inline DemoBinaryTree::const_iterator DemoBinaryTree::find(
  const key_type& searchKey) const
{
  return const_cast<DemoBinaryTree*>(this)->find(searchKey);
}

inline DemoBinaryTree::iterator DemoBinaryTree::find(
  const key_type& searchKey)
{
  return iterator(this, bt::findNode(_root, searchKey, _predicate));
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.