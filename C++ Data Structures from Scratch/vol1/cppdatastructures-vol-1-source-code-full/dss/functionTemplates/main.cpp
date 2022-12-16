#include <iostream>

#include "dss/functionTemplates/insertionSort.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Student/Student.h"

int main()
{
  using namespace std;
  using namespace dss;

  const int totalElements = 5;

  int intArray[totalElements];
  Student studentArray[totalElements];

  for (int i = 0; i != totalElements; ++i)
  {
    cout << "\nEnter a number (integer): ";
    cin >> intArray[i];

    cout << "Enter student name and test score (e.g. Owen Harper 87): ";
    cin >> studentArray[i];
  }

  cout << "\nPerforming insertion sort...\n";

  insertionSort(intArray, intArray + totalElements);
  insertionSort(studentArray, studentArray + totalElements);

  cout << "\nThe sorted sequences are:\n\n";

  printSequence(intArray, intArray + totalElements);
  cout << endl << endl;

  printSequence(studentArray, studentArray + totalElements);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.