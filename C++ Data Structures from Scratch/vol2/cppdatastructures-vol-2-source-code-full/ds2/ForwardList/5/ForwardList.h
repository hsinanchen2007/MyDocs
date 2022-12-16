#ifndef DS2_FORWARDLIST_5_FORWARDLIST
#define DS2_FORWARDLIST_5_FORWARDLIST

#include <cstddef>
#include <memory>

#include "dss/ConstIter/ConstIter.h"

#include "ds2/ForwardList/common/ForwardListIter.h"
#include "ds2/ForwardList/common/ForwardListNode.h"

namespace ds2
{
template <class T>
class ForwardList
{
 public:
  friend class ForwardListIter<ForwardList>;

  typedef dss::ConstIter<ForwardList> const_iterator;
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef ForwardListIter<ForwardList> iterator;
  typedef T* pointer;
  typedef T& reference;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef T value_type;

  ForwardList();
  ForwardList(const ForwardList& source);
  ~ForwardList();

  bool empty() const;
  const_iterator before_begin() const;
  const_iterator begin() const;
  const_iterator end() const;
  const_reference front() const;

  iterator before_begin();
  iterator begin();
  iterator end();
  reference front();
  ForwardList& operator=(const ForwardList& rhs);
  iterator insert_after(const_iterator insertionPoint, const T& newElement);
  iterator erase_after(const_iterator erasurePoint);
  void push_front(const T& newElement);
  void pop_front();
  void clear();

 private:
  typedef ForwardListNode Node;
  typedef ForwardListElementNode<T> ElementNode;

  ElementNode* _downcast(Node* n) const;

  void _copyElementsFrom(const ForwardList& source);
  ElementNode* _createElementNode(const T& newElement);
  void _destroyElementNode(ElementNode* n);
  void _destroyAllElementNodes();

  Node _beforeHead;
  std::allocator<ElementNode> _alloc;
};
};

#include "ds2/ForwardList/common/memberFunctions_1.h"
#include "ds2/ForwardList/common/memberFunctions_2.h"
#include "ds2/ForwardList/common/memberFunctions_3.h"
#include "ds2/ForwardList/common/memberFunctions_4.h"
#include "ds2/ForwardList/common/memberFunctions_5.h"

#endif // DS2_FORWARDLIST_5_FORWARDLIST

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.