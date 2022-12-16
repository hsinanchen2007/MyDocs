#include "dss/Student/Student.h"

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

Student::Student(const Student& source):
  _firstName(source._firstName),
  _lastName(source._lastName),
  _testScore(source._testScore),
  _letterGrade(source._letterGrade)
{
  // ...
}

bool Student::operator<(const Student& rhs) const
{
  if (_lastName < rhs._lastName)
    return true;
  else if (_lastName == rhs._lastName && _firstName < rhs._firstName)
    return true;
  else
    return false;
}

Student& Student::operator=(const Student& rhs)
{
  _firstName = rhs._firstName;
  _lastName = rhs._lastName;
  _testScore = rhs._testScore;
  _letterGrade = rhs._letterGrade;

  return *this;
}

std::istream& operator>>(std::istream& lhs, Student& rhs)
{
  int testScore;

  lhs >> rhs._firstName >> rhs._lastName >> testScore;

  rhs.setTestScore(testScore);

  return lhs;
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