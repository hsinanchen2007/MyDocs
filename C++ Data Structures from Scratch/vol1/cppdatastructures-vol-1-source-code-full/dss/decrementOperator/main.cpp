#include <iostream>

int main()
{
  using namespace std;

  int a = 9;
  int b = 5;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  --a;
  cout << "a = " << a << endl << endl;

  b = --a;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  a--;
  cout << "a = " << a << endl << endl;

  b = a--;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.