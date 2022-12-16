namespace dss
{
template <class Iter>
inline ReverseIter<Iter>::ReverseIter()
{
  // ...
}

template <class Iter>
inline ReverseIter<Iter>::ReverseIter(const Iter& i) :
  _i(i)
{
  // ...
}

template <class Iter>
template <class OtherIter>
inline ReverseIter<Iter>::ReverseIter(const ReverseIter<OtherIter>& source):
  _i(source.base())
{
  // ...
}

template <class Iter>
inline Iter ReverseIter<Iter>::base() const
{
  return _i;
}

template <class Iter>
inline bool ReverseIter<Iter>::operator==(const ReverseIter& rhs) const
{
  return _i == rhs._i;
}

template <class Iter>
inline bool ReverseIter<Iter>::operator!=(const ReverseIter& rhs) const
{
  return _i != rhs._i;
}

template <class Iter>
inline typename ReverseIter<Iter>::pointer
ReverseIter<Iter>::operator->() const
{
  Iter temp = _i;
  --temp;

  return &(*temp);
}

template <class Iter>
inline typename ReverseIter<Iter>::reference
ReverseIter<Iter>::operator*() const
{
  Iter temp = _i;
  --temp;

  return *temp;
}

template <class Iter>
inline ReverseIter<Iter>& ReverseIter<Iter>::operator++()
{
  --_i;

  return *this;
}

template <class Iter>
inline ReverseIter<Iter>& ReverseIter<Iter>::operator--()
{
  ++_i;

  return *this;
}

template <class Iter>
inline ReverseIter<Iter> ReverseIter<Iter>::operator++(int n)
{
  return _i--;
}

template <class Iter>
inline ReverseIter<Iter> ReverseIter<Iter>::operator--(int n)
{
  return _i++;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.