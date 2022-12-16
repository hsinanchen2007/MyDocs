#ifndef DSS_RING_1_RING
#define DSS_RING_1_RING

#include "dss/Allocator/Allocator.h"

namespace dss
{
template <class T>
class Ring
{
 public:
  typedef const T* const_pointer;
  typedef const T& const_reference;
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
  const_reference front() const;
  const_reference back() const;

  reference front();
  reference back();
  void reserve(size_type newCapacity);
  void push_back(const T& source);

 private:
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

#endif // DSS_RING_1_RING

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.