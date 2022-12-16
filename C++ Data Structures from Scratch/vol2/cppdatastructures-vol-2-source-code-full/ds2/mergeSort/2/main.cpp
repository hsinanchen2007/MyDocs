#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/mergeSort/common/merge.h"
#include "ds2/mergeSort/common/split.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2::msCommon;

  vector<int> x = {3, 4, 5, 1, 2, 6};
  printContainer(x);

  auto xMid = split(x.begin(), x.end());
  merge(x.begin(), xMid, x.end(), less<int>());
  printContainer(x);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.