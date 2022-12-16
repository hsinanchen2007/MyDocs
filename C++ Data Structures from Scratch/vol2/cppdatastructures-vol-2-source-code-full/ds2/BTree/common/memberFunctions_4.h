#include <algorithm>

namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
BTree<Key, Mapped, KeyPred, Order>::BTree(const BTree& source):
  _root(nullptr),
  _size(0)
{
  _root = _copyNode(source._root, nullptr);
  _head = _root;
  _tail = _root;
  _size = source._size;

  if (_size != 0)
  {
    while (!_head->isLeaf())
      _head = _head->frontChild();

    while (!_tail->isLeaf())
      _tail = _tail->backChild();
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
BTree<Key, Mapped, KeyPred, Order>&
BTree<Key, Mapped, KeyPred, Order>::operator=(const BTree& rhs)
{
  using std::swap;

  clear();

  BTree temp(rhs);

  swap(_root, temp._root);
  swap(_head, temp._head);
  swap(_tail, temp._tail);
  swap(_size, temp._size);

  return *this;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::clear()
{
  _destroyTree(_root);

  _root = nullptr;
  _head = nullptr;
  _tail = nullptr;

  _size = 0;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::_copyNode(Node* sourceNode, Node* newParent)
{
  if (sourceNode != nullptr)
  {
    Node* newNode = _createNode();

    for (Index i = 0; i != sourceNode->totalElements(); ++i)
      newNode->pushBackElement(sourceNode->element(i));

    newNode->setParent(newParent);

    for (Index i = 0; i != sourceNode->totalChildren(); ++i)
      newNode->pushBackChild(
        _copyNode(sourceNode->child(i), newNode));

    return newNode;
  }
  else
  {
    return nullptr;
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.