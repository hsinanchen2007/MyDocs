namespace dss
{
template <class T>
MultiRing<T>::MultiRing(const MultiRing& source):
  _size(0)
{
  _pages.reserve(source._pages.capacity());

  for (const_iterator sourceElement = source.begin();
    sourceElement != source.end();
    ++sourceElement)
  {
    push_back(*sourceElement);
  }
}

template <class T>
MultiRing<T>& MultiRing<T>::operator=(const MultiRing& rhs)
{
  if (size() >= rhs.size())
  {
    while (size() != rhs.size())
      pop_back();

    for (size_type i = 0; i != size(); ++i)
      (*this)[i] = rhs[i];
  }
  else
  {
    for (size_type i = 0; i != size(); ++i)
      (*this)[i] = rhs[i];

    for (size_type i = size(); i != rhs.size(); ++i)
      push_back(rhs[i]);
  }

  return *this;
}

template <class T>
typename MultiRing<T>::iterator MultiRing<T>::insert(
  const_iterator insertionPoint,
  const T& source)
{
  size_type insertionDistance = insertionPoint - begin();
  const_iterator midpoint = begin() + size() / 2;

  if (insertionPoint < midpoint)
  {
    push_front(source);

    for (iterator n = begin(); n != begin() + insertionDistance; ++n)
      swap(*n, *(n + 1));
  }
  else
  {
    push_back(source);

    for (iterator n = end() - 1; n != begin() + insertionDistance; --n)
      swap(*n, *(n - 1));
  }

  return iterator(this, insertionDistance);
}

template <class T>
typename MultiRing<T>::iterator MultiRing<T>::erase(const_iterator erasurePoint)
{
  size_type erasureDistance = erasurePoint - begin();
  const_iterator midpoint = begin() + size() / 2;

  if (erasurePoint < midpoint)
  {
    for (iterator n = begin() + erasureDistance; n != begin(); --n)
      *n = *(n - 1);

    pop_front();
  }
  else
  {
    for (iterator n = begin() + erasureDistance; n != end() - 1; ++n)
      *n = *(n + 1);

    pop_back();
  }

  return iterator(this, erasureDistance);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.