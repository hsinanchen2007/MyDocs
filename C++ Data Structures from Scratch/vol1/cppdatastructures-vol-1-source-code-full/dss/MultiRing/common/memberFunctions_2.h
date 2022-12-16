namespace dss
{
template <class T>
inline typename MultiRing<T>::const_reference MultiRing<T>::operator[](
  size_type index) const
{
  return _element(index);
}

template <class T>
inline typename MultiRing<T>::reference MultiRing<T>::operator[](
  size_type index)
{
  return _element(index);
}

template <class T>
void MultiRing<T>::push_front(const T& source)
{
  if (empty() || _pages.front()->size() == _pages.front()->capacity())
    _pages.push_front(_createPage());

  _pages.front()->push_front(source);
  ++_size;
}

template <class T>
typename MultiRing<T>::reference MultiRing<T>::_element(size_type index) const
{
  if (index < _pages.front()->size())
  {
    return (*_pages.front())[index];
  }
  else
  {
    size_type offset = index - _pages.front()->size();
    size_type pageNumber = 1 + offset/_pageCapacity;
    size_type cellNumber = offset % _pageCapacity;

    return (*_pages[pageNumber])[cellNumber];
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.