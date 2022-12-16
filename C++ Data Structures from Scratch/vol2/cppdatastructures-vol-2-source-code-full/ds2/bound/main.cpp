#include <iostream>
#include <list>
#include <vector>

#include "ds2/bound/bound.h"

int main()
{
  using namespace std;
  using namespace ds2;

  list<int> s;
  vector<int> v;

  for (int i = 1; i != 17; ++i)
  {
    s.push_back(i);
    v.push_back(i);
  }

  list<int>::const_iterator sBound;
  vector<int>::const_iterator vBound;

  sBound = lowerBound(s.begin(), s.end(), 12);
  vBound = upperBound(v.begin(), v.end(), 12);

  cout << "lowerBound(12) = " << *sBound << endl;
  cout << "upperBound(12) = " << *vBound << endl;

  sBound = lowerBound(s.begin(), s.end(), 0);
  vBound = upperBound(v.begin(), v.end(), 16);

  cout << "lowerBound(0) = " << *sBound << endl;

  if (vBound == v.end())
    cout << "upperBound(16) = end\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.