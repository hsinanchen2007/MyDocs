#include <iostream>

int main()
{
  using namespace std;

  int currentAge;
  int retirementAge;

  cout << "\nWhat is your current age? ";
  cin >> currentAge;

  cout << "\nAt what age do you plan to retire? ";
  cin >> retirementAge;

  for (int futureYears = 5; futureYears <= 25; futureYears += 5)
  {
    int futureAge = currentAge + futureYears;
    bool isRetired = (futureAge >= retirementAge);

    cout << "\nIn " << futureYears << " years, you will be " << futureAge <<
      " years old.\n";

    if (isRetired)
    {
      cout << "  You will have been retired for " <<
        futureAge - retirementAge << " years.\n";
    }
    else
    {
      cout << "  You will have " << retirementAge - futureAge <<
        " years before retirement.\n";
    }
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.