#include <cmath>
#include <cstdlib>
#include <ctime>

#include "dss/predicates/predicates.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate>
inline SkipList<Key, Mapped, Predicate>::SkipList():
  _head(_initialTopLevel + 1),
  _tail(nullptr),
  _size(0)
{
  _initAvailableNodeCount();
}

template <class Key, class Mapped, class Predicate>
inline SkipList<Key, Mapped, Predicate>::~SkipList()
{
  _destroyAllNodes();
}

template <class Key, class Mapped, class Predicate>
inline bool SkipList<Key, Mapped, Predicate>::empty() const
{
  return _size == 0;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::size_type
SkipList<Key, Mapped, Predicate>::size() const
{
  return _size;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::size_type
SkipList<Key, Mapped, Predicate>::capacity() const
{
  return static_cast<size_type>(std::pow(2, topLevel() + 1)) - 1;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_reference
SkipList<Key, Mapped, Predicate>::front() const
{
  return _head[0]->element;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_reference
SkipList<Key, Mapped, Predicate>::back() const
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::key_compare
SkipList<Key, Mapped, Predicate>::key_comp() const
{
  return _predicate;
}

template <class Key, class Mapped, class Predicate>
inline const typename SkipList<Key, Mapped, Predicate>::NodeVector&
SkipList<Key, Mapped, Predicate>::head() const
{
  return _head;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::Level
SkipList<Key, Mapped, Predicate>::topLevel() const
{
  return _head.size() - 1;
}

template <class Key, class Mapped, class Predicate>
inline const typename SkipList<Key, Mapped, Predicate>::CountVector&
SkipList<Key, Mapped, Predicate>::availableNodes() const
{
  return _availableNodes;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::reference
SkipList<Key, Mapped, Predicate>::front()
{
  return _head[0]->element;
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::reference
SkipList<Key, Mapped, Predicate>::back()
{
  return _tail->element;
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::clear()
{
  _destroyAllNodes();

  for (Level i = 0; i <= topLevel(); ++i)
    _head[i] = nullptr;

  _tail = nullptr;
  _size = 0;
  _initAvailableNodeCount();
}

template <class Key, class Mapped, class Predicate>
inline SkipList<Key, Mapped, Predicate>::NewKeySearch::NewKeySearch(
  bool newKeyAlreadyExists,
  Node* node):
    newKeyAlreadyExists(newKeyAlreadyExists),
    node(node)
{
  // ...
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::_initAvailableNodeCount()
{
  _availableNodes.resize(_head.size());

  for (Level i = 0; i <= topLevel(); ++i)
    _availableNodes[i] = static_cast<size_type>(
      std::pow(2, topLevel() - i));
}

template <class Key, class Mapped, class Predicate>
typename SkipList<Key, Mapped, Predicate>::Level
SkipList<Key, Mapped, Predicate>::_getLevelForNewNode()
{
  using namespace std;

  Level randomLevel;

  srand(static_cast<size_t>(time(nullptr)));

  while (true)
  {
    randomLevel = rand() % _availableNodes.size();

    if (_availableNodes[randomLevel] >= 1)
    {
      --_availableNodes[randomLevel];
      break;
    }
  }

  return randomLevel;
}

template <class Key, class Mapped, class Predicate>
typename SkipList<Key, Mapped, Predicate>::NewKeySearch
SkipList<Key, Mapped, Predicate>::_findInsertionPointForNewKey(
  const key_type& newKey,
  LinkVector& rightLinks,
  NodeVector& rightNeighbors)
{
  rightLinks.resize(_head.size());
  rightNeighbors.resize(_head.size());

  SignedLevel currentLevel = topLevel();
  Node* n = _head[currentLevel];
  NodeVector* v = &_head;

  while (true)
  {
    if (n != nullptr &&
      dss::isReflexivelyEqual(n->element.first, newKey, _predicate))
        return NewKeySearch(true, n);

    if (n != nullptr && _predicate(n->element.first, newKey))
    {
      v = &n->right;
      n = n->right[currentLevel];

      continue;
    }

    rightLinks[currentLevel] = &(*v)[currentLevel];
    rightNeighbors[currentLevel] = n;

    --currentLevel;

    if (currentLevel < 0)
      break;

    n = (*v)[currentLevel];
  }

  return NewKeySearch(false, nullptr);
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::_attachNewNode(Node* newNode,
  const LinkVector& rightLinks,
  const NodeVector& rightNeighbors)
{
  if (rightNeighbors[0] != nullptr)
  {
    newNode->left = rightNeighbors[0]->left;
    rightNeighbors[0]->left = newNode;
  }
  else
  {
    newNode->left = _tail;
    _tail = newNode;
  }

  for (Level i = 0; i <= newNode->topLevel(); ++i)
  {
    *rightLinks[i] = newNode;
    newNode->right[i] = rightNeighbors[i];
  }
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::Node*
SkipList<Key, Mapped, Predicate>::_createNode(Level topLevel,
  const value_type& element)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(topLevel, element));

  return newNode;
}

template <class Key, class Mapped, class Predicate>
inline void SkipList<Key, Mapped, Predicate>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n, 1);
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::_destroyAllNodes()
{
  Node* current = _head[0];

  while (current != nullptr)
  {
    Node* next = current->right[0];
    _destroyNode(current);
    current = next;
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.