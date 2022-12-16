#include <iostream>

#include "dss/printContainer/printContainer.h"
#include "dss/Ring/5/Ring.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef Ring<Traceable<char>> Ring;

  Ring x;

  x.push_back('a');
  x.push_back('b');
  x.push_back('c');
  x.push_back('d');
  x.push_back('e');
  x.push_back('f');
  x.push_back('g');
  x.push_back('h');
  x.push_back('i');
  x.push_back('j');
  x.push_back('k');
  cout << endl;

  Ring::iterator p = x.insert(x.begin() + 3, 'Y');
  cout << "\nInserted element " << *p << ":\n";
  printContainer(x);
  cout << endl;

  p = x.insert(x.end() - 3, 'Z');
  cout << "\nInserted element " << *p << ":\n";
  printContainer(x);
  cout << endl;

  p = x.begin() + 3;
  cout << "\nErasing element " << *p << "...\n";
  p = x.erase(p);
  cout << "\nProceeding element is " << *p << ":\n";
  printContainer(x);
  cout << endl;

  p = x.end() - 4;
  cout << "\nErasing element " << *p << "...\n";
  p = x.erase(p);
  cout << "\nProceeding element is " << *p << ":\n";
  printContainer(x);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.