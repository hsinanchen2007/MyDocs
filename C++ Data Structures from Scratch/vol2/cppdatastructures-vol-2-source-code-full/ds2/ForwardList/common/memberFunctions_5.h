namespace ds2
{
template <class T>
inline ForwardList<T>::ForwardList(const ForwardList& source)  
{
  _copyElementsFrom(source);
}

template <class T>
inline ForwardList<T>& ForwardList<T>::operator=(const ForwardList& rhs)
{
  clear();
  _copyElementsFrom(rhs);

  return *this;
}

template <class T>
void ForwardList<T>::_copyElementsFrom(const ForwardList& source)
{
  Node* leftNeighbor = &_beforeHead;

  for (const auto& element : source)
  {
    leftNeighbor->next = _createElementNode(element);
    leftNeighbor = leftNeighbor->next;
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.