#ifndef DSS_BT_FINDINSERTIONPOINT
#define DSS_BT_FINDINSERTIONPOINT

#include "dss/bt/key.h"

namespace dss
{
namespace bt
{
template <class Node, class Predicate>
Node* findInsertionPoint(Node* root,
  const typename Node::key_type& newKey,
  Predicate predicate);

template <class Node, class Predicate>
Node* findInsertionPoint(Node* root,
  const typename Node::key_type& newKey,
  Predicate predicate)
{
  Node* insertionPoint = root;

  for (Node* n = root; n != nullptr;)
  {
    insertionPoint = n;

    if (predicate(newKey, key(n)))
      n = n->left;
    else if (predicate(key(n), newKey))
      n = n->right;
    else
      return n;
  }

  return insertionPoint;
}
};
};

#endif // DSS_BT_FINDINSERTIONPOINT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.