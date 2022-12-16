#ifndef DS2_BTREE_1_BTREE
#define DS2_BTREE_1_BTREE

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include "ds2/BTree/common/BTreeNode.h"

namespace ds2
{
template <class Key,
  class Mapped,
  class KeyPred = std::less<Key>,
  std::size_t Order = 5>
class BTree
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef KeyPred key_compare;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef BTreeNode<Key, Mapped, KeyPred, Order> Node;

  BTree();
  ~BTree();

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
  void insert(const value_type& newElement);
  Node* root();
  Node* head();
  Node* tail();

 private:
  typedef size_type Index;
  typedef std::pair<Key, Mapped> value_type_writable;

  struct NewKeySearch
  {
    bool newKeyAlreadyExists;
    Node* node;
    Index index;
  };

  struct SplitNode
  {
    value_type_writable middleElement;
    Node* leftHalf;
    Node* rightHalf;
  };

  NewKeySearch _findInsertionPointForNewKey(const key_type& newKey) const;

  void _balanceOnInsert(Node* n);
  SplitNode _extractMiddleElementAndSplitNode(Node* n);
  Node* _createNode();
  void _destroyNode(Node* n);
  void _destroyTree(Node* root);

  Node* _root;
  Node* _head;
  Node* _tail;
  size_type _size;
  KeyPred _keyPred;
  std::allocator<Node> _alloc;
};
};

#include "ds2/BTree/common/memberFunctions_1.h"
#include "ds2/BTree/insert/insert_1.h"

#endif // DS2_BTREE_1_BTREE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.