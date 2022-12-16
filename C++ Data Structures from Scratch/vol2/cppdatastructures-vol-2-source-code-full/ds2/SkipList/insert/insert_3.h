namespace ds2
{
template <class Key, class Mapped, class Predicate>
std::pair<typename SkipList<Key, Mapped, Predicate>::iterator, bool>
SkipList<Key, Mapped, Predicate>::insert(const value_type& newElement)
{
  using std::make_pair;

  if (size() == capacity())
    increaseTopLevel(topLevel() + 1);

  LinkVector rightLinks;
  NodeVector rightNeighbors;

  NewKeySearch s = _findInsertionPointForNewKey(newElement.first,
    rightLinks,
    rightNeighbors);

  if (s.newKeyAlreadyExists)
    return make_pair(iterator(this, s.node), false);

  Node* newNode = _createNode(_getLevelForNewNode(), newElement);

  _attachNewNode(newNode, rightLinks, rightNeighbors);
  ++_size;

  return make_pair(iterator(this, newNode), true);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.