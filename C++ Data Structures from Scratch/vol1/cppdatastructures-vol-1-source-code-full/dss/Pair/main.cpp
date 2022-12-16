#include <iostream>
#include <string>

#include "dss/Pair/PairIo.h"
#include "dss/printContainer/printContainer.h"
#include "dss/Vector/4/Vector.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef string FirstName;
  typedef int Age;
  typedef Pair<FirstName, Age> Record;

  Vector<Record> v;

  for (int i = 0; i != 3; ++i)
  {
    Record r;

    cout << "Enter first name and age (separated by whitespace): ";
    cin >> r;

    v.push_back(r);
  }

  cout << "\nYou entered:\n";
  printContainer(v);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.