#ifndef DS2_HEAP_1_HEAP
#define DS2_HEAP_1_HEAP

#include <deque>
#include <functional>

namespace ds2
{
template <class T, class Predicate = std::less<T>>
class Heap
{
 public:
  typedef std::deque<T> container_type;
  typedef const T& const_reference;
  typedef T& reference;
  typedef typename container_type::size_type size_type;
  typedef T value_type;

  bool empty() const;
  size_type size() const;
  const T& top() const;

  void push(const T& value);

 private:
  typedef int Node;

  std::deque<T> _deque;
  Predicate _predicate;
};
};

#include "ds2\Heap\common\memberFunctions_1.h"

#endif // DS2_HEAP_1_HEAP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.