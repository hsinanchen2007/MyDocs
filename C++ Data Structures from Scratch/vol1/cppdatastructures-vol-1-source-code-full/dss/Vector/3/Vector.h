#ifndef DSS_VECTOR_3_VECTOR
#define DSS_VECTOR_3_VECTOR

#include "dss/Allocator/Allocator.h"

namespace dss
{
template <class T>
class Vector
{
 public:
  typedef const T* const_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T* iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  Vector();
  Vector(const Vector& source);
  ~Vector();

  bool empty() const;
  size_type size() const;
  size_type capacity() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reference front() const;
  const_reference back() const;
  const_reference operator[](size_type index) const;

  iterator begin();
  iterator end();
  reference front();
  reference back();
  reference operator[](size_type index);
  Vector& operator=(const Vector& rhs);
  void reserve(size_type newCapacity);
  iterator insert(const_iterator insertionPoint, const T& source);
  iterator erase(const_iterator erasurePoint);
  void push_back(const T& source);
  void pop_back();
  void clear();

 private:
  void _reallocate(size_type newCapacity);
  void _destroyAllElements();

  T* _block;
  size_type _size;
  size_type _capacity;
  Allocator<T> _alloc;
};
};

#include "dss/Vector/common/memberFunctions_1.h"
#include "dss/Vector/common/memberFunctions_2.h"
#include "dss/Vector/common/memberFunctions_3.h"

#endif // DSS_VECTOR_3_VECTOR

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.