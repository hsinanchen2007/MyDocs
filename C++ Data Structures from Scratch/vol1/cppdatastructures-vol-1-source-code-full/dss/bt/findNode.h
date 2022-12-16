#ifndef DSS_BT_FINDNODE
#define DSS_BT_FINDNODE

#include "dss/bt/key.h"

namespace dss
{
namespace bt
{
template <class Node, class Predicate>
Node* findNode(Node* root,
  const typename Node::key_type& searchKey,
  Predicate predicate);

template <class Node, class Predicate>
Node* findNode(Node* root,
  const typename Node::key_type& searchKey,
  Predicate predicate)
{
  for (Node* n = root; n != nullptr;)
  {
    if (predicate(searchKey, key(n)))
      n = n->left;
    else if (predicate(key(n), searchKey))
      n = n->right;
    else
      return n;
  }

  return nullptr;
}
};
};

#endif // DSS_BT_FINDNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.