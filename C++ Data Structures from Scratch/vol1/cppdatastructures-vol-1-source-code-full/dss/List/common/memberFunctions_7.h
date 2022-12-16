namespace dss
{
template <class T>
inline typename List<T>::const_reverse_iterator List<T>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class T>
inline typename List<T>::const_reverse_iterator List<T>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class T>
inline typename List<T>::reverse_iterator List<T>::rbegin()
{
  return reverse_iterator(end());
}

template <class T>
inline typename List<T>::reverse_iterator List<T>::rend()
{
  return reverse_iterator(begin());
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.