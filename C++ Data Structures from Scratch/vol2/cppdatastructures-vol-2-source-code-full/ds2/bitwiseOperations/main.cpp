#include <iostream>
#include <string>

#include "ds2/bitwiseOperations/printBinaryRep.h"
#include "ds2/bitwiseOperations/printTypeTraits.h"

int main()
{
  using namespace std;
  using namespace ds2;

  printTypeTraits<char>();
  printTypeTraits<bool>();
  printTypeTraits<unsigned int>();
  printTypeTraits<int>();
  printTypeTraits<float>();
  printTypeTraits<double>();

  printBinaryRep('x');
  printBinaryRep(true);
  printBinaryRep(false);
  printBinaryRep(137494);
  printBinaryRep(-43);
  printBinaryRep(-2.875);
  printBinaryRep("umbra");
  printBinaryRep(string("umbra"));

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.