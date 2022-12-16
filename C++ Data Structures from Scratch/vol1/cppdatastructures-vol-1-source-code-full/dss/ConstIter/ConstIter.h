#ifndef DSS_CONSTITER_CONSTITER
#define DSS_CONSTITER_CONSTITER

#include <iterator>

namespace dss
{
template <class Container>
class ConstIter;

template <class Container>
ConstIter<Container> operator+(
  typename ConstIter<Container>::difference_type lhs,
  const ConstIter<Container>& rhs);

template <class Container>
class ConstIter
{
 public:
  friend Container;
  typedef typename Container::iterator Iter;

  ConstIter();
  ConstIter(const Iter& i);

  typedef typename std::iterator_traits<Iter>::value_type value_type;
  typedef typename std::iterator_traits<Iter>::difference_type difference_type;

  typedef typename std::iterator_traits<Iter>::iterator_category
    iterator_category;

  typedef typename Container::const_pointer pointer;
  typedef typename Container::const_reference reference;

  bool operator==(const ConstIter& rhs) const;
  bool operator!=(const ConstIter& rhs) const;
  bool operator>=(const ConstIter& rhs) const;
  bool operator<=(const ConstIter& rhs) const;
  bool operator>(const ConstIter& rhs) const;
  bool operator<(const ConstIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;
  reference operator[](difference_type offset) const;
  ConstIter operator+(difference_type offset) const;
  ConstIter operator-(difference_type offset) const;
  difference_type operator-(const ConstIter& rhs) const;

  ConstIter& operator++();
  ConstIter& operator--();
  ConstIter operator++(int n);
  ConstIter operator--(int n);
  ConstIter& operator+=(difference_type offset);
  ConstIter& operator-=(difference_type offset);

 private:
  Iter _i;
};
};

#include "dss/ConstIter/memberFunctions_1.h"
#include "dss/ConstIter/memberFunctions_2.h"
#include "dss/ConstIter/nonMemberFunctions.h"

#endif // DSS_CONSTITER_CONSTITER

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.