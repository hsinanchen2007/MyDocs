#include "dss/classes/Student.h"

namespace dss
{
Student::Student():
  _firstName(""),
  _lastName(""),
  _testScore(0),
  _letterGrade(' ')
{
  // ...
}

void Student::setTestScore(int testScore)
{
  _testScore = testScore;

  if (_testScore >= 90)
    _letterGrade = 'A';
  else if (_testScore >= 80)
    _letterGrade = 'B';
  else if (_testScore >= 70)
    _letterGrade = 'C';
  else if (_testScore >= 60)
    _letterGrade = 'D';
  else
    _letterGrade = 'F';
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.