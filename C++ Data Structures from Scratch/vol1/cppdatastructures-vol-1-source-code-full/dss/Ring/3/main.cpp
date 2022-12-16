#include <iostream>

#include "dss/Ring/3/Ring.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  Ring<Traceable<int>> r;
  Ring<Traceable<int>> s;

  for (int i = 0; i != 9; ++i)
  {
    r.push_front(i);
    s.push_front(i);
  }

  cout << endl;

  while (!r.empty())
    r.pop_back();

  cout << endl;

  while (!s.empty())
    s.pop_front();

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.