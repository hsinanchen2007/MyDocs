#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/heapTransform/3/heapTransform.h"

int main()
{
  using namespace std;
  using namespace dss;

  vector<int> v = {8, 4, 7, 2, 3, 5, 6};
  less<int> predicate;

  while (!v.empty())
  {
    printContainer(v);

    ds2::popHeap(v.begin(), v.end(), predicate);
    v.pop_back();
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.