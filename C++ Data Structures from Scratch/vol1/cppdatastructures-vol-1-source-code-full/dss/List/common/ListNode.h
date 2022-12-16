#ifndef DSS_LIST_COMMON_LISTNODE
#define DSS_LIST_COMMON_LISTNODE

namespace dss
{
template <class T>
struct ListNode
{
  ListNode(const T& sourceElement);

  T element;

  ListNode* left;
  ListNode* right;
};

template <class T>
inline ListNode<T>::ListNode(const T& sourceElement):
  element(sourceElement),
  left(nullptr),
  right(nullptr)
{
  // ...
}
};

#endif // DSS_LIST_COMMON_LISTNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.