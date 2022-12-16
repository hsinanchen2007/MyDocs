#ifndef DSS_MULTIRING_2_MULTIRING
#define DSS_MULTIRING_2_MULTIRING

#include "dss/Allocator/Allocator.h"
#include "dss/Ring/5/Ring.h"

namespace dss
{
template <class T>
class MultiRing
{
 public:
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  MultiRing();
  ~MultiRing();

  bool empty() const;
  size_type size() const;
  const_reference front() const;
  const_reference back() const;
  const_reference operator[](size_type index) const;

  reference front();
  reference back();
  reference operator[](size_type index);
  void push_front(const T& source);
  void push_back(const T& source);

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

#endif // DSS_MULTIRING_2_MULTIRING

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.