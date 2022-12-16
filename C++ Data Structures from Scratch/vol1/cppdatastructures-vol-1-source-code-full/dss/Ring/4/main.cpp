#include <iostream>

#include "dss/Ring/4/Ring.h"

int main()
{
  using namespace std;
  using namespace dss;

  Ring<int> r;

  for (int i = 0; i != 10; ++i)
    r.push_back(i);

  cout << "\nr contains " << r.end() - r.begin() << " elements:\n";

  Ring<int>::const_iterator i = r.begin();

  for (int offset = 0; offset != r.size(); ++offset)
    cout << i[offset] << ' ';
  cout << endl;

  cout << "The 3rd element is " << *(i + 2) << endl;
  cout << "The 4th element is " << *(3 + i) << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.