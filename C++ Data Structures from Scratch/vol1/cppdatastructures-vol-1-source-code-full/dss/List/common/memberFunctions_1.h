namespace dss
{
template <class T>
inline List<T>::List():
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  // ...
}

template <class T>
inline List<T>::~List()
{
  _destroyAllNodes();
}

template <class T>
inline bool List<T>::empty() const
{
  return _size == 0;
}

template <class T>
inline typename List<T>::size_type List<T>::size() const
{
  return _size;
}

template <class T>
inline typename List<T>::const_reference List<T>::front() const
{
  return _head->element;
}

template <class T>
inline typename List<T>::const_reference List<T>::back() const
{
  return _tail->element;
}

template <class T>
inline typename List<T>::reference List<T>::front()
{
  return _head->element;
}

template <class T>
inline typename List<T>::reference List<T>::back()
{
  return _tail->element;
}

template <class T>
void List<T>::push_front(const T& source)
{
  Node* newNode = _createNode(source);

  if (empty())
  {
    _head = newNode;
    _tail = newNode;
  }
  else
  {
    newNode->right = _head;

    _head->left = newNode;
    _head = newNode;
  }

  ++_size;
}

template <class T>
void List<T>::push_back(const T& source)
{
  Node* newNode = _createNode(source);

  if (empty())
  {
    _head = newNode;
    _tail = newNode;
  }
  else
  {
    newNode->left = _tail;

    _tail->right = newNode;
    _tail = newNode;
  }

  ++_size;
}

template <class T>
typename List<T>::Node* List<T>::_createNode(const T& source)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(source));

  return newNode;
}

template <class T>
inline void List<T>::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n);
}

template <class T>
void List<T>::_destroyAllNodes()
{
  Node* n = _head;
  Node* next;

  while (n != nullptr)
  {
    next = n->right;
    _destroyNode(n);
    n = next;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.