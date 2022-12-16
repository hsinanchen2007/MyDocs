#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/heapTransform/1/heapTransform.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  vector<int> v = {2, 3, 4, 5, 6, 7, 8};
  printContainer(v);

  makeHeap(v.begin(), v.end(), less<int>());
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.