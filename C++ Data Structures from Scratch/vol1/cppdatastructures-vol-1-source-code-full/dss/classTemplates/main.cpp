#include <iostream>

#include "dss/classTemplates/alternativeStudentPredicates.h"
#include "dss/insertionSort/insertionSort.h"
#include "dss/predicates/predicates.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Student/Student.h"

int main()
{
  using namespace std;
  using namespace dss;

  const int size = 5;
  Student a[size];

  for (int i = 0; i != size; ++i)
  {
    cout << "\nEnter student name and test score (e.g. Owen Harper 87): ";
    cin >> a[i];
  }

  cout << "\nSorted by lastName, ascending:\n";
  insertionSort(a, a + 5, Less<Student>());
  printSequence(a, a + 5);

  cout << "\n\nSorted by lastName, descending:\n";
  insertionSort(a, a + 5, Greater<Student>());
  printSequence(a, a + 5);

  cout << "\n\nSorted by firstName, ascending:\n";
  insertionSort(a, a + 5, LessByFirstName());
  printSequence(a, a + 5);

  cout << "\n\nSorted by firstName, descending:\n";
  insertionSort(a, a + 5, GreaterByFirstName());
  printSequence(a, a + 5);

  cout << "\n\nSorted by testScore, ascending:\n";
  insertionSort(a, a + 5, LessByTestScore());
  printSequence(a, a + 5);

  cout << "\n\nSorted by testScore, descending:\n";
  insertionSort(a, a + 5, GreaterByTestScore());
  printSequence(a, a + 5);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.