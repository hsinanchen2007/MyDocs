#ifndef DSS_SWAP_SWAP
#define DSS_SWAP_SWAP

namespace dss
{
template <typename T>
void swap(T& a, T& b);

template <typename T>
void swap(T& a, T& b)
{
  T c = a;
  a = b;
  b = c;
}
};

#endif // DSS_SWAP_SWAP

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.