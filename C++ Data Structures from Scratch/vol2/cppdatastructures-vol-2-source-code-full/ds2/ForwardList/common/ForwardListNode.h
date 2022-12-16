#ifndef DS2_FORWARDLIST_COMMON_FORWARDLISTNODE
#define DS2_FORWARDLIST_COMMON_FORWARDLISTNODE

namespace ds2
{
struct ForwardListNode
{
  ForwardListNode();

  ForwardListNode* next;
};

template <class T>
struct ForwardListElementNode : public ForwardListNode
{
  ForwardListElementNode(const T& element);

  T element;
};

ForwardListNode::ForwardListNode():
  next(nullptr)
{
  // ...
}

template <class T>
inline ForwardListElementNode<T>::ForwardListElementNode(const T& element):
  element(element)
{
  // ...
}
};

#endif // DS2_FORWARDLIST_COMMON_FORWARDLISTNODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.