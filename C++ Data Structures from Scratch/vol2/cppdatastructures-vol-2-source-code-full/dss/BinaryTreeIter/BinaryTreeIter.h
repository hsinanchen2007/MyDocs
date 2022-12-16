#ifndef DSS_BINARYTREEITER_BINARYTREEITER
#define DSS_BINARYTREEITER_BINARYTREEITER

#include <iterator>

namespace dss
{
template <class Tree>
class BinaryTreeIter
{
 public:
  friend Tree;

  typedef typename Tree::pointer pointer;
  typedef typename Tree::reference reference;
  typedef typename Tree::difference_type difference_type;
  typedef typename Tree::value_type value_type;
  typedef std::bidirectional_iterator_tag iterator_category;

  BinaryTreeIter();

  bool operator==(const BinaryTreeIter& rhs) const;
  bool operator!=(const BinaryTreeIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;

  BinaryTreeIter& operator++();
  BinaryTreeIter& operator--();
  BinaryTreeIter operator++(int n);
  BinaryTreeIter operator--(int n);

 private:
  typedef typename Tree::Node Node;

  BinaryTreeIter(Tree* tree, Node* node);

  void _pointToNextNode();
  void _pointToPreviousNode();

  Tree* _tree;
  Node* _node;
};

template <class Tree>
inline BinaryTreeIter<Tree>::BinaryTreeIter()
{
  // ...
}

template <class Tree>
inline bool BinaryTreeIter<Tree>::operator==(const BinaryTreeIter& rhs) const
{
  return _node == rhs._node;
}

template <class Tree>
inline bool BinaryTreeIter<Tree>::operator!=(const BinaryTreeIter& rhs) const
{
  return _node != rhs._node;
}

template <class Tree>
inline typename BinaryTreeIter<Tree>::pointer
BinaryTreeIter<Tree>::operator->() const
{
  return &_node->element;
}

template <class Tree>
inline typename BinaryTreeIter<Tree>::reference
BinaryTreeIter<Tree>::operator*() const
{
  return _node->element;
}

template <class Tree>
inline BinaryTreeIter<Tree>& BinaryTreeIter<Tree>::operator++()
{
  _pointToNextNode();

  return *this;
}

template <class Tree>
inline BinaryTreeIter<Tree>& BinaryTreeIter<Tree>::operator--()
{
  _pointToPreviousNode();

  return *this;
}

template <class Tree>
inline BinaryTreeIter<Tree> BinaryTreeIter<Tree>::operator++(int n)
{
  BinaryTreeIter iterToOriginalNode(*this);

  _pointToNextNode();

  return iterToOriginalNode;
}

template <class Tree>
inline BinaryTreeIter<Tree> BinaryTreeIter<Tree>::operator--(int n)
{
  BinaryTreeIter iterToOriginalNode(*this);

  _pointToPreviousNode();

  return iterToOriginalNode;
}

template <class Tree>
inline BinaryTreeIter<Tree>::BinaryTreeIter(Tree* tree, Node* node):
  _tree(tree),
  _node(node)
{
  // ...
}

template <class Tree>
inline void BinaryTreeIter<Tree>::_pointToNextNode()
{
  _node = _node->successor;
}

template <class Tree>
void BinaryTreeIter<Tree>::_pointToPreviousNode()
{
  if (_node != nullptr)
    _node = _node->predecessor;
  else
    _node = _tree->_tail;
}
};

#endif // DSS_BINARYTREEITER_BINARYTREEITER

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.