#ifndef DSS_DISTANCE_DISTANCE
#define DSS_DISTANCE_DISTANCE

#include <iterator>

namespace dss
{
template <class Iter>
typename std::iterator_traits<Iter>::difference_type distance(Iter begin,
  Iter end);

template <class Iter>
typename std::iterator_traits<Iter>::difference_type _distance(Iter begin,
  Iter end,
  std::bidirectional_iterator_tag iteratorTag);

template <class Iter>
typename std::iterator_traits<Iter>::difference_type _distance(Iter begin,
  Iter end,
  std::random_access_iterator_tag iteratorTag);

template <class Iter>
inline typename std::iterator_traits<Iter>::difference_type distance(Iter begin,
  Iter end)
{
  return _distance(begin,
    end,
    std::iterator_traits<Iter>::iterator_category());
}

template <class Iter>
typename std::iterator_traits<Iter>::difference_type _distance(Iter begin,
  Iter end,
  std::bidirectional_iterator_tag iteratorTag)
{
  typename std::iterator_traits<Iter>::difference_type totalElements = 0;

  while (begin != end)
  {
    ++totalElements;
    ++begin;
  }

  return totalElements;
}

template <class Iter>
typename std::iterator_traits<Iter>::difference_type _distance(Iter begin,
  Iter end,
  std::random_access_iterator_tag iteratorTag)
{
  return end - begin;
}
};

#endif // DSS_DISTANCE_DISTANCE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.