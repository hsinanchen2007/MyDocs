namespace ds2
{
template<class T>
inline ForwardList<T>::ForwardList()
{
  // ...
}

template<class T>
inline ForwardList<T>::~ForwardList()
{
  _destroyAllElementNodes();
}

template<class T>
inline bool ForwardList<T>::empty() const
{
  return _beforeHead.next == nullptr;
}

template<class T>
inline typename ForwardList<T>::const_reference ForwardList<T>::front() const
{
  return const_cast<ForwardList*>(this)->front();
}

template<class T>
inline typename ForwardList<T>::reference ForwardList<T>::front()
{
  return _downcast(_beforeHead.next)->element;
}

template<class T>
void ForwardList<T>::push_front(const T& newElement)
{
  ElementNode* newNode = _createElementNode(newElement);

  newNode->next = _beforeHead.next;
  _beforeHead.next = newNode;
}

template <class T>
inline typename ForwardList<T>::ElementNode* ForwardList<T>::_downcast(
  Node* n) const
{
  return static_cast<ElementNode*>(n);
}

template<class T>
typename ForwardList<T>::ElementNode* ForwardList<T>::_createElementNode(
  const T& newElement)
{
  ElementNode* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, ElementNode(newElement));

  return newNode;
}

template<class T>
inline void ForwardList<T>::_destroyElementNode(ElementNode* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n, 1);
}

template<class T>
void ForwardList<T>::_destroyAllElementNodes()
{
  ElementNode* n = _downcast(_beforeHead.next);

  while (n != nullptr)
  {
    ElementNode* next = _downcast(n->next);
    _destroyElementNode(n);
    n = next;
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.