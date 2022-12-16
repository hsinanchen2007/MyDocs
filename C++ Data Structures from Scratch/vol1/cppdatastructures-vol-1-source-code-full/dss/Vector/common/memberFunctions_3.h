#include "dss/swap/swap.h"

namespace dss
{
template <class T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator insertionPoint,
  const T& source)
{
  size_type insertionDistance = insertionPoint - begin();

  push_back(source);

  iterator i = begin() + insertionDistance;

  for (iterator p = end() - 1; p != i; --p)
    swap(*p, *(p - 1));

  return i;
}

template <class T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator erasurePoint)
{
  size_type erasureDistance = erasurePoint - begin();

  for (iterator p = begin() + erasureDistance; p != end() - 1; ++p)
    *p = *(p + 1);

  pop_back();

  return begin() + erasureDistance;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.