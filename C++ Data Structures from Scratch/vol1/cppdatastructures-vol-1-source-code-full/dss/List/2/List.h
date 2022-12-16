#ifndef DSS_LIST_2_LIST
#define DSS_LIST_2_LIST

#include "dss/Allocator/Allocator.h"
#include "dss/List/common/ListNode.h"

namespace dss
{
template <class T>
class List
{
 public:
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  List();
  ~List();

  bool empty() const;
  size_type size() const;
  const_reference front() const;
  const_reference back() const;

  reference front();
  reference back();
  void push_front(const T& source);
  void push_back(const T& source);
  void pop_front();
  void pop_back();
  void clear();

 private:
  typedef ListNode<T> Node;

  Node* _createNode(const T& source);
  void _destroyNode(Node* n);
  void _destroyAllNodes();

  Node* _head;
  Node* _tail;
  size_type _size;
  Allocator<Node> _alloc;
};
};

#include "dss/List/common/memberFunctions_1.h"
#include "dss/List/common/memberFunctions_2.h"

#endif // DSS_LIST_2_LIST

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.