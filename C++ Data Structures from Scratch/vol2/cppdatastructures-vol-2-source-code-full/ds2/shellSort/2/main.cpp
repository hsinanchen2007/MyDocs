#include <iostream>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/shellSort/common/generateGapSizes.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2::shell;

  vector<int> gapSizes;

  generateGapSizes(&gapSizes, 5);
  cout << "Gap sizes for a 5-element sequence:\n";
  printContainerReverse(gapSizes);

  gapSizes.clear();

  generateGapSizes(&gapSizes, 35);
  cout << "Gap sizes for a 35-element sequence:\n";
  printContainerReverse(gapSizes);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.