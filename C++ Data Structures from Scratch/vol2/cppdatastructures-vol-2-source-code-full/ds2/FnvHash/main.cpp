#include <iostream>
#include <string>

#include "ds2/FnvHash/FnvHash.h"

int main()
{
  using namespace std;
  using namespace ds2;

  FnvHash<int> hashInt;
  FnvHash<double> hashDouble;
  FnvHash<string> hashString;

  cout << hashInt(67) << endl;
  cout << hashDouble(3.14159) << endl;
  cout << hashString("perihelion") << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.