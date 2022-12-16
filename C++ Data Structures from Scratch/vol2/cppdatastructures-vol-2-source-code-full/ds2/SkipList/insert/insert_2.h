namespace ds2
{
template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::insert(const value_type& newElement)
{
  if (size() == capacity())
    increaseTopLevel(topLevel() + 1);

  LinkVector rightLinks;
  NodeVector rightNeighbors;

  NewKeySearch s = _findInsertionPointForNewKey(newElement.first,
    rightLinks,
    rightNeighbors);

  if (s.newKeyAlreadyExists)
    return;

  Node* newNode = _createNode(_getLevelForNewNode(), newElement);

  _attachNewNode(newNode, rightLinks, rightNeighbors);
  ++_size;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.