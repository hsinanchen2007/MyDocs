#include <iostream>

#include "dss/List/2/List.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef List<Traceable<char>> List;

  List s;

  s.push_back('A');
  s.push_back('B');
  s.push_back('C');

  s.push_front('X');
  s.push_front('Y');
  s.push_front('Z');
  cout << endl;

  while (!s.empty())
    s.pop_back();
  cout << endl;

  s.push_back('A');
  s.push_back('B');
  s.push_back('C');

  s.push_front('X');
  s.push_front('Y');
  s.push_front('Z');
  cout << endl;

  while (!s.empty())
    s.pop_front();
  cout << endl;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.