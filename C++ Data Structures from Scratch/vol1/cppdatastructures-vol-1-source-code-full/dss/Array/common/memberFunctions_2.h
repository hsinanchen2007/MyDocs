namespace dss
{
template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reverse_iterator
Array<T, Size>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::const_reverse_iterator
Array<T, Size>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reverse_iterator Array<T, Size>::rbegin()
{
  return reverse_iterator(end());
}

template <class T, const unsigned int Size>
inline typename Array<T, Size>::reverse_iterator Array<T, Size>::rend()
{
  return reverse_iterator(begin());
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.