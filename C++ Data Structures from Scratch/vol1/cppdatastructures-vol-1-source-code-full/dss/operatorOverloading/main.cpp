#include <iostream>

#include "dss/Student/Student.h"

namespace dss
{
void printArray(const Student* begin, const Student* end);
void swap(Student& a, Student& b);
void insertionSort(Student* begin, Student* end);
};

int main()
{
  using namespace std;
  using namespace dss;

  const int classSize = 5;
  Student students[classSize];

  for (int i = 0; i != classSize; ++i)
  {
    cout << "\nEnter first name, last name, and test score\n"
      "(e.g. Owen Harper 87): ";

    cin >> students[i];
  }

  cout << "\nPerforming insertion sort...\n";
  insertionSort(students, students + classSize);

  cout << "\nThe sorted sequence (by lastName, firstName) is:\n";
  printArray(students, students + classSize);

  return 0;
}

namespace dss
{
void printArray(const Student* begin, const Student* end)
{
  while (begin != end)
  {
    std::cout << *begin << std::endl;
    ++begin;
  }
}

void swap(Student& a, Student& b)
{
  Student c = a;
  a = b;
  b = c;
}

void insertionSort(Student* begin, Student* end)
{
  for (Student* current = begin; current != end; ++current)
  {
    Student* y = current;
    Student* x = current;
    --x;

    while (y != begin && *y < *x)
    {
      swap(*y, *x);
      --y;
      --x;
    }
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.