namespace dss
{
template <class Iter>
inline ReverseIter<Iter> operator+(
  typename ReverseIter<Iter>::difference_type lhs,
  const ReverseIter<Iter>& rhs)
{
  return rhs + lhs;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.