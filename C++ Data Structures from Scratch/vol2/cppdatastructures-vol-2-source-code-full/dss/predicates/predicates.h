#ifndef DSS_PREDICATES_PREDICATES
#define DSS_PREDICATES_PREDICATES

namespace dss
{
template <class T, class Predicate>
bool isReflexivelyEqual(const T& a, const T& b, Predicate predicate);

template <class T>
struct Less
{
  bool operator()(const T& a, const T& b) const;
};

template <class T>
struct Greater
{
  bool operator()(const T& a, const T& b) const;
};

template <class T, class Predicate>
inline bool isReflexivelyEqual(const T& a, const T& b, Predicate predicate)
{
  return !predicate(a, b) && !predicate(b, a);
}

template <class T>
inline bool Less<T>::operator()(const T& a, const T& b) const
{
  return a < b;
}

template <class T>
inline bool Greater<T>::operator()(const T& a, const T& b) const
{
  return a > b;
}
};

#endif // DSS_PREDICATES_PREDICATES

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.