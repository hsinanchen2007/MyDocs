#include "dss/bt/attachNewNode.h"
#include "dss/bt/findInsertionPoint.h"
#include "dss/bt/key.h"
#include "dss/bt/relatives.h"
#include "dss/bt/rotate.h"
#include "dss/predicates/predicates.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
Pair<typename AvlTree<Key, Mapped, Predicate>::iterator, bool>
AvlTree<Key, Mapped, Predicate>::insert(const value_type& sourceElement)
{
  using bt::key;

  if (empty())
  {
    _root = _createNode(sourceElement);
    _head = _root;
    _tail = _root;

    ++_size;

    return makePair(iterator(this, _root), true);
  }
  else
  {
    Node* insertionPoint = bt::findInsertionPoint(_root,
      key(sourceElement),
      _predicate);

    if (isReflexivelyEqual(key(insertionPoint),
      key(sourceElement),
      _predicate))
    {
      return makePair(iterator(this, insertionPoint), false);
    }
    else
    {
      Node* newNode = _createNode(sourceElement);

      bt::attachNewNode(newNode, insertionPoint, _predicate);

      if (newNode == _head->left)
        _head = newNode;
      else if (newNode == _tail->right)
        _tail = newNode;

      ++_size;

      _balanceOnInsertion(newNode);

      return makePair(iterator(this, newNode), true);
    }
  }
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_balanceOnInsertion(Node* newNode)
{
  for (Node* n = newNode; n != _root; n = n->parent)
  {
    Node* p = n->parent;

    if (bt::isLeftChild(n))
      --p->balanceFactor;
    else
      ++p->balanceFactor;

    if (p->balanceFactor == 0)
    {
      return;
    }
    else if (p->balanceFactor == -2)
    {
      if (n->balanceFactor == -1)
        _fixLeftLeft(p);
      else
        _fixLeftRight(p);

      return;
    }
    else if (p->balanceFactor == 2)
    {
      if (n->balanceFactor == 1)
        _fixRightRight(p);
      else
        _fixRightLeft(p);

      return;
    }
  }
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixLeftLeft(Node* n)
{
  Node* n7 = n;
  Node* n5 = n->left;

  bt::rotateRight(n5, &_root);

  n5->balanceFactor = 0;
  n7->balanceFactor = 0;
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixLeftRight(Node* n)
{
  Node* n7 = n;
  Node* n3 = n->left;
  Node* n5 = n->left->right;

  bt::rotateLeft(n5, &_root);
  bt::rotateRight(n5, &_root);

  if (n5->balanceFactor == 0)
  {
    n3->balanceFactor = 0;
    n7->balanceFactor = 0;
  }
  else if (n5->balanceFactor == -1)
  {
    n3->balanceFactor = 0;
    n5->balanceFactor = 0;
    n7->balanceFactor = 1;
  }
  else
  {
    n3->balanceFactor = -1;
    n5->balanceFactor = 0;
    n7->balanceFactor = 0;
  }
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixRightRight(Node* n)
{
  Node* n3 = n;
  Node* n5 = n->right;

  bt::rotateLeft(n5, &_root);

  n3->balanceFactor = 0;
  n5->balanceFactor = 0;
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixRightLeft(Node* n)
{
  Node* n3 = n;
  Node* n7 = n->right;
  Node* n5 = n->right->left;

  bt::rotateRight(n5, &_root);
  bt::rotateLeft(n5, &_root);

  if (n5->balanceFactor == 0)
  {
    n3->balanceFactor = 0;
    n7->balanceFactor = 0;
  }
  else if (n5->balanceFactor == -1)
  {
    n3->balanceFactor = 0;
    n5->balanceFactor = 0;
    n7->balanceFactor = 1;
  }
  else
  {
    n3->balanceFactor = -1;
    n5->balanceFactor = 0;
    n7->balanceFactor = 0;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.