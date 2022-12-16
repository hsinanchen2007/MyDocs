#ifndef DSS_REVERSEITER_REVERSEITER
#define DSS_REVERSEITER_REVERSEITER

#include <iterator>

namespace dss
{
template <class Iter>
class ReverseIter;

template <class Iter>
ReverseIter<Iter> operator+(typename ReverseIter<Iter>::difference_type lhs,
  const ReverseIter<Iter>& rhs);

template <class Iter>
class ReverseIter
{
 public:
  typedef typename std::iterator_traits<Iter>::difference_type difference_type;
  typedef typename std::iterator_traits<Iter>::pointer pointer;
  typedef typename std::iterator_traits<Iter>::reference reference;
  typedef typename std::iterator_traits<Iter>::value_type value_type;
  typedef typename std::iterator_traits<Iter>::iterator_category
    iterator_category;

  ReverseIter();
  explicit ReverseIter(const Iter& i);

  template <class OtherIter>
  ReverseIter(const ReverseIter<OtherIter>& source);

  Iter base() const;
  bool operator==(const ReverseIter& rhs) const;
  bool operator!=(const ReverseIter& rhs) const;
  bool operator>=(const ReverseIter& rhs) const;
  bool operator<=(const ReverseIter& rhs) const;
  bool operator>(const ReverseIter& rhs) const;
  bool operator<(const ReverseIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;
  reference operator[](difference_type offset) const;
  ReverseIter operator+(difference_type offset) const;
  ReverseIter operator-(difference_type offset) const;
  difference_type operator-(const ReverseIter& rhs) const;

  ReverseIter& operator++();
  ReverseIter& operator--();
  ReverseIter operator++(int n);
  ReverseIter operator--(int n);
  ReverseIter& operator+=(difference_type offset);
  ReverseIter& operator-=(difference_type offset);

 private:
  Iter _i;
};
};

#include "dss/ReverseIter/memberFunctions_1.h"
#include "dss/ReverseIter/memberFunctions_2.h"
#include "dss/ReverseIter/nonMemberFunctions.h"

#endif // DSS_REVERSEITER_REVERSEITER

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.