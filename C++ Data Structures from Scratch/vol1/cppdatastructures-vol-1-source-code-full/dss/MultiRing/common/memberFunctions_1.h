namespace dss
{
template <class T>
MultiRing<T>::MultiRing():
  _size(0)
{
  // ...
}

template <class T>
inline MultiRing<T>::~MultiRing()
{
  _destroyAllPages();
}

template <class T>
inline bool MultiRing<T>::empty() const
{
  return _size == 0;
}

template <class T>
inline typename MultiRing<T>::size_type MultiRing<T>::size() const
{
  return _size;
}

template <class T>
inline typename MultiRing<T>::const_reference MultiRing<T>::front() const
{
  return _pages.front()->front();
}

template <class T>
inline typename MultiRing<T>::const_reference MultiRing<T>::back() const
{
  return _pages.back()->back();
}

template <class T>
inline typename MultiRing<T>::reference MultiRing<T>::front()
{
  return _pages.front()->front();
}

template <class T>
inline typename MultiRing<T>::reference MultiRing<T>::back()
{
  return _pages.back()->back();
}

template <class T>
void MultiRing<T>::push_back(const T& source)
{
  if (empty() || _pages.back()->size() == _pages.back()->capacity())
    _pages.push_back(_createPage());

  _pages.back()->push_back(source);
  ++_size;
}

template <class T>
typename MultiRing<T>::Page* MultiRing<T>::_createPage()
{
  Page* newPage = _alloc.allocate(1);
  _alloc.construct(newPage, Page());

  newPage->reserve(_pageCapacity);

  return newPage;
}

template <class T>
inline void MultiRing<T>::_destroyPage(Page* p)
{
  _alloc.destroy(p);
  _alloc.deallocate(p);
}

template <class T>
void MultiRing<T>::_destroyAllPages()
{
  for (Ring<Page*>::iterator p = _pages.begin(); p != _pages.end(); ++p)
    _destroyPage(*p);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.