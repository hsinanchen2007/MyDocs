#include "dss/Array/1/Array.h"
#include "dss/predicates/predicates.h"
#include "dss/printSequence/printSequence.h"
#include "dss/quickSort/quickSort.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef Array<int, 7> Array;
  Array a;

  a[0] = 5;
  a[1] = 7;
  a[2] = 6;
  a[3] = 1;
  a[4] = 3;
  a[5] = 2;
  a[6] = 4;

  cout << "a contains " << a.size() << " elements:\n";
  printSequence(a.begin(), a.end());
  cout << endl << endl;

  cout << "The front element is " << a.front() << endl;
  cout << "The back element is " << a.back() << endl << endl;

  cout << "Performing quicksort...\n";
  quickSort(a.begin(), a.end(), Less<Array::value_type>());

  cout << "\nThe sorted sequence is:\n";
  printSequence(a.begin(), a.end());

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.