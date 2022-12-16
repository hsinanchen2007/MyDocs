#ifndef DS2_SKIPLIST_1_SKIPLIST
#define DS2_SKIPLIST_1_SKIPLIST

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>
#include <vector>

#include "ds2/SkipList/common/SkipListNode.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate = std::less<Key>>
class SkipList
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef Predicate key_compare;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef SkipListNode<Key, Mapped> Node;
  typedef std::vector<Node*> NodeVector;
  typedef size_type Level;
  typedef size_type NodeCount;
  typedef std::vector<NodeCount> CountVector;

  SkipList();
  ~SkipList();

  bool empty() const;
  size_type size() const;
  size_type capacity() const;
  const_reference front() const;
  const_reference back() const;
  key_compare key_comp() const;
  const NodeVector& head() const;
  Level topLevel() const;
  const CountVector& availableNodes() const;

  reference front();
  reference back();
  void insert(const value_type& newElement);
  void clear();

 private:
  typedef std::vector<Node**> LinkVector;
  typedef int SignedLevel;

  struct NewKeySearch
  {
    NewKeySearch(bool newKeyAlreadyExists, Node* node);

    bool newKeyAlreadyExists;
    Node* node;
  };

  void _initAvailableNodeCount();
  Level _getLevelForNewNode();

  NewKeySearch _findInsertionPointForNewKey(const key_type& newKey,
    LinkVector& rightLinks,
    NodeVector& rightNeighbors);

  void _attachNewNode(Node* newNode,
    const LinkVector& rightLinks,
    const NodeVector& rightNeighbors);

  Node* _createNode(Level topLevel, const value_type& element);
  void _destroyNode(Node* n);
  void _destroyAllNodes();

  static const Level _initialTopLevel = 3;

  NodeVector _head;
  Node* _tail;
  size_type _size;
  CountVector _availableNodes;
  Predicate _predicate;
  std::allocator<Node> _alloc;
};
};

#include "ds2/SkipList/common/memberFunctions_1.h"
#include "ds2/SkipList/insert/insert_1.h"

#endif // DS2_SKIPLIST_1_SKIPLIST

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.