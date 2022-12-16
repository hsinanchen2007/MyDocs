#ifndef DS2_BOUND_UPPERBOUNDPREDICATE
#define DS2_BOUND_UPPERBOUNDPREDICATE

namespace ds2
{
template <class LessThan>
class UpperBoundPredicate
{
 public:
  typedef typename LessThan::first_argument_type first_argument_type;
  typedef typename LessThan::second_argument_type second_argument_type;

  UpperBoundPredicate();
  UpperBoundPredicate(LessThan isLess);

  bool operator()(const first_argument_type& midpoint,
    const second_argument_type& value) const;

 private:
  LessThan _isLess;
};

template <class LessThan>
inline UpperBoundPredicate<LessThan>::UpperBoundPredicate()
{
  // ...
}

template <class LessThan>
inline UpperBoundPredicate<LessThan>::UpperBoundPredicate(LessThan isLess):
  _isLess(isLess)
{
  // ...
}

template <class LessThan>
inline bool UpperBoundPredicate<LessThan>::operator()(
  const first_argument_type& midpoint,
  const second_argument_type& value) const
{
  return !_isLess(value, midpoint);
}
};

#endif // DS2_BOUND_UPPERBOUNDPREDICATE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.