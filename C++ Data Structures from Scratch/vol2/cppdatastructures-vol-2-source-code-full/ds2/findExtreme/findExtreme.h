#ifndef DS2_FINDEXTREME_FINDEXTREME
#define DS2_FINDEXTREME_FINDEXTREME

namespace ds2
{
template <class Iter, class Predicate>
Iter findExtreme(Iter begin, Iter end, Predicate predicate);

template <class Iter, class Predicate>
Iter findExtreme(Iter begin, Iter end, Predicate predicate)
{
  Iter extreme = begin;

  for (Iter current = ++begin; current != end; ++current)
    if (predicate(*current, *extreme))
      extreme = current;

  return extreme;
}
};

#endif // DS2_FINDEXTREME_FINDEXTREME

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.