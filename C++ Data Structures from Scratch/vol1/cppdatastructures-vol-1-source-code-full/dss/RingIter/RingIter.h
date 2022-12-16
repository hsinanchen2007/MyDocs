#ifndef DSS_RINGITER_RINGITER
#define DSS_RINGITER_RINGITER

#include <iterator>

namespace dss
{
template <class Ring>
class RingIter;

template <class Ring>
RingIter<Ring> operator+(typename RingIter<Ring>::difference_type lhs,
  const RingIter<Ring>& rhs);

template <class Ring>
class RingIter
{
 public:
  friend Ring;

  typedef typename Ring::pointer pointer;
  typedef typename Ring::reference reference;
  typedef typename Ring::difference_type difference_type;
  typedef typename Ring::value_type value_type;
  typedef std::random_access_iterator_tag iterator_category;

  RingIter();

  bool operator==(const RingIter& rhs) const;
  bool operator!=(const RingIter& rhs) const;
  bool operator>(const RingIter& rhs) const;
  bool operator<(const RingIter& rhs) const;
  bool operator>=(const RingIter& rhs) const;
  bool operator<=(const RingIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;
  reference operator[](difference_type offset) const;
  RingIter operator+(difference_type offset) const;
  RingIter operator-(difference_type offset) const;
  difference_type operator-(const RingIter& rhs) const;

  RingIter& operator++();
  RingIter& operator--();
  RingIter operator++(int n);
  RingIter operator--(int n);
  RingIter& operator+=(difference_type offset);
  RingIter& operator-=(difference_type offset);

 private:
  RingIter(const Ring* ring, int index);

  const Ring* _ring;
  int _index;
};

template <class Ring>
inline RingIter<Ring> operator+(typename RingIter<Ring>::difference_type lhs,
  const RingIter<Ring>& rhs)
{
  return rhs + lhs;
}

template <class Ring>
inline RingIter<Ring>::RingIter()
{
  // ...
}

template <class Ring>
inline bool RingIter<Ring>::operator==(const RingIter& rhs) const
{
  return _index == rhs._index;
}

template <class Ring>
inline bool RingIter<Ring>::operator!=(const RingIter& rhs) const
{
  return _index != rhs._index;
}

template <class Ring>
inline bool RingIter<Ring>::operator>(const RingIter& rhs) const
{
  return _index > rhs._index;
}

template <class Ring>
inline bool RingIter<Ring>::operator<(const RingIter& rhs) const
{
  return _index < rhs._index;
}

template <class Ring>
inline bool RingIter<Ring>::operator>=(const RingIter& rhs) const
{
  return _index >= rhs._index;
}

template <class Ring>
inline bool RingIter<Ring>::operator<=(const RingIter& rhs) const
{
  return _index <= rhs._index;
}

template <class Ring>
inline typename RingIter<Ring>::pointer RingIter<Ring>::operator->() const
{
  return &_ring->_element(_index);
}

template <class Ring>
inline typename RingIter<Ring>::reference RingIter<Ring>::operator*() const
{
  return _ring->_element(_index);
}

template <class Ring>
inline typename RingIter<Ring>::reference RingIter<Ring>::operator[](
  difference_type offset) const
{
  return _ring->_element(_index + offset);
}

template <class Ring>
inline RingIter<Ring> RingIter<Ring>::operator+(difference_type offset) const
{
  return RingIter(_ring, _index + offset);
}

template <class Ring>
inline RingIter<Ring> RingIter<Ring>::operator-(difference_type offset) const
{
  return RingIter(_ring, _index - offset);
}

template <class Ring>
inline typename RingIter<Ring>::difference_type RingIter<Ring>::operator-(
  const RingIter& rhs) const
{
  return _index - rhs._index;
}

template <class Ring>
inline RingIter<Ring>& RingIter<Ring>::operator++()
{
  ++_index;

  return *this;
}

template <class Ring>
inline RingIter<Ring>& RingIter<Ring>::operator--()
{
  --_index;

  return *this;
}

template <class Ring>
inline RingIter<Ring> RingIter<Ring>::operator++(int n)
{
  RingIter iterToCurrentElement(*this);

  ++_index;

  return iterToCurrentElement;
}

template <class Ring>
inline RingIter<Ring> RingIter<Ring>::operator--(int n)
{
  RingIter iterToCurrentElement(*this);

  --_index;

  return iterToCurrentElement;
}

template <class Ring>
inline RingIter<Ring>& RingIter<Ring>::operator+=(difference_type offset)
{
  _index += offset;

  return *this;
}

template <class Ring>
inline RingIter<Ring>& RingIter<Ring>::operator-=(difference_type offset)
{
  _index -= offset;

  return *this;
}

template <class Ring>
inline RingIter<Ring>::RingIter(const Ring* ring, int index):
  _ring(ring),
  _index(index)
{
  // ...
}
};

#endif // DSS_RINGITER_RINGITER

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.