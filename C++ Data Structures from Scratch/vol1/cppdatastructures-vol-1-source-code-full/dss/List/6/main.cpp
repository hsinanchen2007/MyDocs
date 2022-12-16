#include <iostream>

#include "dss/List/6/List.h"
#include "dss/printContainer/printContainer.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef List<Traceable<char>> List;

  List s;

  s.push_back('A');
  s.push_back('B');
  cout << endl;

  s.insert(s.begin(), 'x');
  cout << endl;

  s.insert(s.end(), 'z');
  cout << endl;

  List::iterator i = ++++s.begin();

  i = s.insert(i, 'y');
  cout << endl;

  printContainer(s);
  cout << endl;

  cout << "Inserted element " << *i << endl;
  cout << "Preceding element is " << *--i << endl;
  cout << "Proceeding element is " << *++++i << endl << endl;

  s.erase(s.begin());
  cout << endl;

  s.erase(--s.end());
  cout << endl;

  --i;

  cout << "Erasing element " << *i << "...\n";
  i = s.erase(i);
  cout << endl;

  printContainer(s);
  cout << endl;

  cout << "Proceeding element is " << *i << endl;
  cout << "Preceding element is " << *--i << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.