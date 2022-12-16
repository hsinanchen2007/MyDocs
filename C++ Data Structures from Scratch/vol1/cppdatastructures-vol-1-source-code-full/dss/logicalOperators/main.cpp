#include <iostream>

int main()
{
  using namespace std;

  int x;

  cout << "Enter a number (integer): ";
  cin >> x;

  if (x > 0 && x < 10)
    cout << "Your number is positive and less than 10\n";
  else
    cout << "Your number is either nonpositive or greater than 9\n";

  if (x % 2 == 1 || x < 0)
    cout << "Your number is either odd, negative, or both\n";
  else
    cout << "Your number is neither odd nor negative\n";

  if ((x < -5 && x > -10) || (x > 5 && x < 10))
    cout << "Your number is either between -5 and -10, or between 5 and 10\n";
  else
    cout << "Your number is neither between -5 and -10, nor between 5 and 10\n";

  if (!(x < 0))
    cout << "Your number is not negative\n";
  else
    cout << "Your number is negative\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.