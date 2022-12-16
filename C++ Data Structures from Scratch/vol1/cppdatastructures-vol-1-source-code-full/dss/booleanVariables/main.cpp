#include <iostream>

int main()
{
  using namespace std;

  int k;

  cout << "Enter a number (integer): ";
  cin >> k;

  bool isPositive = (k > 0);
  bool isNegative = (k < 0);
  bool isEven = (k % 2 == 0);

  if (isEven)
    cout << "You entered an even number\n";

  if (!isEven)
    cout << "You entered an odd number\n";

  if (!isPositive && !isNegative)
    cout << "You entered 0\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.