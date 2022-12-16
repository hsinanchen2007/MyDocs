#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/shellSort/3/shellSort.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  vector<int> x = {21, 20, 17, 12, 14, 18, 16, 11, 22, 19, 15, 13};
  printContainer(x);

  shellSort(x.begin(), x.end(), less<int>());
  printContainer(x);

  shellSort(x.begin(), x.end(), greater<int>());
  printContainer(x);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.