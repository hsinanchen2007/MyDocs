#include <iostream>

#include "dss/printSequence/printSequence.h"
#include "dss/Traceable/Traceable.h"
#include "dss/Vector/1/Vector.h"

int main()
{
  using namespace std;
  using namespace dss;

  Vector<Traceable<char>> v;

  while (true)
  {
    char userCommand;
    cout << "\n(p)ush_back (q)uit: ";
    cin >> userCommand;

    if (userCommand == 'p')
    {
      char c;
      cout << "\nEnter a character to push_back: ";
      cin >> c;

      v.push_back(c);

      cout << "\nv contains " << v.size() << " element(s):\n";
      printSequence(v.begin(), v.end());
      cout << endl;
    }
    else
    {
      break;
    }
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.