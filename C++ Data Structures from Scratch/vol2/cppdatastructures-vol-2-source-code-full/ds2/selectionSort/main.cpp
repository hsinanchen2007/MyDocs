#include <functional>
#include <iostream>
#include <vector>

#include "dss/printContainer/printContainer.h"

#include "ds2/selectionSort/selectionSort.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  vector<int> v = {5, 4, 7, 2, 3, 8, 6};
  printContainer(v);

  selectionSort(v.begin(), v.end(), less<int>());
  printContainer(v);

  selectionSort(v.begin(), v.end(), greater<int>());
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.