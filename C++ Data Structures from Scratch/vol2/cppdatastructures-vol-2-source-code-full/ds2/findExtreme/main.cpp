#include <functional>
#include <iostream>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/findExtreme/findExtreme.h"

int main()
{
  using namespace std;
  using namespace ds2;

  vector<int> v = {5, 4, 7, 2, 3, 8, 6};
  dss::printContainer(v);

  cout << "The smallest element is " <<
    *findExtreme(v.begin(), v.end(), less<int>());

  cout << "\nThe largest element is " <<
    *findExtreme(v.begin(), v.end(), greater<int>());

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.