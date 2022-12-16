namespace dss
{
template <class T>
void List<T>::pop_front()
{
  Node* newHead = _head->right;

  if (newHead != nullptr)
    newHead->left = nullptr;
  else
    _tail = nullptr;

  _destroyNode(_head);
  _head = newHead;
  --_size;
}

template <class T>
void List<T>::pop_back()
{
  Node* newTail = _tail->left;

  if (newTail != nullptr)
    newTail->right = nullptr;
  else
    _head = nullptr;

  _destroyNode(_tail);
  _tail = newTail;
  --_size;
}

template <class T>
void List<T>::clear()
{
  _destroyAllNodes();

  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.