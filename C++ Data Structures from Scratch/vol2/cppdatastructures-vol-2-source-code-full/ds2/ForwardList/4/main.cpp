#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/ForwardList/4/ForwardList.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  ForwardList<Traceable<int>> f;

  for (int i = 0; i != 5; ++i)
    f.push_front(i);

  cout << endl;
  printContainer(f);
  cout << endl;

  f.insert_after(f.before_begin(), 6);
  cout << endl;
  printContainer(f);
  cout << endl;

  f.insert_after(f.begin(), 5);
  cout << endl;
  printContainer(f);
  cout << endl;

  f.erase_after(f.begin());
  cout << endl;
  printContainer(f);
  cout << endl;

  f.erase_after(f.before_begin());
  cout << endl;
  printContainer(f);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.