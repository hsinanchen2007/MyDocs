#ifndef DSS_PRINTSEQUENCE_PRINTSEQUENCE
#define DSS_PRINTSEQUENCE_PRINTSEQUENCE

#include <iostream>

namespace dss
{
template <class Iter>
void printSequence(Iter begin, Iter end);

template <class Iter>
void printSequence(Iter begin, Iter end)
{
  while (begin != end)
  {
    std::cout << *begin << ' ';
    ++begin;
  }
}
};

#endif // DSS_PRINTSEQUENCE_PRINTSEQUENCE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.