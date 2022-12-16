#include <iostream>

int main()
{
  using namespace std;

  int a = 3;
  int b = 5;

  cout << "a = " << a << ", b = " << b << endl;

  a += 8;
  cout << "a = " << a << endl;

  b = (a += 8);
  cout << "a = " << a << ", b = " << b << endl;

  a -= 4;
  cout << "a = " << a << endl;

  b = (a -= 4);
  cout << "a = " << a << ", b = " << b << endl;

  a *= 3;
  cout << "a = " << a << endl;

  b = (a *= 3);
  cout << "a = " << a << ", b = " << b << endl;

  a /= 3;
  cout << "a = " << a << endl;

  b = (a /= 3);
  cout << "a = " << a << ", b = " << b << endl;

  a %= 4;
  cout << "a = " << a << endl;

  b = (a %= 2);
  cout << "a = " << a << ", b = " << b << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.