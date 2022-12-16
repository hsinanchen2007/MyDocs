namespace dss
{
template <class T>
inline typename Ring<T>::const_iterator Ring<T>::begin() const
{
  return const_cast<Ring*>(this)->begin();
}

template <class T>
inline typename Ring<T>::const_iterator Ring<T>::end() const
{
  return const_cast<Ring*>(this)->end();
}

template <class T>
inline typename Ring<T>::const_reverse_iterator Ring<T>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class T>
inline typename Ring<T>::const_reverse_iterator Ring<T>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class T>
inline typename Ring<T>::iterator Ring<T>::begin()
{
  return iterator(this, 0);
}

template <class T>
inline typename Ring<T>::iterator Ring<T>::end()
{
  return iterator(this, size());
}

template <class T>
inline typename Ring<T>::reverse_iterator Ring<T>::rbegin()
{
  return reverse_iterator(end());
}

template <class T>
inline typename Ring<T>::reverse_iterator Ring<T>::rend()
{
  return reverse_iterator(begin());
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.