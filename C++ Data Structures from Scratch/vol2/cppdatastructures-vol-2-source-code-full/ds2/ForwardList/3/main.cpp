#include <iostream>

#include "dss/printContainer/printContainer.h"
#include "dss/printSequence/printSequence.h"

#include "ds2/ForwardList/3/ForwardList.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  ForwardList<int> f;

  for (int i = 0; i != 5; ++i)
    f.push_front(i);

  cout << *(++f.before_begin()) << endl;

  printContainer(f);
  printSequence(f.begin(), f.end());

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.