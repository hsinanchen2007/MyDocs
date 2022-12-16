#include <iostream>

#include "dss/Allocator/Allocator.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef Allocator<Traceable<int>> Allocator;
  typedef Allocator::pointer Pointer;

  Allocator::size_type totalObjects;
  cout << "\nEnter number of objects to create: ";
  cin >> totalObjects;

  Allocator allocator;

  cout << "\nAllocating memory block for " << totalObjects << " objects...\n";
  Pointer a = allocator.allocate(totalObjects);

  cout << "\nConstructing objects...\n\n";
  for (Pointer p = a; p != a + totalObjects; ++p)
    allocator.construct(p, Allocator::value_type());

  for (Pointer p = a; p != a + totalObjects; ++p)
  {
    cout << "\nEnter an integer value: ";
    cin >> *p;
  }

  cout << "\nYou entered:\n";
  printSequence(a, a + totalObjects);

  cout << "\n\nDestroying objects...\n\n";
  for (Pointer p = a; p != a + totalObjects; ++p)
    allocator.destroy(p);

  cout << "\nDeallocating memory block...\n";
  allocator.deallocate(a);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.