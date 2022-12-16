namespace dss
{
template <class Iter>
inline bool ReverseIter<Iter>::operator>=(const ReverseIter& rhs) const
{
  return _i <= rhs._i;
}

template <class Iter>
inline bool ReverseIter<Iter>::operator<=(const ReverseIter& rhs) const
{
  return _i >= rhs._i;
}

template <class Iter>
inline bool ReverseIter<Iter>::operator>(const ReverseIter& rhs) const
{
  return _i < rhs._i;
}

template <class Iter>
inline bool ReverseIter<Iter>::operator<(const ReverseIter& rhs) const
{
  return _i > rhs._i;
}

template <class Iter>
inline typename ReverseIter<Iter>::reference ReverseIter<Iter>::operator[](
  difference_type offset) const
{
  return _i[-offset - 1];
}

template <class Iter>
inline ReverseIter<Iter> ReverseIter<Iter>::operator+(
  difference_type offset) const
{
  return ReverseIter(_i - offset);
}

template <class Iter>
inline ReverseIter<Iter> ReverseIter<Iter>::operator-(
  difference_type offset) const
{
  return ReverseIter(_i + offset);
}

template <class Iter>
inline typename ReverseIter<Iter>::difference_type
ReverseIter<Iter>::operator-(const ReverseIter& rhs) const
{
  return rhs._i - _i;
}

template <class Iter>
inline ReverseIter<Iter>& ReverseIter<Iter>::operator+=(difference_type offset)
{
  _i -= offset;

  return *this;
}

template <class Iter>
inline ReverseIter<Iter>& ReverseIter<Iter>::operator-=(difference_type offset)
{
  _i += offset;

  return *this;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.