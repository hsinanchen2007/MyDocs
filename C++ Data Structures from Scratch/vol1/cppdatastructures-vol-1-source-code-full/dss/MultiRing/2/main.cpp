#include <iostream>

#include "dss/MultiRing/2/MultiRing.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef MultiRing<Traceable<char>> MultiRing;

  MultiRing m;

  m.push_front('h');
  m.push_front('g');
  m.push_front('f');
  m.push_front('e');
  m.push_front('d');
  m.push_front('c');
  m.push_front('b');
  m.push_front('a');
  cout << endl;

  for (MultiRing::size_type i = 0; i != m.size(); ++i)
    cout << m[i] << ' ';

  cout << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.