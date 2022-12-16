namespace dss
{
template <class T, const unsigned int Size>
inline bool Array<T, Size>::empty() const
{
  return Size == 0;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::size_type Array<T, Size>::size() const
{
  return Size;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_iterator Array<T, Size>::begin() const
{
  return _a;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_iterator Array<T, Size>::end() const
{
  return _a + size();
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::front() const
{
  return *_a;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::back() const
{
  return *(_a + size() - 1);
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reference Array<T, Size>::operator[](
  size_type index) const
{
  return _a[index];
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::begin()
{
  return _a;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::iterator Array<T, Size>::end()
{
  return _a + size();
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reference Array<T, Size>::front()
{
  return *_a;
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reference Array<T, Size>::back()
{
  return *(_a + size() - 1);
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reference Array<T, Size>::operator[](
  size_type index)
{
  return _a[index];
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.