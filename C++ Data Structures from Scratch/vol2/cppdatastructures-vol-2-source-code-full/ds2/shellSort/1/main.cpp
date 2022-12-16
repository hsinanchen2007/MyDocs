#include <functional>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/shellSort/common/sortSubsequence.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2::shell;

  vector<int> v = {21, 20, 17, 12, 14, 18, 16, 11, 22, 19, 15, 13};
  int gapSize = 3;

  printContainer(v);

  for (int s = 0; s != gapSize; ++s)
  {
    sortSubsequence(v.begin() + s,
      v.end(),
      gapSize,
      less<int>());

    printContainer(v);
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.