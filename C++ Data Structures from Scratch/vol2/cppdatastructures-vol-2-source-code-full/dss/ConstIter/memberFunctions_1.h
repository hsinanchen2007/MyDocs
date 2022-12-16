namespace dss
{
template <class Container>
inline ConstIter<Container>::ConstIter()
{
  // ...
}

template <class Container>
inline ConstIter<Container>::ConstIter(const Iter& i) :
  _i(i)
{
  // ...
}

template <class Container>
inline bool ConstIter<Container>::operator==(const ConstIter& rhs) const
{
  return _i == rhs._i;
}

template <class Container>
inline bool ConstIter<Container>::operator!=(const ConstIter& rhs) const
{
  return _i != rhs._i;
}

template <class Container>
inline typename ConstIter<Container>::pointer
ConstIter<Container>::operator->() const
{
  return _i.operator->();
}

template <class Container>
inline typename ConstIter<Container>::reference
ConstIter<Container>::operator*() const
{
  return *_i;
}

template <class Container>
inline ConstIter<Container>& ConstIter<Container>::operator++()
{
  ++_i;

  return *this;
}

template <class Container>
inline ConstIter<Container>& ConstIter<Container>::operator--()
{
  --_i;

  return *this;
}

template <class Container>
inline ConstIter<Container> ConstIter<Container>::operator++(int n)
{
  return _i++;
}

template <class Container>
inline ConstIter<Container> ConstIter<Container>::operator--(int n)
{
  return _i--;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.