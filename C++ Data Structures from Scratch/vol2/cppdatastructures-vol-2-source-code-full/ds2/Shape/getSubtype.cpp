#include <iostream>

#include "ds2/Shape/getSubtype.h"

namespace ds2
{
char getSubtype()
{
  using namespace std;

  char subtype;

  cout << "\n(c)ircle (s)quare (t)riangle (d)one: ";
  cin >> subtype;

  return subtype;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.