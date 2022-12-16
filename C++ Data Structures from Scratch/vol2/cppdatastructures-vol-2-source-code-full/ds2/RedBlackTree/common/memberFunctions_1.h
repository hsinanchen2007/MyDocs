#include <algorithm>

#include "dss/bt/findNode.h"
#include "dss/bt/relatives.h"
#include "dss/inOrderIterative/inOrderIterative.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate>
RedBlackTree<Key, Mapped, Predicate>::RedBlackTree():
  _root(nullptr),
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  // ...
}

template <class Key, class Mapped, class Predicate>
RedBlackTree<Key, Mapped, Predicate>::RedBlackTree(const RedBlackTree& source)
{
  using namespace dss;
  using namespace dss::bt;

  _root = _copyNode(source._root, nullptr);
  _head = leftmostNode(_root);
  _tail = rightmostNode(_root);
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
inline RedBlackTree<Key, Mapped, Predicate>::~RedBlackTree()
{
  _destroyAllNodes();
}

template <class Key, class Mapped, class Predicate>
inline bool RedBlackTree<Key, Mapped, Predicate>::empty() const
{
  return _size == 0;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::size_type
RedBlackTree<Key, Mapped, Predicate>::size() const
{
  return _size;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_iterator
RedBlackTree<Key, Mapped, Predicate>::begin() const
{
  return const_cast<RedBlackTree*>(this)->begin();
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_iterator
RedBlackTree<Key, Mapped, Predicate>::end() const
{
  return const_cast<RedBlackTree*>(this)->end();
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_reverse_iterator
RedBlackTree<Key, Mapped, Predicate>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_reverse_iterator
RedBlackTree<Key, Mapped, Predicate>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_reference
RedBlackTree<Key, Mapped, Predicate>::front() const
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_reference
RedBlackTree<Key, Mapped, Predicate>::back() const
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::const_iterator
RedBlackTree<Key, Mapped, Predicate>::find(const key_type& searchKey) const
{
  return const_cast<RedBlackTree*>(this)->find(searchKey);
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::key_compare
RedBlackTree<Key, Mapped, Predicate>::key_comp() const
{
  return _predicate;
}

template <class Key, class Mapped, class Predicate>
inline const typename RedBlackTree<Key, Mapped, Predicate>::Node*
RedBlackTree<Key, Mapped, Predicate>::root() const
{
  return _root;
}

template <class Key, class Mapped, class Predicate>
inline const typename RedBlackTree<Key, Mapped, Predicate>::Node*
RedBlackTree<Key, Mapped, Predicate>::head() const
{
  return _head;
}

template <class Key, class Mapped, class Predicate>
inline const typename RedBlackTree<Key, Mapped, Predicate>::Node*
RedBlackTree<Key, Mapped, Predicate>::tail() const
{
  return _tail;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::iterator
RedBlackTree<Key, Mapped, Predicate>::begin()
{
  return iterator(this, _head);
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::iterator
RedBlackTree<Key, Mapped, Predicate>::end()
{
  return iterator(this, nullptr);
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::reverse_iterator
RedBlackTree<Key, Mapped, Predicate>::rbegin()
{
  return reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::reverse_iterator
RedBlackTree<Key, Mapped, Predicate>::rend()
{
  return reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::reference
RedBlackTree<Key, Mapped, Predicate>::front()
{
  return _head->element;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::reference
RedBlackTree<Key, Mapped, Predicate>::back()
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
RedBlackTree<Key, Mapped, Predicate>&
RedBlackTree<Key, Mapped, Predicate>::operator=(const RedBlackTree& rhs)
{
  using std::swap;

  clear();

  RedBlackTree temp(rhs);

  swap(_root, temp._root);
  swap(_head, temp._head);
  swap(_tail, temp._tail);

  _size = temp._size;

  return *this;
}

template <class Key, class Mapped, class Predicate>
inline typename RedBlackTree<Key, Mapped, Predicate>::iterator
RedBlackTree<Key, Mapped, Predicate>::find(const key_type& searchKey)
{
  return iterator(this, dss::bt::findNode(_root, searchKey, _predicate));
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::clear()
{
  _destroyAllNodes();

  _root = nullptr;
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

template <class Key, class Mapped, class Predicate>
typename RedBlackTree<Key, Mapped, Predicate>::Node*
RedBlackTree<Key, Mapped, Predicate>::_createNode(
  const value_type& sourceElement)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(sourceElement));

  return newNode;
}

template <class Key, class Mapped, class Predicate>
inline void RedBlackTree<Key, Mapped, Predicate>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n, 1);
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_destroyAllNodes()
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

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.