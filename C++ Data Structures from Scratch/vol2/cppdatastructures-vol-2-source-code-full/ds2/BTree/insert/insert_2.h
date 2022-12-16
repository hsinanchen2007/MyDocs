namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
std::pair<typename BTree<Key, Mapped, KeyPred, Order>::iterator, bool>
BTree<Key, Mapped, KeyPred, Order>::insert(const value_type& newElement)
{
  using std::make_pair;

  if (empty())
  {
    _root = _createNode();

    _root->pushBackElement(newElement);
    ++_size;

    _head = _root;
    _tail = _root;

    return make_pair(begin(), true);
  }

  NewKeySearch s = _findInsertionPointForNewKey(newElement.first);

  if (s.newKeyAlreadyExists)
    return make_pair(
      iterator(this, Location(s.node, s.index)),
      false);

  s.node->insertElement(s.index, newElement);
  ++_size;

  _balanceOnInsert(s.node);

  return make_pair(find(newElement.first), true);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.