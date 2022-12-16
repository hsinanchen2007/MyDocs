namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline BTree<Key, Mapped, KeyPred, Order>::Location::Location():
  node(nullptr),
  index(0)
{
  // ...
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline BTree<Key, Mapped, KeyPred, Order>::Location::Location(Node* node,
  Index index):
    node(node),
    index(index)
{
  // ...
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTree<Key, Mapped, KeyPred, Order>::Location::operator==(
  const Location& rhs) const
{
  return (node == rhs.node) && (index == rhs.index);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTree<Key, Mapped, KeyPred, Order>::Location::operator!=(
  const Location& rhs) const
{
  return (node != rhs.node) || (index != rhs.index);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.