#include <deque>
#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/KmPair/KmPair.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  typedef KmPair<Traceable<int>, int> KmPair;
  typedef KmPair::StdPair StdPair;

  deque<KmPair> kmPairs;

  for (int i = 4; i <= 6; ++i)
    kmPairs.push_back(StdPair(i, 0));

  for (int i = 2; i >= 0; --i)
    kmPairs.push_front(StdPair(i, 0));

  cout << endl;

  printContainer(kmPairs);
  cout << endl;

  kmPairs.insert(kmPairs.begin() + 3, StdPair(3, 0));
  cout << endl;

  printContainer(kmPairs);
  cout << endl;

  kmPairs.erase(kmPairs.begin() + 3);
  cout << endl;

  printContainer(kmPairs);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.