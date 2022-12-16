#include <iostream>
#include <string>

#include "dss/classes/Student.h"

namespace dss
{
void printArray(const Student* begin, const Student* end);
};

int main()
{
  using namespace std;
  using namespace dss;

  const int classSize = 5;
  Student students[classSize];

  for (int i = 0; i != classSize; ++i)
  {
    string firstName;
    string lastName;
    int testScore;

    cout << "\nEnter first name, last name, and test score\n"
      "(e.g. Owen Harper 87): ";

    cin >> firstName >> lastName >> testScore;

    students[i].setName(firstName, lastName);
    students[i].setTestScore(testScore);
  }

  cout << endl;
  printArray(students, students + classSize);

  return 0;
}

namespace dss
{
void printArray(const Student* begin, const Student* end)
{
  using namespace std;

  while (begin != end)
  {
    cout << begin->firstName() << ' ' <<
      begin->lastName() << ' ' <<
      begin->testScore() << ' ' <<
      begin->letterGrade() << endl;

    ++begin;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.