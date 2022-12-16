#ifndef DSS_AVLTREE_1_AVLTREE
#define DSS_AVLTREE_1_AVLTREE

#include "dss/Allocator/Allocator.h"
#include "dss/AvlTree/common/AvlTreeNode.h"
#include "dss/BinaryTreeIter/BinaryTreeIter.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/Pair/Pair.h"
#include "dss/predicates/predicates.h"
#include "dss/ReverseIter/ReverseIter.h"

namespace dss
{
template <class Key, class Mapped, class Predicate = Less<Key>>
class AvlTree
{
 public:
  friend class BinaryTreeIter<AvlTree>;

  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef Pair<const key_type, mapped_type> value_type;
  typedef Predicate key_compare;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef ConstIter<AvlTree> const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef BinaryTreeIter<AvlTree> iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef AvlTreeNode<key_type, mapped_type> Node;

  AvlTree();
  AvlTree(const AvlTree& source);
  ~AvlTree();

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
  AvlTree& operator=(const AvlTree& rhs);
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
  Allocator<Node> _alloc;
};
};

#include "dss/AvlTree/common/memberFunctions_1.h"
#include "dss/AvlTree/common/memberFunctions_2.h"

#endif // DSS_AVLTREE_1_AVLTREE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.