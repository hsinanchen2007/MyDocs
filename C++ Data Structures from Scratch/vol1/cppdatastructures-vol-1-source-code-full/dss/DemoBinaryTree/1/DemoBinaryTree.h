#ifndef DSS_DEMOBINARYTREE_1_DEMOBINARYTREE
#define DSS_DEMOBINARYTREE_1_DEMOBINARYTREE

#include "dss/Allocator/Allocator.h"
#include "dss/Array/2/Array.h"
#include "dss/BinaryTreeNode/BinaryTreeNode.h"
#include "dss/bt/relatives.h"
#include "dss/Pair/Pair.h"
#include "dss/predicates/predicates.h"

namespace dss
{
class DemoBinaryTree
{
 public:
  typedef int key_type;
  typedef char mapped_type;
  typedef Pair<const key_type, mapped_type> value_type;
  typedef Less<key_type> key_compare;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef BinaryTreeNode<key_type, mapped_type> Node;

  DemoBinaryTree();
  ~DemoBinaryTree();

  bool empty() const;
  size_type size() const;
  const_reference front() const;
  const_reference back() const;
  key_compare key_comp() const;
  const Node* root() const;
  const Node* head() const;
  const Node* tail() const;

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

DemoBinaryTree::DemoBinaryTree()
{
  _createAllNodes();
  _setParentAndChildLinks();

  _root = _n[7];
  _head = bt::leftmostNode(_root);
  _tail = bt::rightmostNode(_root);
}

void DemoBinaryTree::_destroyAllNodes()
{
  for (int i = 0; i != _n.size(); ++i)
    _destroyNode(_n[i]);
}
};

#include "dss/DemoBinaryTree/common/memberFunctions_1.h"

#endif // DSS_DEMOBINARYTREE_1_DEMOBINARYTREE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.