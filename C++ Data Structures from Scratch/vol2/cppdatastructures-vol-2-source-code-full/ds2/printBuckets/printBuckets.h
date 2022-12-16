#include <iostream>

#include "dss/printSequence/printSequence.h"

namespace ds2
{
template <class HashTable>
void printBuckets(const HashTable& h);

template <class HashTable>
void printBuckets(const HashTable& h)
{
  using namespace std;

  cout << "Non-empty buckets (out of " << h.bucket_count() << " total):\n\n";

  for (HashTable::size_type i = 0; i != h.bucket_count(); ++i)
  {
    if (h.bucket_size(i) == 0)
      continue;

    cout << i << ": ";
    dss::printSequence(h.begin(i), h.end(i));
    cout << endl;
  }

  cout << endl;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.