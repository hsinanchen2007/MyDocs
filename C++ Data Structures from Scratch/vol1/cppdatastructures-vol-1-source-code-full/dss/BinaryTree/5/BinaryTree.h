#ifndef DSS_BINARYTREE_5_BINARYTREE
#define DSS_BINARYTREE_5_BINARYTREE

#include "dss/Allocator/Allocator.h"
#include "dss/BinaryTreeIter/BinaryTreeIter.h"
#include "dss/BinaryTreeNode/BinaryTreeNode.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/Pair/Pair.h"
#include "dss/predicates/predicates.h"
#include "dss/ReverseIter/ReverseIter.h"

namespace dss
{
template <class Key, class Mapped, class Predicate = Less<Key>>
class BinaryTree
{
 public:
  friend class BinaryTreeIter<BinaryTree>;

  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef Pair<const key_type, mapped_type> value_type;
  typedef Predicate key_compare;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef ConstIter<BinaryTree> const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef BinaryTreeIter<BinaryTree> iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef BinaryTreeNode<key_type, mapped_type> Node;

  BinaryTree();
  BinaryTree(const BinaryTree& source);
  ~BinaryTree();

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
  BinaryTree& operator=(const BinaryTree& rhs);
  iterator find(const key_type& searchKey);
  Pair<iterator, bool> insert(const value_type& sourceElement);
  iterator erase(const_iterator erasurePoint);
  void clear();
  void rotate(const_iterator rotationPoint);

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
  Allocator<Node> _alloc;
};
};

#include "dss/BinaryTree/common/memberFunctions_1.h"
#include "dss/BinaryTree/common/memberFunctions_2.h"
#include "dss/BinaryTree/common/memberFunctions_3.h"
#include "dss/BinaryTree/common/memberFunctions_4.h"
#include "dss/BinaryTree/common/memberFunctions_5.h"

#endif // DSS_BINARYTREE_5_BINARYTREE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.