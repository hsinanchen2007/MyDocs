#ifndef DS2_REDBLACKTREE_COMMON_REDBLACKTREENODE
#define DS2_REDBLACKTREE_COMMON_REDBLACKTREENODE

#include <utility>

namespace ds2
{
template <class Key, class Mapped>
class RedBlackTreeNode
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef RedBlackTreeNode Node;

  RedBlackTreeNode(const value_type& sourceElement);

  bool isRed() const;
  bool isBlack() const;

  void paintRed();
  void paintBlack();
  void matchColor(const Node& n);

  value_type element;

  Node* parent;
  Node* left;
  Node* right;

  Node* predecessor;
  Node* successor;

 private:
  bool _isRed;
};

template <class Key, class Mapped>
RedBlackTreeNode<Key, Mapped>::RedBlackTreeNode(
  const value_type& sourceElement):
    element(sourceElement),
    parent(nullptr),
    left(nullptr),
    right(nullptr),
    predecessor(nullptr),
    successor(nullptr),
    _isRed(true)
{
  // ...
}

template <class Key, class Mapped>
inline bool RedBlackTreeNode<Key, Mapped>::isRed() const
{
  return _isRed;
}

template <class Key, class Mapped>
inline bool RedBlackTreeNode<Key, Mapped>::isBlack() const
{
  return !_isRed;
}

template <class Key, class Mapped>
inline void RedBlackTreeNode<Key, Mapped>::paintRed()
{
  _isRed = true;
}

template <class Key, class Mapped>
inline void RedBlackTreeNode<Key, Mapped>::paintBlack()
{
  _isRed = false;
}

template <class Key, class Mapped>
inline void RedBlackTreeNode<Key, Mapped>::matchColor(const Node& n)
{
  _isRed = n._isRed;
}
};

#endif // DS2_REDBLACKTREE_COMMON_REDBLACKTREENODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.