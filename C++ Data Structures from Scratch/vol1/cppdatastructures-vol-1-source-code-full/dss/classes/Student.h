#ifndef DSS_CLASSES_STUDENT
#define DSS_CLASSES_STUDENT

#include <string>

namespace dss
{
class Student
{
 public:
  Student();

  std::string firstName() const;
  std::string lastName() const;
  int testScore() const;
  char letterGrade() const;

  void setName(const std::string& firstName, const std::string& lastName);
  void setTestScore(int testScore);

 private:
  std::string _firstName;
  std::string _lastName;
  int _testScore;
  char _letterGrade;
};

inline std::string Student::firstName() const
{
  return _firstName;
}

inline std::string Student::lastName() const
{
  return _lastName;
}

inline int Student::testScore() const
{
  return _testScore;
}

inline char Student::letterGrade() const
{
  return _letterGrade;
}

inline void Student::setName(const std::string& firstName,
  const std::string& lastName)
{
  _firstName = firstName;
  _lastName = lastName;
}
};

#endif // DSS_CLASSES_STUDENT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.