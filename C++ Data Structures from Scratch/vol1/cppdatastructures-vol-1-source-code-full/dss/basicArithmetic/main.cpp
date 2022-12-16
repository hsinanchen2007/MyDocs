#include <iostream>

int main()
{
  using namespace std;

  int a = 1;
  int b = a + 2;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  a = 7 - b;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  b = a * 3;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  a = b / 4;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  b = a % 2;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.