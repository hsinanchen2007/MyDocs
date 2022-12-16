#include <iostream>

#include "dss/List/1/List.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef List<Traceable<char>> List;

  List s;
  List t;

  s.push_back('A');
  s.push_back('B');
  s.push_back('C');
  cout << endl;

  s.push_front('X');
  s.push_front('Y');
  s.push_front('Z');
  cout << endl;

  t.push_front('A');
  t.push_front('B');
  t.push_front('C');
  cout << endl;

  t.push_back('X');
  t.push_back('Y');
  t.push_back('Z');
  cout << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.