#include <iostream>
#include <vector>

#include "dss/printContainer/printContainer.h"
#include "dss/printSequence/printSequence.h"

#include "ds2/mergeSort/common/split.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2::msCommon;

  vector<int> x = {2, 4, 6, 8};
  printContainer(x);

  auto xMid = split(x.begin(), x.end());
  printSequence(x.begin(), xMid);
  cout << endl;
  printSequence(xMid, x.end());
  cout << endl << endl;

  vector<int> y = {1, 3, 5, 7, 9};
  printContainer(y);

  auto yMid = split(y.begin(), y.end());
  printSequence(y.begin(), yMid);
  cout << endl;
  printSequence(yMid, y.end());

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.