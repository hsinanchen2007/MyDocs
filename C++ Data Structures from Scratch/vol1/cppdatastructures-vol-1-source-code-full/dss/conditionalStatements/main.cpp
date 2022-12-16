#include <iostream>

int main()
{
  using namespace std;

  int x;

  cout << "Enter a number (integer): ";
  cin >> x;

  if (x == 0)
  {
    cout << "You entered 0\n";
  }

  if (x % 2 == 0)
    cout << "You entered an even number\n";
  else
    cout << "You entered an odd number\n";

  if (x > 0)
    cout << "You entered a positive number\n";
  else if (x < 0)
    cout << "You entered a negative number\n";
  else
    cout << "The number you entered is neither positive nor negative\n";

  if (x > 15)
  {
    if (x < 20)
      cout << "You entered a number greater than 15 but less than 20\n";
    else
      cout << "You entered a number greater than both 15 and 19\n";
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.