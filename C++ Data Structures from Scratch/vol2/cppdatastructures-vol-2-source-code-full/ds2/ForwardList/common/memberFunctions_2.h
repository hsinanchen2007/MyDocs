namespace ds2
{
template <class T>
void ForwardList<T>::pop_front()
{
  ElementNode* head = _downcast(_beforeHead.next);

  _beforeHead.next = head->next;
  _destroyElementNode(head);
}

template <class T>
inline void ForwardList<T>::clear()
{
  _destroyAllElementNodes();
  _beforeHead.next = nullptr;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.