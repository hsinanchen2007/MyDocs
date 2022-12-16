#include "dss/bt/findNode.h"
#include "dss/bt/relatives.h"
#include "dss/inOrderIterative/inOrderIterative.h"
#include "dss/swap/swap.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
AvlTree<Key, Mapped, Predicate>::AvlTree():
  _root(nullptr),
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  // ...
}

template <class Key, class Mapped, class Predicate>
AvlTree<Key, Mapped, Predicate>::AvlTree(const AvlTree& source)
{
  _root = _copyNode(source._root, nullptr);
  _head = bt::leftmostNode(_root);
  _tail = bt::rightmostNode(_root);
  _size = source._size;

  Node* currentNode = _head;
  Node* previousNode = nullptr;

  while (currentNode != nullptr)
  {
    currentNode->predecessor = previousNode;
    currentNode->successor = inOrderSuccessor(currentNode);

    previousNode = currentNode;
    currentNode = currentNode->successor;
  }
}

template <class Key, class Mapped, class Predicate>
inline AvlTree<Key, Mapped, Predicate>::~AvlTree()
{
  _destroyAllNodes();
}

template <class Key, class Mapped, class Predicate>
inline bool AvlTree<Key, Mapped, Predicate>::empty() const
{
  return _size == 0;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::size_type
AvlTree<Key, Mapped, Predicate>::size() const
{
  return _size;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_iterator
AvlTree<Key, Mapped, Predicate>::begin() const
{
  return const_cast<AvlTree*>(this)->begin();
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_iterator
AvlTree<Key, Mapped, Predicate>::end() const
{
  return const_cast<AvlTree*>(this)->end();
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_reverse_iterator
AvlTree<Key, Mapped, Predicate>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_reverse_iterator
AvlTree<Key, Mapped, Predicate>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_reference
AvlTree<Key, Mapped, Predicate>::front() const
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_reference
AvlTree<Key, Mapped, Predicate>::back() const
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::const_iterator
AvlTree<Key, Mapped, Predicate>::find(const key_type& searchKey) const
{
  return const_cast<AvlTree*>(this)->find(searchKey);
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::key_compare
AvlTree<Key, Mapped, Predicate>::key_comp() const
{
  return _predicate;
}

template <class Key, class Mapped, class Predicate>
inline const typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::root() const
{
  return _root;
}

template <class Key, class Mapped, class Predicate>
inline const typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::head() const
{
  return _head;
}

template <class Key, class Mapped, class Predicate>
inline const typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::tail() const
{
  return _tail;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::iterator
AvlTree<Key, Mapped, Predicate>::begin()
{
  return iterator(this, _head);
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::iterator
AvlTree<Key, Mapped, Predicate>::end()
{
  return iterator(this, nullptr);
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::reverse_iterator
AvlTree<Key, Mapped, Predicate>::rbegin()
{
  return reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::reverse_iterator
AvlTree<Key, Mapped, Predicate>::rend()
{
  return reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::reference
AvlTree<Key, Mapped, Predicate>::front()
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::reference
AvlTree<Key, Mapped, Predicate>::back()
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
AvlTree<Key, Mapped, Predicate>&
AvlTree<Key, Mapped, Predicate>::operator=(const AvlTree& rhs)
{
  clear();

  AvlTree temp(rhs);

  swap(_root, temp._root);
  swap(_head, temp._head);
  swap(_tail, temp._tail);

  _size = temp._size;

  return *this;
}

template <class Key, class Mapped, class Predicate>
inline typename AvlTree<Key, Mapped, Predicate>::iterator
AvlTree<Key, Mapped, Predicate>::find(const key_type& searchKey)
{
  return iterator(this, bt::findNode(_root, searchKey, _predicate));
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::clear()
{
  _destroyAllNodes();

  _root = nullptr;
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

template <class Key, class Mapped, class Predicate>
typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::_createNode(const value_type& sourceElement)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(sourceElement));

  return newNode;
}

template <class Key, class Mapped, class Predicate>
inline void AvlTree<Key, Mapped, Predicate>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n);
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_destroyAllNodes()
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