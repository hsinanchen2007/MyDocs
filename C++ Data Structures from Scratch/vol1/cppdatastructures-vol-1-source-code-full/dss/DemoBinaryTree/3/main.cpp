#include <iostream>

#include "dss/DemoBinaryTree/3/DemoBinaryTree.h"
#include "dss/Pair/PairIo.h"
#include "dss/printContainer/printContainer.h"

int main()
{
  using namespace std;
  using namespace dss;

  DemoBinaryTree t;
  printContainer(t);

  DemoBinaryTree::key_type searchKey;
  cout << "\nEnter key value (int) of desired element: ";
  cin >> searchKey;

  DemoBinaryTree::iterator i = t.find(searchKey);

  if (i != t.end())
  {
    cout << "\nFound element " << *i;
    cout << "\nEnter new mapped value (char): ";
    cin >> i->second;

    cout << endl;
    printContainer(t);
  }
  else
  {
    cout << "\nNo element with a key value of " << searchKey << " exists.";
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.