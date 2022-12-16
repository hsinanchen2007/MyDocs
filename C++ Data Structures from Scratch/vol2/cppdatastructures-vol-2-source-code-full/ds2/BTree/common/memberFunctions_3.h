#include <algorithm>

#include "ds2/BTreeInOrderIterative/BTreeInOrderIterative.h"

namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::iterator
BTree<Key, Mapped, KeyPred, Order>::erase(const_iterator element)
{
  LeafElement trash = _getLeafElementForDeletion(element);

  trash.node->eraseElement(trash.index);

  _balanceOnErase(trash.node);

  --_size;

  if (_size == 0)
  {
    _destroyNode(_root);

    _root = nullptr;
    _head = nullptr;
    _tail = nullptr;
  }

  if (trash.hasSuccessor)
    return find(trash.successorKey);
  else
    return end();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::LeafElement
BTree<Key, Mapped, KeyPred, Order>::_getLeafElementForDeletion(
  const_iterator element)
{
  LeafElement trash;

  Location e = element._i._location;
  Location successor = bTreeInOrderSuccessor(e);

  if (e.node->isLeaf())
  {
    if (successor.node != nullptr)
    {
      trash.hasSuccessor = true;
      trash.successorKey = successor.node->key(successor.index);
    }
    else
    {
      trash.hasSuccessor = false;
    }

    trash.node = e.node;
    trash.index = e.index;
  }
  else
  {
    trash.hasSuccessor = true;
    trash.successorKey = successor.node->key(successor.index);

    Location predecessor = bTreeInOrderPredecessor(e);

    _swapElements(e, predecessor);

    trash.node = predecessor.node;
    trash.index = predecessor.index;
  }

  return trash;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTree<Key, Mapped, KeyPred, Order>::_swapElements(Location a,
  Location b)
{
  std::swap(a.node->kmPair(a.index), b.node->kmPair(b.index));
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_balanceOnErase(Node* n)
{
  while (!n->isRoot())
  {
    if (n->isAtLeastHalfFull())
      return;

    Node* leftSibling = n->leftSibling();
    Node* rightSibling = n->rightSibling();

    if (leftSibling != nullptr && leftSibling->isMoreThanHalfFull())
    {
      _rotateParentElementRight(n, leftSibling);
      return;
    }
    else if (rightSibling != nullptr && rightSibling->isMoreThanHalfFull())
    {
      _rotateParentElementLeft(n, rightSibling);
      return;
    }
    else if (n->parent()->isRoot() && _root->totalElements() == 1)
    {
      _mergeRootWithItsTwoChildren();
      return;
    }
    else if (leftSibling != nullptr)
    {
      n = _mergeWithLeftSibling(n, leftSibling);
      n = n->parent();
    }
    else
    {
      n = _mergeWithRightSibling(n, rightSibling);
      n = n->parent();
    }
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_rotateParentElementRight(Node* n,
  Node* leftSibling)
{
  Index parentElementIndex = n->parent()->lowerBound(n->key(0)) - 1;
  value_type parentElement = n->parent()->element(parentElementIndex);

  n->pushFrontElement(parentElement);
  n->parent()->overwriteElement(parentElementIndex, leftSibling->backElement());

  leftSibling->popBackElement();

  if (!leftSibling->isLeaf())
  {
    n->pushFrontChild(leftSibling->backChild());
    n->frontChild()->setParent(n);

    leftSibling->popBackChild();
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_rotateParentElementLeft(Node* n,
  Node* rightSibling)
{
  Index parentElementIndex = n->parent()->lowerBound(n->key(0));
  value_type parentElement = n->parent()->element(parentElementIndex);

  n->pushBackElement(parentElement);
  n->parent()->overwriteElement(parentElementIndex,
    rightSibling->frontElement());

  rightSibling->popFrontElement();

  if (!rightSibling->isLeaf())
  {
    n->pushBackChild(rightSibling->frontChild());
    n->backChild()->setParent(n);

    rightSibling->popFrontChild();
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
void BTree<Key, Mapped, KeyPred, Order>::_mergeRootWithItsTwoChildren()
{
  Node* leftChild = _root->frontChild();
  Node* rightChild = _root->backChild();
  Node* newRoot = _createNode();

  for (Index i = 0; i != leftChild->totalElements(); ++i)
    newRoot->pushBackElement(leftChild->element(i));

  for (Index i = 0; i != leftChild->totalChildren(); ++i)
    newRoot->pushBackChild(leftChild->child(i));

  newRoot->pushBackElement(_root->backElement());

  for (Index i = 0; i != rightChild->totalElements(); ++i)
    newRoot->pushBackElement(rightChild->element(i));

  for (Index i = 0; i != rightChild->totalChildren(); ++i)
    newRoot->pushBackChild(rightChild->child(i));

  for (Index i = 0; i != newRoot->totalChildren(); ++i)
    newRoot->child(i)->setParent(newRoot);

  if (leftChild == _head)
    _head = newRoot;

  if (rightChild == _tail)
    _tail = newRoot;

  _destroyNode(_root);
  _destroyNode(leftChild);
  _destroyNode(rightChild);

  _root = newRoot;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::_mergeWithLeftSibling(Node* n,
  Node* leftSibling)
{
  Index parentElementIndex = n->parent()->lowerBound(n->key(0)) - 1;
  Index nIndex = parentElementIndex + 1;

  value_type parentElement = n->parent()->element(parentElementIndex);

  leftSibling->pushBackElement(parentElement);

  for (Index i = 0; i != n->totalElements(); ++i)
    leftSibling->pushBackElement(n->element(i));

  if (!n->isLeaf())
  {
    for (Index i = 0; i != n->totalChildren(); ++i)
    {
      leftSibling->pushBackChild(n->child(i));
      leftSibling->backChild()->setParent(leftSibling);
    }
  }

  if (n == _tail)
    _tail = leftSibling;

  n->parent()->eraseElement(parentElementIndex);
  n->parent()->eraseChild(nIndex);

  _destroyNode(n);

  return leftSibling;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::Node*
BTree<Key, Mapped, KeyPred, Order>::_mergeWithRightSibling(Node* n,
  Node* rightSibling)
{
  Index parentElementIndex = n->parent()->lowerBound(n->key(0));
  Index nIndex = parentElementIndex;

  value_type parentElement = n->parent()->element(parentElementIndex);

  rightSibling->pushFrontElement(parentElement);

  while (n->totalElements() != 0)
  {
    rightSibling->pushFrontElement(n->backElement());
    n->popBackElement();
  }

  if (!n->isLeaf())
  {
    while (n->totalChildren() != 0)
    {
      rightSibling->pushFrontChild(n->backChild());
      rightSibling->frontChild()->setParent(rightSibling);

      n->popBackChild();
    }
  }

  if (n == _head)
    _head = rightSibling;

  n->parent()->eraseElement(parentElementIndex);
  n->parent()->eraseChild(nIndex);

  _destroyNode(n);

  return rightSibling;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.