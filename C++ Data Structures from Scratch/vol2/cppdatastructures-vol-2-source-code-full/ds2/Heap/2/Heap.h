#ifndef DS2_HEAP_2_HEAP
#define DS2_HEAP_2_HEAP

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
  void pop();

 private:
  typedef int Node;

  Node _leftChild(Node n) const;
  Node _rightChild(Node n) const;
  Node _getChildForComparison(Node n) const;

  bool _isLeaf(Node n) const;
  bool _hasTwoChildren(Node n) const;

  std::deque<T> _deque;
  Predicate _predicate;
};
};

#include "ds2\Heap\common\memberFunctions_1.h"
#include "ds2\Heap\common\memberFunctions_2.h"

#endif // DS2_HEAP_2_HEAP

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.