#ifndef DSS_CLASSTEMPLATES_ALTERNATIVESTUDENTPREDICATES
#define DSS_CLASSTEMPLATES_ALTERNATIVESTUDENTPREDICATES

#include "dss/Student/Student.h"

namespace dss
{
struct LessByFirstName
{
  bool operator()(const Student& a, const Student& b) const;
};

struct GreaterByFirstName
{
  bool operator()(const Student& a, const Student& b) const;
};

struct LessByTestScore
{
  bool operator()(const Student& a, const Student& b) const;
};

struct GreaterByTestScore
{
  bool operator()(const Student& a, const Student& b) const;
};

inline bool LessByFirstName::operator()(const Student& a,
  const Student& b) const
{
  return a.firstName() < b.firstName();
}

inline bool GreaterByFirstName::operator()(const Student& a,
  const Student& b) const
{
  return a.firstName() > b.firstName();
}

inline bool LessByTestScore::operator()(const Student& a,
  const Student& b) const
{
  return a.testScore() < b.testScore();
}

inline bool GreaterByTestScore::operator()(const Student& a,
  const Student& b) const
{
  return a.testScore() > b.testScore();
}
};

#endif // DSS_CLASSTEMPLATES_ALTERNATIVESTUDENTPREDICATES

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.