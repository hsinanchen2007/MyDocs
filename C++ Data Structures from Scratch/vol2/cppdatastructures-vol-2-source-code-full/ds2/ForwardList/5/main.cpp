#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/ForwardList/5/ForwardList.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  typedef ForwardList<Traceable<int>> ForwardList;

  ForwardList f;

  for (int i = 0; i != 5; ++i)
    f.push_front(i);

  ForwardList g(f);
  cout << endl;
  printContainer(g);
  cout << endl;

  ForwardList h;
  h.push_front(5);
  h.push_front(6);
  cout << endl;

  h = f;
  cout << endl;
  printContainer(h);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.