#include <iostream>

#include "dss/Ring/1/Ring.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  Ring<Traceable<int>> r;

  for (int i = 0; i != 9; ++i)
  {
    r.push_back(i);
    cout << endl;
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.