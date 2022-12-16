#include <iostream>

#include "dss/distance/distance.h"
#include "dss/List/7/List.h"
#include "dss/Ring/5/Ring.h"

int main()
{
  using namespace std;
  using namespace dss;

  Ring<int> r;
  List<int> t;

  for (int i = 0; i != 5; ++i)
  {
    r.push_back(i);
    t.push_back(i);
  }

  cout << "r contains " << dss::distance(r.begin(), r.end()) << " elements\n";
  cout << "t contains " << dss::distance(t.begin(), t.end()) << " elements";

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.