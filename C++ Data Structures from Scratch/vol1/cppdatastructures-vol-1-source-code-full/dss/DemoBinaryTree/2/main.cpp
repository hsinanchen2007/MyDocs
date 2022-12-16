#include <iostream>

#include "dss/DemoBinaryTree/2/DemoBinaryTree.h"
#include "dss/Pair/PairIo.h"
#include "dss/printContainer/printContainer.h"

int main()
{
  using namespace std;
  using namespace dss;

  DemoBinaryTree t;

  cout << "t contains " << t.size() << " elements:\n";
  printContainer(t);

  cout << "\nThe reverse sequence is:\n";
  printContainerReverse(t);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.