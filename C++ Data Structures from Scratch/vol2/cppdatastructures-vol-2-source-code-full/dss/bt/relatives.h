#ifndef DSS_BT_RELATIVES
#define DSS_BT_RELATIVES

namespace dss
{
namespace bt
{
template <class Node>
bool isRoot(const Node* n);

template <class Node>
bool isLeaf(const Node* n);

template <class Node>
bool isLeftChild(const Node* n);

template <class Node>
bool isRightChild(const Node* n);

template <class Node>
bool hasLeftChild(const Node* n);

template <class Node>
bool hasRightChild(const Node* n);

template <class Node>
bool hasPredecessor(const Node* n);

template <class Node>
bool hasSuccessor(const Node* n);

template <class Node>
Node* leftmostNode(Node* n);

template <class Node>
Node* rightmostNode(Node* n);

template <class Node>
inline bool isRoot(const Node* n)
{
  return n->parent == nullptr;
}

template <class Node>
inline bool isLeaf(const Node* n)
{
  return !hasLeftChild(n) && !hasRightChild(n);
}

template <class Node>
inline bool isLeftChild(const Node* n)
{
  return !isRoot(n) && (n == n->parent->left);
}

template <class Node>
inline bool isRightChild(const Node* n)
{
  return !isRoot(n) && (n == n->parent->right);
}

template <class Node>
inline bool hasLeftChild(const Node* n)
{
  return n->left != nullptr;
}

template <class Node>
inline bool hasRightChild(const Node* n)
{
  return n->right != nullptr;
}

template <class Node>
inline bool hasPredecessor(const Node* n)
{
  return n->predecessor != nullptr;
}

template <class Node>
inline bool hasSuccessor(const Node* n)
{
  return n->successor != nullptr;
}

template <class Node>
Node* leftmostNode(Node* n)
{
  while (n->left != nullptr)
    n = n->left;

  return n;
}

template <class Node>
Node* rightmostNode(Node* n)
{
  while (n->right != nullptr)
    n = n->right;

  return n;
}
};
};

#endif // DSS_BT_RELATIVES

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.