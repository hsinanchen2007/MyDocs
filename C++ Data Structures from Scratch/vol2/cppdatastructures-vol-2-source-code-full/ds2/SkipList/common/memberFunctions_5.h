#include <algorithm>

namespace ds2
{
template <class Key, class Mapped, class Predicate>
SkipList<Key, Mapped, Predicate>::SkipList(const SkipList& source):
  _head(source._head.size(), nullptr),
  _tail(nullptr),
  _size(source._size),
  _availableNodes(source._availableNodes)
{
  LinkVector rightLinks(_head.size());

  for (Level i = 0; i <= topLevel(); ++i)
    rightLinks[i] = &_head[i];

  for (Node* sourceNode = source._head[0];
    sourceNode != nullptr;
    sourceNode = sourceNode->right[0])
  {
    Node* newNode = _createNode(sourceNode->topLevel(), sourceNode->element);

    for (Level i = 0; i <= newNode->topLevel(); ++i)
    {
      *rightLinks[i] = newNode;
      rightLinks[i] = &newNode->right[i];
    }

    newNode->left = _tail;
    _tail = newNode;
  }
}

template <class Key, class Mapped, class Predicate>
SkipList<Key, Mapped, Predicate>& SkipList<Key, Mapped, Predicate>::operator=(
  const SkipList& rhs)
{
  using std::swap;

  clear();

  SkipList temp(rhs);

  _head.swap(temp._head);
  swap(_tail, temp._tail);
  swap(_size, temp._size);
  _availableNodes.swap(temp._availableNodes);

  return *this;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.