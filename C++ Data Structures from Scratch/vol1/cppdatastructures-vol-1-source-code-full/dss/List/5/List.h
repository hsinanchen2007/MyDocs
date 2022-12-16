#ifndef DSS_LIST_5_LIST
#define DSS_LIST_5_LIST

#include "dss/Allocator/Allocator.h"
#include "dss/ConstIter/ConstIter.h"
#include "dss/List/common/ListIter.h"
#include "dss/List/common/ListNode.h"

namespace dss
{
template <class T>
class List
{
 public:
  friend class ListIter<List>;

  typedef ConstIter<List> const_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef ListIter<List> iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef int difference_type;
  typedef unsigned int size_type;
  typedef T value_type;

  List();
  List(const List& source);
  ~List();

  bool empty() const;
  size_type size() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reference front() const;
  const_reference back() const;

  iterator begin();
  iterator end();
  reference front();
  reference back();
  List& operator=(const List& rhs);
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
#include "dss/List/common/memberFunctions_3.h"
#include "dss/List/common/memberFunctions_4.h"
#include "dss/List/common/memberFunctions_5.h"

#endif // DSS_LIST_5_LIST

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.