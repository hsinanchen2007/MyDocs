#include <deque>
#include <functional>
#include <iostream>

#include "ds2/KmPair/KmPair.h"
#include "ds2/KmPairBound/KmPairBound.h"
#include "ds2/stdPairIo/stdPairIo.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef KmPair<int, int> KmPair;
  typedef KmPair::StdPair StdPair;

  deque<KmPair> kmPairs;

  for (int i = 0; i != 20; ++i)
    kmPairs.push_back(StdPair(i, 0));

  deque<KmPair>::const_iterator i = kmPairLowerBound(kmPairs.begin(),
    kmPairs.end(),
    7,
    less<int>());

  cout << "lowerBound(key 7) = " << *i << endl;

  i = kmPairUpperBound(kmPairs.begin(),
    kmPairs.end(),
    7,
    less<int>());

  cout << "upperBound(key 7) = " << *i << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.