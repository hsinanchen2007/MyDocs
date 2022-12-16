namespace dss
{
template <class T>
inline typename List<T>::const_iterator List<T>::begin() const
{
  return const_cast<List*>(this)->begin();
}

template <class T>
inline typename List<T>::const_iterator List<T>::end() const
{
  return const_cast<List*>(this)->end();
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.