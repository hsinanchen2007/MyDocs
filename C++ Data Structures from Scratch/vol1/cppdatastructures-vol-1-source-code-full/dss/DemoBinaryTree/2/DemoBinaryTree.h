#ifndef DSS_DEMOBINARYTREE_2_DEMOBINARYTREE
#define DSS_DEMOBINARYTREE_2_DEMOBINARYTREE

#include "dss/Allocator/Allocator.h"
#include "dss/Array/2/Array.h"
#include "dss/BinaryTreeIter/BinaryTreeIter.h"
#include "dss/BinaryTreeNode/BinaryTreeNode.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/Pair/Pair.h"
#include "dss/predicates/predicates.h"
#include "dss/ReverseIter/ReverseIter.h"

namespace dss
{
class DemoBinaryTree
{
 public:
  friend class BinaryTreeIter<DemoBinaryTree>;

  typedef int key_type;
  typedef char mapped_type;
  typedef Pair<const key_type, mapped_type> value_type;
  typedef Less<key_type> key_compare;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef ConstIter<DemoBinaryTree> const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef BinaryTreeIter<DemoBinaryTree> iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef BinaryTreeNode<key_type, mapped_type> Node;

  DemoBinaryTree();
  ~DemoBinaryTree();

  bool empty() const;
  size_type size() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reference front() const;
  const_reference back() const;
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

 private:
  typedef key_compare Predicate;

  DemoBinaryTree(const DemoBinaryTree& source);

  Node* _createNode(const value_type& sourceElement);
  void _createAllNodes();
  void _setParentAndChildLinks();
  void _destroyNode(Node* n);
  void _destroyAllNodes();
  DemoBinaryTree& operator=(const DemoBinaryTree& rhs);

  Node* _root;
  Node* _head;
  Node* _tail;
  Predicate _predicate;
  Array<Node*, 15> _n;
  Allocator<Node> _alloc;
};
};

#include "dss/DemoBinaryTree/common/memberFunctions_1.h"
#include "dss/DemoBinaryTree/common/memberFunctions_2.h"

#endif // DSS_DEMOBINARYTREE_2_DEMOBINARYTREE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.