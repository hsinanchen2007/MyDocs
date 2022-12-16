#include "dss/bt/detachLeafNode.h"
#include "dss/bt/detachOneChildNode.h"
#include "dss/bt/relatives.h"

#include "ds2/bt/relatives.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate>
typename RedBlackTree<Key, Mapped, Predicate>::iterator
RedBlackTree<Key, Mapped, Predicate>::erase(const_iterator erasurePoint)
{
  using namespace dss::bt;

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

  _balanceOnErase(trash);

  if (isLeaf(trash))
    detachLeafNode(trash, &_root);
  else
    detachOneChildNode(trash, &_root);

  _destroyNode(trash);
  --_size;

  return iterator(this, trashSuccessor);
}

template <class Key, class Mapped, class Predicate>
bool RedBlackTree<Key, Mapped, Predicate>::_is2Node(Node* n) const
{
  using namespace dss::bt;

  if (n == nullptr)
    return false;

  bool hasTwoNonNullBlackChildren = hasLeftChild(n) &&
    n->left->isBlack() &&
    hasRightChild(n) &&
    n->right->isBlack();

  return n->isBlack() && (isLeaf(n) || hasTwoNonNullBlackChildren);
}

template <class Key, class Mapped, class Predicate>
bool RedBlackTree<Key, Mapped, Predicate>::_isLeftLeaning3Node(Node* n) const
{
  return (n != nullptr && n->isBlack()) &&
    (n->left != nullptr && n->left->isRed()) &&
    (n->right == nullptr || n->right->isBlack());
}

template <class Key, class Mapped, class Predicate>
bool RedBlackTree<Key, Mapped, Predicate>::_isRightLeaning3Node(Node* n) const
{
  return (n != nullptr && n->isBlack()) &&
    (n->right != nullptr && n->right->isRed()) &&
    (n->left == nullptr || n->left->isBlack());
}

template <class Key, class Mapped, class Predicate>
bool RedBlackTree<Key, Mapped, Predicate>::_is4Node(Node* n) const
{
  using namespace dss::bt;

  if (n == nullptr)
    return false;

  bool hasTwoRedChildren = hasLeftChild(n) &&
    n->left->isRed() &&
    hasRightChild(n) &&
    n->right->isRed();

  return n->isBlack() && hasTwoRedChildren;
}

template <class Key, class Mapped, class Predicate>
inline bool RedBlackTree<Key, Mapped, Predicate>::_is4NodeOrLeftLeaning3Node(
  Node* n) const
{
  return _is4Node(n) || _isLeftLeaning3Node(n);
}

template <class Key, class Mapped, class Predicate>
inline bool RedBlackTree<Key, Mapped, Predicate>::_is4NodeOrRightLeaning3Node(
  Node* n) const
{
  return _is4Node(n) || _isRightLeaning3Node(n);
}

template <class Key, class Mapped, class Predicate>
inline void RedBlackTree<Key, Mapped, Predicate>::_balanceOnErase(Node* trash)
{
  bool is3Or4NodeCase = _balanceOn3Or4NodeErase(trash);

  if (!is3Or4NodeCase)
    _balanceOn2NodeErase(trash);
}

template <class Key, class Mapped, class Predicate>
bool RedBlackTree<Key, Mapped, Predicate>::_balanceOn3Or4NodeErase(Node* trash)
{
  using namespace dss::bt;

  if (trash->isRed())
    return true;

  if (hasLeftChild(trash) && trash->left->isRed())
  {
    trash->left->paintBlack();
    return true;
  }

  if (hasRightChild(trash) && trash->right->isRed())
  {
    trash->right->paintBlack();
    return true;
  }

  return false;
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_balanceOn2NodeErase(Node* trash)
{
  using namespace dss::bt;
  using namespace ds2::bt;

  Node* n = trash;

  while (true)
  {
    if (isRoot(n))
      return;

    if (isLeftChild(n) && _isRightLeaning3Node(n->parent))
      _convertToLeftLeaning3Node(n->parent);
    else if (isRightChild(n) && _isLeftLeaning3Node(n->parent))
      _convertToRightLeaning3Node(n->parent);

    if (n->parent->isBlack() && _is2Node(sibling(n)))
    {
      sibling(n)->paintRed();
      n = n->parent;
      continue;
    }

    if (n->parent->isRed() && _is2Node(sibling(n)))
    {
      n->parent->paintBlack();
      sibling(n)->paintRed();
      return;
    }

    if (isLeftChild(n) && _isLeftLeaning3Node(sibling(n)))
      _convertToRightLeaning3Node(sibling(n));
    else if (isRightChild(n) && _isRightLeaning3Node(sibling(n)))
      _convertToLeftLeaning3Node(sibling(n));

    if (isLeftChild(n) && _is4NodeOrRightLeaning3Node(sibling(n)))
    {
      _performBTreeLeftRotation(sibling(n));
      return;
    }
    else if (isRightChild(n) && _is4NodeOrLeftLeaning3Node(sibling(n)))
    {
      _performBTreeRightRotation(sibling(n));
      return;
    }
  }
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_convertToLeftLeaning3Node(
  Node* blackPortion)
{
  Node* redPortion = blackPortion->right;

  dss::bt::rotateLeft(redPortion, &_root);

  redPortion->paintBlack();
  blackPortion->paintRed();
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_convertToRightLeaning3Node(
  Node* blackPortion)
{
  Node* redPortion = blackPortion->left;

  dss::bt::rotateRight(redPortion, &_root);

  redPortion->paintBlack();
  blackPortion->paintRed();
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_performBTreeLeftRotation(
  Node* sibling)
{
  Node* originalParent = sibling->parent;
  Node* originalChild = sibling->right;

  dss::bt::rotateLeft(sibling, &_root);

  sibling->matchColor(*originalParent);
  originalParent->paintBlack();
  originalChild->paintBlack();
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_performBTreeRightRotation(
  Node* sibling)
{
  Node* originalParent = sibling->parent;
  Node* originalChild = sibling->left;

  dss::bt::rotateRight(sibling, &_root);

  sibling->matchColor(*originalParent);
  originalParent->paintBlack();
  originalChild->paintBlack();
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.