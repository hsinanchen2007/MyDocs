#include <iostream>

int main()
{
  using namespace std;

  for (int i = 0; i != 5; ++i)
    cout << i << endl;

  cout << endl;

  int i = 0;

  while (i != 5)
  {
    cout << i << endl;
    ++i;
  }

  cout << endl;

  for (int i = 0; i != 5; ++i)
  {
    if (i % 2 == 0)
      cout << i << " is even\n";
    else
      cout << i << " is odd\n";

    for (int n = i - 1; n >= 0; --n)
      cout << "  " << n << endl;
  }

  cout << endl;

  for (int x = 1000; true; ++x)
  {
    if (x % 17 == 0)
    {
      cout << x << " is divisible by 17\n";
      break;
    }
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.