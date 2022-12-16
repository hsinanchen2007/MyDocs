#include <iostream>

#include "dss/MultiRing/3/MultiRing.h"
#include "dss/printContainer/printContainer.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef MultiRing<Traceable<int>> MultiRing;

  MultiRing x;
  MultiRing y;

  for (int i = 0; i != 12; ++i)
  {
    x.push_back(i);
    y.push_front(i);
  }

  cout << "\nx contains the elements:\n";
  printContainer(x);

  cout << "\ny contains the elements:\n";
  printContainer(y);

  cout << endl;

  while (!x.empty())
    x.pop_back();

  cout << endl;

  while (!y.empty())
    y.pop_front();

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.