namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::insert(const value_type& newElement)
{
  if (empty())
  {
    _root = _createNode();

    _root->pushBackElement(newElement);
    ++_size;

    _head = _root;
    _tail = _root;

    return;
  }

  NewKeySearch s = _findInsertionPointForNewKey(newElement.first);

  if (s.newKeyAlreadyExists)
    return;

  s.node->insertElement(s.index, newElement);
  ++_size;

  _balanceOnInsert(s.node);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.