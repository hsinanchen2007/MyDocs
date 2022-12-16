#include "dss/bt/findNode.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
BinaryTree<Key, Mapped, Predicate>::BinaryTree():
  _root(nullptr),
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  // ...
}

template <class Key, class Mapped, class Predicate>
inline BinaryTree<Key, Mapped, Predicate>::~BinaryTree()
{
  _destroyAllNodes();
}

template <class Key, class Mapped, class Predicate>
inline bool BinaryTree<Key, Mapped, Predicate>::empty() const
{
  return _size == 0;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::size_type
BinaryTree<Key, Mapped, Predicate>::size() const
{
  return _size;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_iterator
BinaryTree<Key, Mapped, Predicate>::begin() const
{
  return const_cast<BinaryTree*>(this)->begin();
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_iterator
BinaryTree<Key, Mapped, Predicate>::end() const
{
  return const_cast<BinaryTree*>(this)->end();
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_reverse_iterator
BinaryTree<Key, Mapped, Predicate>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_reverse_iterator
BinaryTree<Key, Mapped, Predicate>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_reference
BinaryTree<Key, Mapped, Predicate>::front() const
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_reference
BinaryTree<Key, Mapped, Predicate>::back() const
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::const_iterator
BinaryTree<Key, Mapped, Predicate>::find(const key_type& searchKey) const
{
  return const_cast<BinaryTree*>(this)->find(searchKey);
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::key_compare
BinaryTree<Key, Mapped, Predicate>::key_comp() const
{
  return _predicate;
}

template <class Key, class Mapped, class Predicate>
inline const typename BinaryTree<Key, Mapped, Predicate>::Node*
BinaryTree<Key, Mapped, Predicate>::root() const
{
  return _root;
}

template <class Key, class Mapped, class Predicate>
inline const typename BinaryTree<Key, Mapped, Predicate>::Node*
BinaryTree<Key, Mapped, Predicate>::head() const
{
  return _head;
}

template <class Key, class Mapped, class Predicate>
inline const typename BinaryTree<Key, Mapped, Predicate>::Node*
BinaryTree<Key, Mapped, Predicate>::tail() const
{
  return _tail;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::iterator
BinaryTree<Key, Mapped, Predicate>::begin()
{
  return iterator(this, _head);
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::iterator
BinaryTree<Key, Mapped, Predicate>::end()
{
  return iterator(this, nullptr);
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::reverse_iterator
BinaryTree<Key, Mapped, Predicate>::rbegin()
{
  return reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::reverse_iterator
BinaryTree<Key, Mapped, Predicate>::rend()
{
  return reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::reference
BinaryTree<Key, Mapped, Predicate>::front()
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::reference
BinaryTree<Key, Mapped, Predicate>::back()
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
inline typename BinaryTree<Key, Mapped, Predicate>::iterator
BinaryTree<Key, Mapped, Predicate>::find(const key_type& searchKey)
{
  return iterator(this, bt::findNode(_root, searchKey, _predicate));
}

template <class Key, class Mapped, class Predicate>
typename BinaryTree<Key, Mapped, Predicate>::Node*
BinaryTree<Key, Mapped, Predicate>::_createNode(const value_type& sourceElement)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(sourceElement));

  return newNode;
}

template <class Key, class Mapped, class Predicate>
inline void BinaryTree<Key, Mapped, Predicate>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n);
}

template <class Key, class Mapped, class Predicate>
void BinaryTree<Key, Mapped, Predicate>::_destroyAllNodes()
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