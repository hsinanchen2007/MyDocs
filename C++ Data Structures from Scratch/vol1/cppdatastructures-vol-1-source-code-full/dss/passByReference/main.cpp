#include <iostream>

#include "dss/swapInts/swap.h"

int main()
{
  using namespace std;

  int x;
  int y;

  cout << "Enter an integer value for x: ";
  cin >> x;

  cout << "Enter an integer value for y: ";
  cin >> y;

  while (true)
  {
    cout << "\nThe value of x is now " << x << endl;
    cout << "The value of y is now " << y << endl;

    char userCommand;

    cout << "\nEnter s to swap the values of x and y, or q to quit"
      " (case-sensitive): ";

    cin >> userCommand;

    if (userCommand == 's')
      dss::swap(&x, &y);
    else
      break;
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.