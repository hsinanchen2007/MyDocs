#ifndef DSS_PAIR_PAIR
#define DSS_PAIR_PAIR

namespace dss
{
template <class A, class B>
struct Pair;

template <class A, class B>
Pair<A, B> makePair(const A& first, const B& second);

template <class A, class B>
struct Pair
{
  typedef A first_type;
  typedef B second_type;

  Pair();
  Pair(const A& _first, const B& _second);

  template <class X, class Y>
  Pair(const Pair<X, Y>& source);

  A first;
  B second;
};

template <class A, class B>
inline Pair<A, B> makePair(const A& first, const B& second)
{
  return Pair<A, B>(first, second);
}

template <class A, class B>
Pair<A, B>::Pair():
  first(A()),
  second(B())
{
  // ...
}

template <class A, class B>
Pair<A, B>::Pair(const A& _first, const B& _second):
  first(_first),
  second(_second)
{
  // ...
}

template <class A, class B>
template <class X, class Y>
inline Pair<A, B>::Pair(const Pair<X, Y>& source):
  first(source.first),
  second(source.second)
{
  // ...
}
};

#endif // DSS_PAIR_PAIR

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.