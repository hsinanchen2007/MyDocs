namespace ds2
{
template<class T>
inline ForwardListSize<T>::ForwardListSize():
  _size(0)
{
  // ...
}

template<class T>
inline bool ForwardListSize<T>::empty() const
{
  return _list.empty();
}

template <class T>
inline typename ForwardListSize<T>::size_type ForwardListSize<T>::size() const
{
  return _size;
}

template <class T>
inline typename ForwardListSize<T>::const_iterator
ForwardListSize<T>::before_begin() const
{
  return _list.before_begin();
}

template <class T>
inline typename ForwardListSize<T>::const_iterator ForwardListSize<T>::begin() const
{
  return _list.begin();
}

template <class T>
inline typename ForwardListSize<T>::const_iterator ForwardListSize<T>::end() const
{
  return _list.end();
}

template<class T>
inline typename ForwardListSize<T>::const_reference ForwardListSize<T>::front() const
{
  return _list.front();
}

template <class T>
inline typename ForwardListSize<T>::iterator ForwardListSize<T>::before_begin()
{
  return _list.before_begin();
}

template <class T>
inline typename ForwardListSize<T>::iterator ForwardListSize<T>::begin()
{
  return _list.begin();
}

template <class T>
inline typename ForwardListSize<T>::iterator ForwardListSize<T>::end()
{
  return _list.end();
}

template<class T>
inline typename ForwardListSize<T>::reference ForwardListSize<T>::front()
{
  return _list.front();
}

template <class T>
inline typename ForwardListSize<T>::iterator ForwardListSize<T>::insert_after(
  const_iterator insertionPoint, const T& newElement)
{
  ++_size;

  return _list.insert_after(insertionPoint, newElement);
}

template <class T>
inline typename ForwardListSize<T>::iterator ForwardListSize<T>::erase_after(
  const_iterator erasurePoint)
{
  --_size;

  return _list.erase_after(erasurePoint);
}

template<class T>
inline void ForwardListSize<T>::push_front(const T& newElement)
{
  _list.push_front(newElement);
  ++_size;
}

template <class T>
inline void ForwardListSize<T>::pop_front()
{
  _list.pop_front();
  --_size;
}

template <class T>
inline void ForwardListSize<T>::clear()
{
  _list.clear();
  _size = 0;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.