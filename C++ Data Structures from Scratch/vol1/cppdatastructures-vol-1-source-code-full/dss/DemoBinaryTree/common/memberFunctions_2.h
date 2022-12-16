#include "dss/bt/relatives.h"
#include "dss/inOrderIterative/inOrderIterative.h"

namespace dss
{
DemoBinaryTree::DemoBinaryTree()
{
  _createAllNodes();
  _setParentAndChildLinks();

  _root = _n[7];
  _head = bt::leftmostNode(_root);
  _tail = bt::rightmostNode(_root);

  Node* n = _head;
  while (n != nullptr)
  {
    n->predecessor = inOrderPredecessor(n);
    n->successor = inOrderSuccessor(n);
    n = n->successor;
  }
}

inline DemoBinaryTree::const_iterator DemoBinaryTree::begin() const
{
  return const_cast<DemoBinaryTree*>(this)->begin();
}

inline DemoBinaryTree::const_iterator DemoBinaryTree::end() const
{
  return const_cast<DemoBinaryTree*>(this)->end();
}

inline DemoBinaryTree::const_reverse_iterator DemoBinaryTree::rbegin() const
{
  return const_reverse_iterator(end());
}

inline DemoBinaryTree::const_reverse_iterator DemoBinaryTree::rend() const
{
  return const_reverse_iterator(begin());
}

inline DemoBinaryTree::iterator DemoBinaryTree::begin()
{
  return iterator(this, _head);
}

inline DemoBinaryTree::iterator DemoBinaryTree::end()
{
  return iterator(this, nullptr);
}

inline DemoBinaryTree::reverse_iterator DemoBinaryTree::rbegin()
{
  return reverse_iterator(end());
}

inline DemoBinaryTree::reverse_iterator DemoBinaryTree::rend()
{
  return reverse_iterator(begin());
}

void DemoBinaryTree::_destroyAllNodes()
{
  Node* n = _head;
  Node* next;

  while (n != nullptr)
  {
    next = n->successor;
    _destroyNode(n);
    n = next;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.