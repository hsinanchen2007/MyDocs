#ifndef DS2_FORWARDLISTSIZE_1_FORWARDLISTSIZE
#define DS2_FORWARDLISTSIZE_1_FORWARDLISTSIZE

#include "ds2/ForwardList/5/ForwardList.h"

namespace ds2
{
template <class T>
class ForwardListSize
{
 public:
  typedef ForwardList<T> List;

  typedef typename List::const_iterator const_iterator;
  typedef typename List::const_pointer const_pointer;
  typedef typename List::const_reference const_reference;
  typedef typename List::iterator iterator;
  typedef typename List::pointer pointer;
  typedef typename List::reference reference;
  typedef typename List::difference_type difference_type;
  typedef typename List::size_type size_type;
  typedef typename List::value_type value_type;

  ForwardListSize();

  bool empty() const;
  size_type size() const;
  const_iterator before_begin() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reference front() const;

  iterator before_begin();
  iterator begin();
  iterator end();
  reference front();
  iterator insert_after(const_iterator insertionPoint, const T& newElement);
  iterator erase_after(const_iterator erasurePoint);
  void push_front(const T& newElement);
  void pop_front();
  void clear();

 private:
  size_type _size;
  List _list;
};
};

#include "ds2/ForwardListSize/common/memberFunctions_1.h"

#endif // DS2_FORWARDLISTSIZE_1_FORWARDLISTSIZE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.