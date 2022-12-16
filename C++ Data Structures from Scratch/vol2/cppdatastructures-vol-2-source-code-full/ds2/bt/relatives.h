#ifndef DS2_BT_RELATIVES
#define DS2_BT_RELATIVES

#include "dss/bt/relatives.h"

namespace ds2
{
namespace bt
{
template <class Node>
bool hasGrandparent(const Node* n);

template <class Node>
bool hasUncle(const Node* n);

template <class Node>
Node* grandparent(Node* n);

template <class Node>
Node* uncle(Node* n);

template <class Node>
Node* sibling(Node* n);

template <class Node>
inline bool hasGrandparent(const Node* n)
{
  using dss::bt::isRoot;

  return !isRoot(n) && !isRoot(n->parent);
}

template <class Node>
bool hasUncle(const Node* n)
{
  using namespace dss::bt;

  if (!hasGrandparent(n))
    return false;
  else if (isLeftChild(n->parent))
    return hasRightChild(grandparent(n));
  else
    return hasLeftChild(grandparent(n));
}

template <class Node>
inline Node* grandparent(Node* n)
{
  return n->parent->parent;
}

template <class Node>
Node* uncle(Node* n)
{
  using dss::bt::isLeftChild;

  if (isLeftChild(n->parent))
    return grandparent(n)->right;
  else
    return grandparent(n)->left;
}

template <class Node>
Node* sibling(Node* n)
{
  using namespace dss::bt;

  if (isRoot(n))
    return nullptr;
  else if (isLeftChild(n))
    return n->parent->right;
  else
    return n->parent->left;
}
};
};

#endif // DS2_BT_RELATIVES

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.