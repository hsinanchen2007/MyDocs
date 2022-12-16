#ifndef DS2_BTREE_COMMON_BTREEITER
#define DS2_BTREE_COMMON_BTREEITER

#include <iterator>

#include "ds2/BTreeInOrderIterative/BTreeInOrderIterative.h"

namespace ds2
{
template <class BTree>
class BTreeIter
{
 public:
  friend BTree;

  typedef typename BTree::pointer pointer;
  typedef typename BTree::reference reference;
  typedef typename BTree::difference_type difference_type;
  typedef typename BTree::value_type value_type;
  typedef std::bidirectional_iterator_tag iterator_category;

  BTreeIter();

  bool operator==(const BTreeIter& rhs) const;
  bool operator!=(const BTreeIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;

  BTreeIter& operator++();
  BTreeIter& operator--();
  BTreeIter operator++(int n);
  BTreeIter operator--(int n);

 private:
  typedef typename BTree::Location Location;

  BTreeIter(BTree* bTree, Location location);

  BTree* _bTree;
  Location _location;
};

template <class BTree>
inline BTreeIter<BTree>::BTreeIter()
{
  // ...
}

template <class BTree>
inline bool BTreeIter<BTree>::operator==(const BTreeIter& rhs) const
{
  return _location == rhs._location;
}

template <class BTree>
inline bool BTreeIter<BTree>::operator!=(const BTreeIter& rhs) const
{
  return _location != rhs._location;
}

template <class BTree>
inline typename BTreeIter<BTree>::pointer BTreeIter<BTree>::operator->() const
{
  return &_location.node->element(_location.index);
}

template <class BTree>
inline typename BTreeIter<BTree>::reference BTreeIter<BTree>::operator*() const
{
  return _location.node->element(_location.index);
}

template <class BTree>
inline BTreeIter<BTree>& BTreeIter<BTree>::operator++()
{
  _location = bTreeInOrderSuccessor(_location);

  return *this;
}

template <class BTree>
BTreeIter<BTree>& BTreeIter<BTree>::operator--()
{
  if (_location.node != nullptr)
  {
    _location = bTreeInOrderPredecessor(_location);

  }
  else
  {
    _location.node = _bTree->_tail;
    _location.index = _bTree->_tail->backElementIndex();
  }

  return *this;
}

template <class BTree>
inline BTreeIter<BTree> BTreeIter<BTree>::operator++(int n)
{
  BTreeIter original(*this);

  ++(*this);

  return original;
}

template <class BTree>
inline BTreeIter<BTree> BTreeIter<BTree>::operator--(int n)
{
  BTreeIter original(*this);

  --(*this);

  return original;
}

template <class BTree>
inline BTreeIter<BTree>::BTreeIter(BTree* bTree, Location location):
  _bTree(bTree),
  _location(location)
{
  // ...
}
};

#endif // DS2_BTREE_COMMON_BTREEITER

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.