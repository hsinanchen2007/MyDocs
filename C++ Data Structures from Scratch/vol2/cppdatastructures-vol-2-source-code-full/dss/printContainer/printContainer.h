#ifndef DSS_PRINTCONTAINER_PRINTCONTAINER
#define DSS_PRINTCONTAINER_PRINTCONTAINER

#include <iostream>

#include "dss/printSequence/printSequence.h"

namespace dss
{
template <class Container>
void printContainer(const Container& container);

template <class Container>
void printContainerReverse(const Container& container);

template <class Container>
inline void printContainer(const Container& container)
{
  printSequence(container.begin(), container.end());
  std::cout << std::endl;
}

template <class Container>
inline void printContainerReverse(const Container& container)
{
  printSequence(container.rbegin(), container.rend());
  std::cout << std::endl;
}
};

#endif // DSS_PRINTCONTAINER_PRINTCONTAINER

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.