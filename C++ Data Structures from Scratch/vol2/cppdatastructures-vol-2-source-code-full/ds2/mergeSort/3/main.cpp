#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/mergeSort/3/mergeSort.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  vector<int> v = {1, 6, 4, 8, 2, 7, 3, 0, 9, 5};
  printContainer(v);

  mergeSort(v.begin(), v.end(), less<int>());
  printContainer(v);

  mergeSort(v.begin(), v.end(), greater<int>());
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.