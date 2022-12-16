#ifndef DSS_ARRAY_2_ARRAY
#define DSS_ARRAY_2_ARRAY

#include "dss/ReverseIter/ReverseIter.h"

namespace dss
{
template <class T, const unsigned int Size>
class Array
{
 public:
  typedef const T* const_iterator;
  typedef ReverseIter<const_iterator> const_reverse_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T* iterator;
  typedef ReverseIter<iterator> reverse_iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

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

 private:
  T _a[Size];
};
};

#include "dss/Array/common/memberFunctions_1.h"
#include "dss/Array/common/memberFunctions_2.h"

#endif // DSS_ARRAY_2_ARRAY

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.