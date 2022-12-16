#ifndef DS2_SKIPLIST_COMMON_SKIPLISTITER
#define DS2_SKIPLIST_COMMON_SKIPLISTITER

#include <iterator>

namespace ds2
{
template <class SkipList>
class SkipListIter
{
 public:
  friend SkipList;

  typedef typename SkipList::pointer pointer;
  typedef typename SkipList::reference reference;
  typedef typename SkipList::difference_type difference_type;
  typedef typename SkipList::value_type value_type;
  typedef std::bidirectional_iterator_tag iterator_category;

  SkipListIter();

  bool operator==(const SkipListIter& rhs) const;
  bool operator!=(const SkipListIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;

  SkipListIter& operator++();
  SkipListIter& operator--();
  SkipListIter operator++(int n);
  SkipListIter operator--(int n);

 private:
  typedef typename SkipList::Node Node;

  SkipListIter(SkipList* skipList, Node* node);

  SkipList* _skipList;
  Node* _node;
};

template <class SkipList>
inline SkipListIter<SkipList>::SkipListIter()
{
  // ...
}

template <class SkipList>
inline bool SkipListIter<SkipList>::operator==(const SkipListIter& rhs) const
{
  return _node == rhs._node;
}

template <class SkipList>
inline bool SkipListIter<SkipList>::operator!=(const SkipListIter& rhs) const
{
  return _node != rhs._node;
}

template <class SkipList>
inline typename SkipListIter<SkipList>::pointer
SkipListIter<SkipList>::operator->() const
{
  return &_node->element;
}

template <class SkipList>
inline typename SkipListIter<SkipList>::reference
SkipListIter<SkipList>::operator*() const
{
  return _node->element;
}

template <class SkipList>
inline SkipListIter<SkipList>& SkipListIter<SkipList>::operator++()
{
  _node = _node->right[0];

  return *this;
}

template <class SkipList>
inline SkipListIter<SkipList>& SkipListIter<SkipList>::operator--()
{
  if (_node != nullptr)
    _node = _node->left;
  else
    _node = _skipList->_tail;

  return *this;
}

template <class SkipList>
inline SkipListIter<SkipList> SkipListIter<SkipList>::operator++(int n)
{
  SkipListIter original(*this);

  ++(*this);

  return original;
}

template <class SkipList>
inline SkipListIter<SkipList> SkipListIter<SkipList>::operator--(int n)
{
  SkipListIter original(*this);

  --(*this);

  return original;
}

template <class SkipList>
inline SkipListIter<SkipList>::SkipListIter(SkipList* skipList, Node* node):
  _skipList(skipList),
  _node(node)
{
  // ...
}
};

#endif // DS2_SKIPLIST_COMMON_SKIPLISTITER

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.