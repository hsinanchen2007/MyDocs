#ifndef DSS_STUDENT_STUDENT
#define DSS_STUDENT_STUDENT

#include <iostream>
#include <string>

namespace dss
{
class Student;

std::ostream& operator<<(std::ostream& lhs, const Student& rhs);

class Student
{
 public:
  Student();
  Student(const Student& source);

  std::string firstName() const;
  std::string lastName() const;
  int testScore() const;
  char letterGrade() const;

  bool operator==(const Student& rhs) const;
  bool operator!=(const Student& rhs) const;
  bool operator>=(const Student& rhs) const;
  bool operator<=(const Student& rhs) const;
  bool operator>(const Student& rhs) const;
  bool operator<(const Student& rhs) const;

  void setName(const std::string& firstName, const std::string& lastName);
  void setTestScore(int testScore);

  Student& operator=(const Student& rhs);
  friend std::istream& operator>>(std::istream& lhs, Student& rhs);

 private:
  std::string _firstName;
  std::string _lastName;
  int _testScore;
  char _letterGrade;
};

inline std::ostream& operator<<(std::ostream& lhs, const Student& rhs)
{
  lhs << rhs.firstName() << ' ' <<
    rhs.lastName() << ' ' <<
    rhs.testScore() << ' ' <<
    rhs.letterGrade();

  return lhs;
}

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

inline bool Student::operator==(const Student& rhs) const
{
  return _firstName == rhs._firstName && _lastName == rhs._lastName;
}

inline bool Student::operator!=(const Student& rhs) const
{
  return !(*this == rhs);
}

inline bool Student::operator>=(const Student& rhs) const
{
  return !(*this < rhs);
}

inline bool Student::operator<=(const Student& rhs) const
{
  return !(*this > rhs);
}

inline bool Student::operator>(const Student& rhs) const
{
  return (*this != rhs) && !(*this < rhs);
}

inline void Student::setName(const std::string& firstName,
  const std::string& lastName)
{
  _firstName = firstName;
  _lastName = lastName;
}
};

#endif // DSS_STUDENT_STUDENT

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.