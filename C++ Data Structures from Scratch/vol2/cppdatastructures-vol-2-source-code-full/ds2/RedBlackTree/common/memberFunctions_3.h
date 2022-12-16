#include "dss/bt/attachNewNode.h"
#include "dss/bt/findInsertionPoint.h"
#include "dss/bt/key.h"
#include "dss/bt/relatives.h"
#include "dss/bt/rotate.h"
#include "dss/predicates/predicates.h"

#include "ds2/bt/relatives.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate>
std::pair<typename RedBlackTree<Key, Mapped, Predicate>::iterator, bool>
RedBlackTree<Key, Mapped, Predicate>::insert(const value_type& newElement)
{
  using namespace dss::bt;

  Node* newNode;

  if (empty())
  {
    newNode = _createNode(newElement);

    _root = newNode;
    _head = newNode;
    _tail = newNode;
  }
  else
  {
    Node* insertionPoint = findInsertionPoint(_root,
      key(newElement),
      _predicate);

    if (dss::isReflexivelyEqual(key(insertionPoint),
      key(newElement),
      _predicate))
    {
      return make_pair(iterator(this, insertionPoint), false);
    }
    else
    {
      newNode = _createNode(newElement);

      attachNewNode(newNode, insertionPoint, _predicate);

      if (newNode == _head->left)
        _head = newNode;
      else if (newNode == _tail->right)
        _tail = newNode;
    }
  }

  ++_size;
  _balanceOnInsert(newNode);

  return make_pair(iterator(this, newNode), true);
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_balanceOnInsert(Node* n)
{
  using namespace dss::bt;
  using namespace ds2::bt;

  while (true)
  {
    if (isRoot(n))
    {
      n->paintBlack();
      return;
    }
    else if (n->parent->isBlack())
    {
      return;
    }
    else if (hasUncle(n) && uncle(n)->isRed())
    {
      grandparent(n)->paintRed();
      n->parent->paintBlack();
      uncle(n)->paintBlack();

      n = grandparent(n);
    }
    else
    {
      if (isLeftChild(n->parent) && isLeftChild(n))
        _fixLeftLeft(n);
      else if (isLeftChild(n->parent) && isRightChild(n))
        _fixLeftRight(n);
      else if (isRightChild(n->parent) && isRightChild(n))
        _fixRightRight(n);
      else
        _fixRightLeft(n);

      return;
    }
  }
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_fixLeftLeft(Node* n)
{
  using namespace dss::bt;
  using namespace ds2::bt;

  Node* p = n->parent;
  Node* g = grandparent(n);

  rotateRight(p, &_root);

  p->paintBlack();
  g->paintRed();
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_fixLeftRight(Node* n)
{
  using namespace dss::bt;

  Node* p = n->parent;

  rotateLeft(n, &_root);
  _fixLeftLeft(p);
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_fixRightRight(Node* n)
{
  using namespace dss::bt;
  using namespace ds2::bt;

  Node* p = n->parent;
  Node* g = grandparent(n);

  rotateLeft(p, &_root);

  p->paintBlack();
  g->paintRed();
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_fixRightLeft(Node* n)
{
  using namespace dss::bt;

  Node* p = n->parent;

  rotateRight(n, &_root);
  _fixRightRight(p);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.