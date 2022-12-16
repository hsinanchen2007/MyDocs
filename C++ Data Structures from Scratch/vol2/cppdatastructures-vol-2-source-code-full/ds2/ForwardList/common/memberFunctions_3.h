namespace ds2
{
template <class T>
inline typename ForwardList<T>::const_iterator
ForwardList<T>::before_begin() const
{
  return &_beforeHead;
}

template <class T>
inline typename ForwardList<T>::const_iterator ForwardList<T>::begin() const
{
  return _beforeHead.next;
}

template <class T>
inline typename ForwardList<T>::const_iterator ForwardList<T>::end() const
{
  return nullptr;
}

template <class T>
inline typename ForwardList<T>::iterator ForwardList<T>::before_begin()
{
  return &_beforeHead;
}

template <class T>
inline typename ForwardList<T>::iterator ForwardList<T>::begin()
{
  return _beforeHead.next;
}

template <class T>
inline typename ForwardList<T>::iterator ForwardList<T>::end()
{
  return nullptr;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.