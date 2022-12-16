namespace dss
{
template <class Iter>
inline ConstIter<Iter> operator+(typename ConstIter<Iter>::difference_type lhs,
  const ConstIter<Iter>& rhs)
{
  return rhs + lhs;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.