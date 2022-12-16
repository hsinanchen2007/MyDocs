#ifndef DS2_REDBLACKTREE_1_REDBLACKTREE
#define DS2_REDBLACKTREE_1_REDBLACKTREE

#include <functional>
#include <memory>
#include <utility>

#include "dss/BinaryTreeIter/BinaryTreeIter.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/ReverseIter/ReverseIter.h"

#include "ds2/RedBlackTree/common/RedBlackTreeNode.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate = std::less<Key>>
class RedBlackTree
{
 public:
  friend class dss::BinaryTreeIter<RedBlackTree>;

  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const key_type, mapped_type> value_type;
  typedef Predicate key_compare;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef dss::ConstIter<RedBlackTree> const_iterator;
  typedef dss::ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef dss::BinaryTreeIter<RedBlackTree> iterator;
  typedef dss::ReverseIter<iterator> reverse_iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef RedBlackTreeNode<key_type, mapped_type> Node;

  RedBlackTree();
  RedBlackTree(const RedBlackTree& source);
  ~RedBlackTree();

  bool empty() const;
  size_type size() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reference front() const;
  const_reference back() const;
  const_iterator find(const key_type& searchKey) const;
  key_compare key_comp() const;
  const Node* root() const;
  const Node* head() const;
  const Node* tail() const;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
  reference front();
  reference back();
  RedBlackTree& operator=(const RedBlackTree& rhs);
  iterator find(const key_type& searchKey);
  void clear();

 private:
  Node* _copyNode(Node* sourceNode, Node* newParent);
  Node* _createNode(const value_type& sourceElement);
  void _destroyNode(Node* n);
  void _destroyAllNodes();
  void _overwriteElement(Node* n, const value_type& sourceElement);

  Node* _root;
  Node* _head;
  Node* _tail;
  size_type _size;
  Predicate _predicate;
  std::allocator<Node> _alloc;
};
};

#include "ds2/RedBlackTree/common/memberFunctions_1.h"
#include "ds2/RedBlackTree/common/memberFunctions_2.h"

#endif // DS2_REDBLACKTREE_1_REDBLACKTREE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.