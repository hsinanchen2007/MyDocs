namespace dss
{
template <class Iter>
inline bool ConstIter<Iter>::operator>=(const ConstIter& rhs) const
{
  return _i >= rhs._i;
}

template <class Iter>
inline bool ConstIter<Iter>::operator<=(const ConstIter& rhs) const
{
  return _i <= rhs._i;
}

template <class Iter>
inline bool ConstIter<Iter>::operator>(const ConstIter& rhs) const
{
  return _i > rhs._i;
}

template <class Iter>
inline bool ConstIter<Iter>::operator<(const ConstIter& rhs) const
{
  return _i < rhs._i;
}

template <class Iter>
inline typename ConstIter<Iter>::reference ConstIter<Iter>::operator[](
  difference_type offset) const
{
  return _i[offset];
}

template <class Iter>
inline ConstIter<Iter> ConstIter<Iter>::operator+(
  difference_type offset) const
{
  return ConstIter(_i + offset);
}

template <class Iter>
inline ConstIter<Iter> ConstIter<Iter>::operator-(
  difference_type offset) const
{
  return ConstIter(_i - offset);
}

template <class Iter>
inline typename ConstIter<Iter>::difference_type
ConstIter<Iter>::operator-(const ConstIter& rhs) const
{
  return _i - rhs._i;
}

template <class Iter>
inline ConstIter<Iter>& ConstIter<Iter>::operator+=(difference_type offset)
{
  _i += offset;

  return *this;
}

template <class Iter>
inline ConstIter<Iter>& ConstIter<Iter>::operator-=(difference_type offset)
{
  _i -= offset;

  return *this;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.