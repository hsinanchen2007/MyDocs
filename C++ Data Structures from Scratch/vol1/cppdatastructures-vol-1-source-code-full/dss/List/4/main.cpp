#include <iostream>

#include "dss/List/4/List.h"
#include "dss/printContainer/printContainer.h"

int main()
{
  using namespace std;
  using namespace dss;

  List<int> s;

  for (int i = 0; i != 10; ++i)
    s.push_back(i);

  printContainer(s);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.