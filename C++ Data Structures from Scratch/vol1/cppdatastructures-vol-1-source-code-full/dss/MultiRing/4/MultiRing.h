#ifndef DSS_MULTIRING_4_MULTIRING
#define DSS_MULTIRING_4_MULTIRING

#include "dss/Allocator/Allocator.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/Ring/5/Ring.h"
#include "dss/RingIter/RingIter.h"

namespace dss
{
template <class T>
class MultiRing
{
 public:
  friend class RingIter<MultiRing>;

  typedef ConstIter<MultiRing> const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef RingIter<MultiRing> iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  MultiRing();
  MultiRing(const MultiRing& source);
  ~MultiRing();

  bool empty() const;
  size_type size() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  const_reference front() const;
  const_reference back() const;
  const_reference operator[](size_type index) const;

  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
  reference front();
  reference back();
  reference operator[](size_type index);
  MultiRing& operator=(const MultiRing& rhs);
  iterator insert(const_iterator insertionPoint, const T& source);
  iterator erase(const_iterator erasurePoint);
  void push_front(const T& source);
  void push_back(const T& source);
  void pop_front();
  void pop_back();
  void clear();

 private:
  typedef Ring<T> Page;

  reference _element(size_type index) const;

  Page* _createPage();
  void _destroyPage(Page* p);
  void _destroyAllPages();

  static const size_type _pageCapacity = 5;

  Ring<Page*> _pages;
  size_type _size;
  Allocator<Page> _alloc;
};
};

#include "dss/MultiRing/common/memberFunctions_1.h"
#include "dss/MultiRing/common/memberFunctions_2.h"
#include "dss/MultiRing/common/memberFunctions_3.h"
#include "dss/MultiRing/common/memberFunctions_4.h"

#endif // DSS_MULTIRING_4_MULTIRING

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.