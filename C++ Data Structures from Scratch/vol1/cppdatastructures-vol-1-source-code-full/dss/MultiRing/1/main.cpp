#include <iostream>

#include "dss/MultiRing/1/MultiRing.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  MultiRing<Traceable<int>> m;

  for (int i = 0; i != 12; ++i)
    m.push_back(i);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.