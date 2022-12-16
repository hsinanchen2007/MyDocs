#include <iostream>

#include "dss/Vector/4/Vector.h"

int main()
{
  using namespace std;
  using namespace dss;

  Vector<int> v;

  for (int i = 0; i != 10; ++i)
    v.push_back(i);

  cout << "\nv contains " << v.rend() - v.rbegin() << " elements\n";
  cout << "The reverse sequence is:\n";

  Vector<int>::const_reverse_iterator i = v.rbegin();

  for (int offset = 0; offset != v.size(); ++offset)
    cout << i[offset] << ' ';
  cout << endl;

  cout << "The 3rd element is " << *(i + 2) << endl;
  cout << "The 4th element is " << *(3 + i) << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.