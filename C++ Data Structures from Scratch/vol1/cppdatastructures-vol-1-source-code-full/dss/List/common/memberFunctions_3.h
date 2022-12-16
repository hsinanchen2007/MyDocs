namespace dss
{
template <class T>
inline typename List<T>::iterator List<T>::begin()
{
  return iterator(this, _head);
}

template <class T>
inline typename List<T>::iterator List<T>::end()
{
  return iterator(this, nullptr);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.