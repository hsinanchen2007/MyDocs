namespace dss
{
template <class T>
inline typename MultiRing<T>::const_iterator MultiRing<T>::begin() const
{
  return const_cast<MultiRing*>(this)->begin();
}

template <class T>
inline typename MultiRing<T>::const_iterator MultiRing<T>::end() const
{
  return const_cast<MultiRing*>(this)->end();
}

template <class T>
inline typename MultiRing<T>::const_reverse_iterator
MultiRing<T>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class T>
inline typename MultiRing<T>::const_reverse_iterator MultiRing<T>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class T>
inline typename MultiRing<T>::iterator MultiRing<T>::begin()
{
  return iterator(this, 0);
}

template <class T>
inline typename MultiRing<T>::iterator MultiRing<T>::end()
{
  return iterator(this, size());
}

template <class T>
inline typename MultiRing<T>::reverse_iterator MultiRing<T>::rbegin()
{
  return reverse_iterator(end());
}

template <class T>
inline typename MultiRing<T>::reverse_iterator MultiRing<T>::rend()
{
  return reverse_iterator(begin());
}

template <class T>
void MultiRing<T>::pop_front()
{
  _pages.front()->pop_front();

  if (_pages.front()->empty())
  {
    _destroyPage(_pages.front());
    _pages.pop_front();
  }

  --_size;
}

template <class T>
void MultiRing<T>::pop_back()
{
  _pages.back()->pop_back();

  if (_pages.back()->empty())
  {
    _destroyPage(_pages.back());
    _pages.pop_back();
  }

  --_size;
}

template <class T>
void MultiRing<T>::clear()
{
  _destroyAllPages();
  _pages.clear();
  _size = 0;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.