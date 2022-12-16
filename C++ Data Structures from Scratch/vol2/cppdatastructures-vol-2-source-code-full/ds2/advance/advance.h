#ifndef DS2_ADVANCE_ADVANCE
#define DS2_ADVANCE_ADVANCE

#include <iterator>

namespace ds2
{
template <class Iter, class Distance>
void advance(Iter& iter, Distance distance);

template <class Iter, class Distance>
void _advance(Iter& iter,
  Distance distance,
  std::input_iterator_tag iteratorTag);

template <class Iter, class Distance>
void _advance(Iter& iter,
  Distance distance,
  std::random_access_iterator_tag iteratorTag);

template <class Iter, class Distance>
inline void advance(Iter& iter, Distance distance)
{
  _advance(iter,
    distance,
    std::iterator_traits<Iter>::iterator_category());
}

template <class Iter, class Distance>
void _advance(Iter& iter,
  Distance distance,
  std::input_iterator_tag iteratorTag)
{
  for (Distance d = 0; d != distance; ++d)
    ++iter;
}

template <class Iter, class Distance>
inline void _advance(Iter& iter,
  Distance distance,
  std::random_access_iterator_tag iteratorTag)
{
  iter += distance;
}
};

#endif // DS2_ADVANCE_ADVANCE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.