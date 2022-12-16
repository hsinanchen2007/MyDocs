#include "dss/bt/detachLeafNode.h"
#include "dss/bt/detachOneChildNode.h"
#include "dss/bt/relatives.h"

namespace dss
{
template <class Key, class Mapped, class Predicate>
typename BinaryTree<Key, Mapped, Predicate>::iterator
BinaryTree<Key, Mapped, Predicate>::erase(const_iterator erasurePoint)
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

  if (isLeaf(trash))
    detachLeafNode(trash, &_root);
  else
    detachOneChildNode(trash, &_root);

  _destroyNode(trash);
  --_size;

  return iterator(this, trashSuccessor);
}

template <class Key, class Mapped, class Predicate>
void BinaryTree<Key, Mapped, Predicate>::_overwriteElement(Node* n,
  const value_type& sourceElement)
{
  Node temp(sourceElement);

  temp.parent = n->parent;
  temp.left = n->left;
  temp.right = n->right;
  temp.predecessor = n->predecessor;
  temp.successor = n->successor;

  _alloc.destroy(n);
  _alloc.construct(n, temp);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.