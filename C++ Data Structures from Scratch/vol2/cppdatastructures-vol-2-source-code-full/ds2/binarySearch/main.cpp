#include <iostream>
#include <vector>

#include "ds2/binarySearch/binarySearch.h"

int main()
{
  using namespace std;
  using namespace ds2;

  vector<int> v;

  for (int i = 2; i <= 30; i +=2)
    v.push_back(i);

  vector<int>::const_iterator i = binarySearch(v.begin(), v.end(), 8);

  cout << "Found " << *i << endl;

  i = binarySearch(v.begin(), v.end(), 21);

  if (i == v.end())
    cout << "21 not found\n";

  i = binarySearch(v.begin(), v.end(), 0);

  if (i == v.end())
    cout << "0 not found\n";

  i = binarySearch(v.begin(), v.end(), 32);

  if (i == v.end())
    cout << "32 not found\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.