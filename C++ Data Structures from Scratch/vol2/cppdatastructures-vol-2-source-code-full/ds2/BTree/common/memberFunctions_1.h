#include "dss/predicates/predicates.h"

namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
BTree<Key, Mapped, KeyPred, Order>::BTree():
  _root(nullptr),
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  // ...
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline BTree<Key, Mapped, KeyPred, Order>::~BTree()
{
  _destroyTree(_root);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
bool BTree<Key, Mapped, KeyPred, Order>::empty() const
{
  return _size == 0;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::size_type
BTree<Key, Mapped, KeyPred, Order>::size() const
{
  return _size;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_reference
BTree<Key, Mapped, KeyPred, Order>::front() const
{
  return _head->frontElement();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_reference
BTree<Key, Mapped, KeyPred, Order>::back() const
{
  return _tail->backElement();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::key_compare
BTree<Key, Mapped, KeyPred, Order>::key_comp() const
{
  return _keyPred;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline const typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::root() const
{
  return _root;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline const typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::head() const
{
  return _head;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline const typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::tail() const
{
  return _tail;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::reference
BTree<Key, Mapped, KeyPred, Order>::front()
{
  return _head->frontElement();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::reference
BTree<Key, Mapped, KeyPred, Order>::back()
{
  return _tail->backElement();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::root()
{
  return _root;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::head()
{
  return _head;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::tail()
{
  return _tail;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::NewKeySearch
BTree<Key, Mapped, KeyPred, Order>::_findInsertionPointForNewKey(
  const key_type& newKey) const
{
  NewKeySearch search;

  Node* n = _root;
  Index i;

  while (true)
  {
    i = n->lowerBound(newKey);

    if (n->hasElement(i) &&
      dss::isReflexivelyEqual(n->key(i), newKey, _keyPred))
    {
      search.newKeyAlreadyExists = true;
      break;
    }
    else if (n->hasLeftChild(i))
    {
      n = n->leftChild(i);
    }
    else
    {
      search.newKeyAlreadyExists = false;
      break;
    }
  }

  search.node = n;
  search.index = i;

  return search;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_balanceOnInsert(Node* n)
{
  while (n != nullptr)
  {
    if (n->hasOverflow())
    {
      SplitNode s = _extractMiddleElementAndSplitNode(n);

      if (s.leftHalf == _tail)
        _tail = s.rightHalf;

      if (s.leftHalf != _root)
      {
        Node* parent = s.leftHalf->parent();
        Index i = parent->lowerBound(s.middleElement.first);

        parent->insertElement(i, s.middleElement);
        parent->insertChild(i + 1, s.rightHalf);

        s.rightHalf->setParent(parent);

        n = parent;
      }
      else
      {
        _root = _createNode();

        _root->pushBackElement(s.middleElement);
        _root->pushBackChild(s.leftHalf);
        _root->pushBackChild(s.rightHalf);

        s.leftHalf->setParent(_root);
        s.rightHalf->setParent(_root);

        break;
      }
    }
    else
    {
      break;
    }
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::SplitNode
BTree<Key, Mapped, KeyPred, Order>::_extractMiddleElementAndSplitNode(Node* n)
{
  SplitNode s;
  Index midpoint = static_cast<Index>(n->totalElements() / 2);

  s.middleElement = n->element(midpoint);
  s.leftHalf = n;
  s.rightHalf = _createNode();

  size_type halfTotalElements = midpoint;
  size_type halfTotalChildren = midpoint + 1;

  while (s.leftHalf->totalElements() != halfTotalElements)
  {
    s.rightHalf->pushFrontElement(s.leftHalf->backElement());
    s.leftHalf->popBackElement();
  }

  s.rightHalf->popFrontElement();

  while (s.leftHalf->totalChildren() > halfTotalChildren)
  {
    s.rightHalf->pushFrontChild(s.leftHalf->backChild());
    s.leftHalf->popBackChild();

    s.rightHalf->frontChild()->setParent(s.rightHalf);
  }

  return s;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::_createNode()
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node());

  return newNode;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTree<Key, Mapped, KeyPred, Order>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n, 1);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_destroyTree(Node* root)
{
  if (root != nullptr)
  {
    while (root->totalChildren() != 0)
    {
      _destroyTree(root->frontChild());
      root->popFrontChild();
    }

    _destroyNode(root);
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.