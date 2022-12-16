#include <iostream>

#include "dss/Array/1/Array.h"
#include "dss/insertionSort/insertionSort.h"
#include "dss/predicates/predicates.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef Array<Traceable<int>, 5> Array;
  Array a;

  for (Array::size_type i = 0; i != a.size(); ++i)
  {
    cout << "\nEnter an integer: ";
    cin >> a[i];
  }

  cout << "\nPerforming insertion sort...\n\n";
  insertionSort(a.begin(), a.end(), Less<Array::value_type>());

  cout << "\nThe sorted sequence is:\n";
  printSequence(a.begin(), a.end());
  cout << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.