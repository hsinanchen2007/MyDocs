#include <iostream>
#include <string>

int main()
{
  using namespace std;

  cout << "Hello" << endl;

  int i = 0;
  double d = 3.14;
  bool b = true;
  char c = '?';
  string s = "Independence Day";

  cout << "i is " << i << endl;
  cout << "d is " << d << endl;
  cout << "b is " << b << endl;
  cout << "c is " << c << endl;
  cout << "s is " << s << endl << endl;

  i = 9;
  d = 2.71;
  b = false;
  c = '!';
  s = "July 4th, 1776";

  cout << "i is " << i << endl;
  cout << "d is " << d << endl;
  cout << "b is " << b << endl;
  cout << "c is " << c << endl;
  cout << "s is " << s << endl;
  cout << "Goodbye\n";

  return 0;
}

// single-line comment

/*
  multiple-line
  comment
*/

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.