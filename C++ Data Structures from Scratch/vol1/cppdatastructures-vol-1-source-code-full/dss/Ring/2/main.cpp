#include <iostream>

#include "dss/Ring/2/Ring.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  Ring<Traceable<int>> r;

  for (int i = 0; i != 9; ++i)
  {
    r.push_front(i);
    cout << endl;
  }

  Ring<char> s;

  s.push_front('g');
  s.push_front('f');
  s.push_front('e');
  s.push_front('d');
  s.push_front('c');
  s.push_front('b');
  s.push_front('a');

  cout << "s contains " << s.size() << " elements:\n";

  for (int i = 0; i != s.size(); ++i)
    cout << s[i] << ' ';

  cout << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.