#include "dss/bt/detachLeafNode.h"
#include "dss/bt/detachOneChildNode.h"
#include "dss/bt/relatives.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
typename AvlTree<Key, Mapped, Predicate>::iterator
AvlTree<Key, Mapped, Predicate>::erase(const_iterator erasurePoint)
{
  using namespace bt;

  Node* trash = erasurePoint._i._node;
  Node* trashSuccessor = trash->successor;

  if (hasLeftChild(trash) && hasRightChild(trash))
  {
    _overwriteElement(trash, trash->predecessor->element);
    trash = trash->predecessor;
  }

  if (trash == _head)
    _head = _head->successor;

  if (trash == _tail)
    _tail = _tail->predecessor;

  Node* trashParent = trash->parent;
  bool leftSubtreeWasPruned = isLeftChild(trash);

  if (isLeaf(trash))
    detachLeafNode(trash, &_root);
  else
    detachOneChildNode(trash, &_root);

  _destroyNode(trash);
  --_size;

  _balanceOnErasure(trashParent, leftSubtreeWasPruned);

  return iterator(this, trashSuccessor);
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_balanceOnErasure(Node* trashParent,
  bool leftSubtreeWasPruned)
{
  for (Node* p = trashParent; p != nullptr; p = p->parent)
  {
    if (leftSubtreeWasPruned)
      p = _balanceOnLeftPruning(p);
    else
      p = _balanceOnRightPruning(p);

    if (p->balanceFactor == -1 || p->balanceFactor == 1)
      return;
    else
      leftSubtreeWasPruned = bt::isLeftChild(p);
  }
}

template <class Key, class Mapped, class Predicate>
typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::_balanceOnLeftPruning(Node* p)
{
  ++p->balanceFactor;

  if (p->balanceFactor == 2)
  {
    if (p->right->balanceFactor == 1)
      _fixRightRight(p);
    else if (p->right->balanceFactor == -1)
      _fixRightLeft(p);
    else
      _fixRightZero(p);

    return p->parent;
  }
  else
  {
    return p;
  }
}

template <class Key, class Mapped, class Predicate>
typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::_balanceOnRightPruning(Node* p)
{
  --p->balanceFactor;

  if (p->balanceFactor == -2)
  {
    if (p->left->balanceFactor == -1)
      _fixLeftLeft(p);
    else if (p->left->balanceFactor == 1)
      _fixLeftRight(p);
    else
      _fixLeftZero(p);

    return p->parent;
  }
  else
  {
    return p;
  }
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixLeftZero(Node* n)
{
  Node* n7 = n;
  Node* n5 = n->left;

  bt::rotateRight(n5, &_root);

  n5->balanceFactor = 1;
  n7->balanceFactor = -1;
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_fixRightZero(Node* n)
{
  Node* n3 = n;
  Node* n5 = n->right;

  bt::rotateLeft(n5, &_root);

  n3->balanceFactor = 1;
  n5->balanceFactor = -1;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.