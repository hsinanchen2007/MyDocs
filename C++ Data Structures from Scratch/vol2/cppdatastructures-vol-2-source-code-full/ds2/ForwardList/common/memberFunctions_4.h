namespace ds2
{
template <class T>
typename ForwardList<T>::iterator ForwardList<T>::insert_after(
  const_iterator insertionPoint, const T& newElement)
{
  ElementNode* newNode = _createElementNode(newElement);
  Node* _insertionPoint = insertionPoint._i._n;

  newNode->next = _insertionPoint->next;
  _insertionPoint->next = newNode;

  return newNode;
}

template <class T>
typename ForwardList<T>::iterator ForwardList<T>::erase_after(
  const_iterator erasurePoint)
{
  Node* _erasurePoint = erasurePoint._i._n;
  ElementNode* trash = _downcast(_erasurePoint->next);

  _erasurePoint->next = trash->next;
  _destroyElementNode(trash);

  return _erasurePoint->next;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.