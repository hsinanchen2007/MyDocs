#ifndef DS2_FORWARDLIST_COMMON_FORWARDLISTITER
#define DS2_FORWARDLIST_COMMON_FORWARDLISTITER

#include <iterator>

namespace ds2
{
template <class ForwardList>
class ForwardListIter
{
 public:
  friend ForwardList;

  typedef typename ForwardList::pointer pointer;
  typedef typename ForwardList::reference reference;
  typedef typename ForwardList::difference_type difference_type;
  typedef typename ForwardList::value_type value_type;
  typedef std::forward_iterator_tag iterator_category;

  ForwardListIter();

  bool operator==(const ForwardListIter& rhs) const;
  bool operator!=(const ForwardListIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;

  ForwardListIter& operator++();
  ForwardListIter operator++(int n);

 private:
  typedef typename ForwardList::Node Node;
  typedef typename ForwardList::ElementNode ElementNode;

  ForwardListIter(Node* n);

  Node* _n;
};

template <class ForwardList>
ForwardListIter<ForwardList>::ForwardListIter()
{
  // ...
}

template <class ForwardList>
inline bool ForwardListIter<ForwardList>::operator==(
  const ForwardListIter& rhs) const
{
  return _n == rhs._n;
}

template <class ForwardList>
inline bool ForwardListIter<ForwardList>::operator!=(
  const ForwardListIter& rhs) const
{
  return _n != rhs._n;
}

template <class ForwardList>
inline typename ForwardListIter<ForwardList>::pointer
ForwardListIter<ForwardList>::operator->() const
{
  return &(static_cast<ElementNode*>(_n)->element);
}

template <class ForwardList>
inline typename ForwardListIter<ForwardList>::reference
ForwardListIter<ForwardList>::operator*() const
{
  return static_cast<ElementNode*>(_n)->element;
}

template <class ForwardList>
inline ForwardListIter<ForwardList>& ForwardListIter<ForwardList>::operator++()
{
  _n = _n->next;

  return *this;
}

template <class ForwardList>
inline ForwardListIter<ForwardList> ForwardListIter<ForwardList>::operator++(
  int n)
{
  ForwardListIter original(*this);

  _n = _n->next;

  return original;
}

template <class ForwardList>
inline ForwardListIter<ForwardList>::ForwardListIter(Node* n):
  _n(n)
{
  // ...
}
};

#endif // DS2_FORWARDLIST_COMMON_FORWARDLISTITER

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.