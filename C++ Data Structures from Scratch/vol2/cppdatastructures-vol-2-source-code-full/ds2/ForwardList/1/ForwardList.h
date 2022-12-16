#ifndef DS2_FORWARDLIST_1_FORWARDLIST
#define DS2_FORWARDLIST_1_FORWARDLIST

#include <cstddef>
#include <memory>

#include "ds2/ForwardList/common/ForwardListNode.h"

namespace ds2
{
template <class T>
class ForwardList
{
 public:
  typedef const T* const_pointer;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef T& reference;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;
  typedef T value_type;

  ForwardList();
  ~ForwardList();

  bool empty() const;
  const_reference front() const;

  reference front();
  void push_front(const T& newElement);

 private:
  typedef ForwardListNode Node;
  typedef ForwardListElementNode<T> ElementNode;

  ElementNode* _downcast(Node* n) const;

  ElementNode* _createElementNode(const T& newElement);
  void _destroyElementNode(ElementNode* n);
  void _destroyAllElementNodes();

  Node _beforeHead;
  std::allocator<ElementNode> _alloc;
};
};

#include "ds2/ForwardList/common/memberFunctions_1.h"

#endif // DS2_FORWARDLIST_1_FORWARDLIST

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.