#include <iostream>

int main()
{
  using namespace std;

  int x = 0;
  int y = 1;

  int* p = nullptr;

  cout << "p = nullptr = " << p << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl << endl;

  p = &x;
  *p = 5;

  cout << "p = &x = " << p << endl;
  cout << "*p = " << *p << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl << endl;

  p = &y;
  *p = 8;

  cout << "p = &y = " << p << endl;
  cout << "*p = " << *p << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.