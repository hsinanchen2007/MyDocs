#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/heapTransform/2/heapTransform.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  vector<int> v = {2, 3, 4, 5, 6, 7, 8};
  less<int> predicate;

  makeHeap(v.begin(), v.end(), predicate);
  printContainer(v);

  v.push_back(9);
  printContainer(v);

  pushHeap(v.begin(), v.end(), predicate);
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.