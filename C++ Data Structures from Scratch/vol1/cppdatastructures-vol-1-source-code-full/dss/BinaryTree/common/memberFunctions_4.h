#include "dss/bt/relatives.h"
#include "dss/inOrderIterative/inOrderIterative.h"
#include "dss/swap/swap.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
BinaryTree<Key, Mapped, Predicate>::BinaryTree(const BinaryTree& source)
{
  _root = _copyNode(source._root, nullptr);
  _head = bt::leftmostNode(_root);
  _tail = bt::rightmostNode(_root);
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
BinaryTree<Key, Mapped, Predicate>&
BinaryTree<Key, Mapped, Predicate>::operator=(const BinaryTree& rhs)
{
  clear();

  BinaryTree temp(rhs);

  swap(_root, temp._root);
  swap(_head, temp._head);
  swap(_tail, temp._tail);

  _size = temp._size;

  return *this;
}

template <class Key, class Mapped, class Predicate>
void BinaryTree<Key, Mapped, Predicate>::clear()
{
  _destroyAllNodes();

  _root = nullptr;
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

template <class Key, class Mapped, class Predicate>
typename BinaryTree<Key, Mapped, Predicate>::Node*
BinaryTree<Key, Mapped, Predicate>::_copyNode(Node* sourceNode, Node* newParent)
{
  if (sourceNode != nullptr)
  {
    Node* newNode = _createNode(sourceNode->element);

    newNode->parent = newParent;
    newNode->left = _copyNode(sourceNode->left, newNode);
    newNode->right = _copyNode(sourceNode->right, newNode);

    return newNode;
  }
  else
  {
    return nullptr;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.