#include "dss/bt/attachNewNode.h"
#include "dss/bt/findInsertionPoint.h"
#include "dss/bt/key.h"
#include "dss/predicates/predicates.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
Pair<typename BinaryTree<Key, Mapped, Predicate>::iterator, bool>
BinaryTree<Key, Mapped, Predicate>::insert(const value_type& sourceElement)
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

      return makePair(iterator(this, newNode), true);
    }
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.