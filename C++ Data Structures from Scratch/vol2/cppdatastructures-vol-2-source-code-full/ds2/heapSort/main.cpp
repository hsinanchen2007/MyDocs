#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/heapSort/heapSort.h"

int main()
{
  using namespace std;
  using namespace dss;

  vector<int> v = {5, 3, 7, 2, 4, 8, 6};
  printContainer(v);

  ds2::heapSort(v.begin(), v.end(), less<int>());
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.