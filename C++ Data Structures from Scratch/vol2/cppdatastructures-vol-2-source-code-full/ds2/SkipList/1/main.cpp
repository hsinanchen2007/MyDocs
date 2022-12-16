#include <iostream>

#include "ds2/printSkipList/printSkipList.h"
#include "ds2/SkipList/1/SkipList.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef SkipList<Traceable<int>, int> SkipList;

  SkipList s;

  s.insert(make_pair(4, 0));
  s.insert(make_pair(0, 0));
  s.insert(make_pair(3, 0));
  s.insert(make_pair(1, 0));
  s.insert(make_pair(5, 0));
  s.insert(make_pair(2, 0));
  s.insert(make_pair(7, 0));
  s.insert(make_pair(6, 0));
  cout << endl;

  printSkipList(s);
  printAvailableNodes(s);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.