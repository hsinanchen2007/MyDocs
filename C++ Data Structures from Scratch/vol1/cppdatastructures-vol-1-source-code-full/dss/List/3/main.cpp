#include <iostream>
#include <string>

#include "dss/List/3/List.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  List<int> s;

  s.push_back(0);

  for (int i = 1; i <= 5; ++i)
  {
    s.push_back(i);
    s.push_front(-i);
  }

  printSequence(s.begin(), s.end());
  cout << endl;

  List<int>::iterator i = s.end();
  while (i != s.begin())
  {
    --i;
    cout << *i << ' ';
  }
  cout << endl << endl;

  List<Traceable<string>> t;
  t.push_back(string("macadamia"));
  cout << endl;

  List<Traceable<string>>::iterator x = t.begin();
  x->printValue();
  cout << endl;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.