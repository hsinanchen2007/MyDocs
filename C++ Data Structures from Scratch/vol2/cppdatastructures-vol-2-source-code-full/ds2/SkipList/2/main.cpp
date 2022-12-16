#include <iostream>

#include "ds2/printSkipList/printSkipList.h"
#include "ds2/SkipList/2/SkipList.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef SkipList<Traceable<int>, int> SkipList;

  SkipList s;

  for (int i = 0; i != s.capacity(); ++i)
    s.insert(make_pair(i, 0));
  cout << endl;

  printSkipList(s);
  printAvailableNodes(s);

  s.insert(make_pair(s.back().first.value() + 1, 0));
  cout << endl;

  printSkipList(s);
  printAvailableNodes(s);

  s.reserve(32);
  printSkipList(s);
  printAvailableNodes(s);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.