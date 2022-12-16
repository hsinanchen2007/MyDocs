#ifndef DSS_RING_4_RING
#define DSS_RING_4_RING

#include "dss/Allocator/Allocator.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/RingIter/RingIter.h"
#include "dss/ReverseIter/ReverseIter.h"

namespace dss
{
template <class T>
class Ring
{
 public:
  friend class RingIter<Ring>;

  typedef ConstIter<Ring> const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef RingIter<Ring> iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  Ring();
  ~Ring();

  bool empty() const;
  size_type size() const;
  size_type capacity() const;
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
  void reserve(size_type newCapacity);
  void push_front(const T& source);
  void push_back(const T& source);
  void pop_front();
  void pop_back();
  void clear();

 private:
  reference _element(size_type index) const;

  void _reallocate(size_type newCapacity);
  void _destroyAllElements();

  T* _block;
  T* _endOfBlock;
  T* _head;
  T* _tail;
  size_type _size;
  size_type _capacity;
  Allocator<T> _alloc;
};
};

#include "dss/Ring/common/memberFunctions_1.h"
#include "dss/Ring/common/memberFunctions_2.h"
#include "dss/Ring/common/memberFunctions_3.h"
#include "dss/Ring/common/memberFunctions_4.h"

#endif // DSS_RING_4_RING

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.