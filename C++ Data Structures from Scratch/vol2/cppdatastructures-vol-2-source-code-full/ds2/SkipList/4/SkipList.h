#ifndef DS2_SKIPLIST_4_SKIPLIST
#define DS2_SKIPLIST_4_SKIPLIST

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>
#include <vector>

#include "dss/ConstIter/ConstIter.h"
#include "dss/ReverseIter/ReverseIter.h"

#include "ds2/SkipList/common/SkipListIter.h"
#include "ds2/SkipList/common/SkipListNode.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate = std::less<Key>>
class SkipList
{
 public:
  friend class SkipListIter<SkipList>;

  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef Predicate key_compare;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef dss::ConstIter<SkipList> const_iterator;
  typedef dss::ReverseIter<const_iterator> const_reverse_iterator;
  typedef const value_type* const_pointer;
  typedef const value_type& const_reference;
  typedef SkipListIter<SkipList> iterator;
  typedef dss::ReverseIter<iterator> reverse_iterator;
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
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reference front() const;
  const_reference back() const;
  const_iterator find(const key_type& key) const;
  key_compare key_comp() const;
  const NodeVector& head() const;
  Level topLevel() const;
  const CountVector& availableNodes() const;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
  reference front();
  reference back();
  iterator find(const key_type& key);
  void increaseTopLevel(Level newTopLevel);
  void reserve(size_type newCapacity);
  std::pair<iterator, bool> insert(const value_type& newElement);
  iterator erase(const_iterator element);
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

  void _findRightLinksOnErase(Node* trash, LinkVector& rightLinks);

  void _attachNewNode(Node* newNode,
    const LinkVector& rightLinks,
    const NodeVector& rightNeighbors);

  void _detachNode(Node* trash, const LinkVector& rightLinks);
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
#include "ds2/SkipList/common/memberFunctions_2.h"
#include "ds2/SkipList/common/memberFunctions_3.h"
#include "ds2/SkipList/common/memberFunctions_4.h"
#include "ds2/SkipList/insert/insert_3.h"

#endif // DS2_SKIPLIST_4_SKIPLIST

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.