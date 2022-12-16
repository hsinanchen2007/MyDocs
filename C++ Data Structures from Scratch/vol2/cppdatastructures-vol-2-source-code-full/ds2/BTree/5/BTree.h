#ifndef DS2_BTREE_5_BTREE
#define DS2_BTREE_5_BTREE

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include "dss/ConstIter/ConstIter.h"
#include "dss/ReverseIter/ReverseIter.h"

#include "ds2/BTree/common/BTreeIter.h"
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
  friend class BTreeIter<BTree>;

  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef KeyPred key_compare;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef dss::ConstIter<BTree> const_iterator;
  typedef dss::ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef BTreeIter<BTree> iterator;
  typedef dss::ReverseIter<iterator> reverse_iterator;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef BTreeNode<Key, Mapped, KeyPred, Order> Node;
  typedef size_type Index;

  struct Location
  {
    typedef Node Node;
    typedef Index Index;

    Location();
    Location(Node* node, Index index);

    bool operator==(const Location& rhs) const;
    bool operator!=(const Location& rhs) const;

    Node* node;
    Index index;
  };

  BTree();
  BTree(const BTree& source);
  ~BTree();

  bool empty() const;
  size_type size() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reference front() const;
  const_reference back() const;
  const_iterator find(const key_type& key) const;
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
  BTree& operator=(const BTree& rhs);
  iterator find(const key_type& key);
  std::pair<iterator, bool> insert(const value_type& newElement);
  iterator erase(const_iterator element);
  void clear();
  Node* root();
  Node* head();
  Node* tail();

 private:
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

  struct LeafElement
  {
    Node* node;
    Index index;
    bool hasSuccessor;
    key_type successorKey;
  };

  Location _location(const key_type& key) const;
  NewKeySearch _findInsertionPointForNewKey(const key_type& newKey) const;

  void _balanceOnInsert(Node* n);
  SplitNode _extractMiddleElementAndSplitNode(Node* n);
  LeafElement _getLeafElementForDeletion(const_iterator element);
  void _swapElements(Location a, Location b);
  void _balanceOnErase(Node* n);
  void _rotateParentElementLeft(Node* n, Node* rightSibling);
  void _rotateParentElementRight(Node* n, Node* leftSibling);
  void _mergeRootWithItsTwoChildren();
  Node* _mergeWithLeftSibling(Node* n, Node* leftSibling);
  Node* _mergeWithRightSibling(Node* n, Node* rightSibling);
  Node* _copyNode(Node* sourceNode, Node* newParent);
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

#include "ds2/BTree/common/Location.h"
#include "ds2/BTree/common/memberFunctions_1.h"
#include "ds2/BTree/common/memberFunctions_2.h"
#include "ds2/BTree/common/memberFunctions_3.h"
#include "ds2/BTree/common/memberFunctions_4.h"
#include "ds2/BTree/insert/insert_2.h"

#endif // DS2_BTREE_5_BTREE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.