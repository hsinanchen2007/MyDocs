#ifndef DS2_SKIPLIST_COMMON_SKIPLISTNODE
#define DS2_SKIPLIST_COMMON_SKIPLISTNODE

#include <cstddef>
#include <utility>
#include <vector>

namespace ds2
{
template <class Key, class Mapped>
struct SkipListNode
{
  typedef std::pair<const Key, Mapped> value_type;
  typedef SkipListNode Node;
  typedef std::vector<Node*> NodeVector;
  typedef std::size_t Level;

  SkipListNode(Level topLevel, const value_type& element);

  Level topLevel() const;

  void setTopLevel(Level newTopLevel);

  value_type element;
  Node* left;
  NodeVector right;
};

template <class Key, class Mapped>
inline SkipListNode<Key, Mapped>::SkipListNode(Level topLevel,
  const value_type& element):
    element(element),
    left(nullptr),
    right(topLevel + 1, nullptr)
{
  // ...
}

template <class Key, class Mapped>
inline typename SkipListNode<Key, Mapped>::Level
SkipListNode<Key, Mapped>::topLevel() const
{
  return right.size() - 1;
}

template <class Key, class Mapped>
inline void SkipListNode<Key, Mapped>::setTopLevel(Level newTopLevel)
{
  right.resize(newTopLevel + 1);
}
};

#endif // DS2_SKIPLIST_COMMON_SKIPLISTNODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.