#include <iostream>

#include "ds2/ForwardList/1/ForwardList.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace ds2;

  ForwardList<Traceable<int>> f;

  for (int i = 0; i != 5; ++i)
  {
    f.push_front(i);
    cout << "\nInserted " << f.front() << endl << endl;
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.