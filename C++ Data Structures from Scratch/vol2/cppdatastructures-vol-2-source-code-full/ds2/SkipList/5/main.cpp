#include <iostream>

#include "ds2/printSkipList/printSkipList.h"
#include "ds2/SkipList/5/SkipList.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef SkipList<Traceable<int>, int> SkipList;

  SkipList x;

  for (int i = 1; i != 10; ++i)
    x.insert(std::make_pair(i, 0));

  SkipList y(x);

  SkipList z;

  for (int i = 10; i != 16; ++i)
    z.insert(make_pair(i, 0));

  z = x;

  printSkipList(x);
  printAvailableNodes(x);

  printSkipList(y);
  printAvailableNodes(y);

  printSkipList(z);
  printAvailableNodes(z);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.