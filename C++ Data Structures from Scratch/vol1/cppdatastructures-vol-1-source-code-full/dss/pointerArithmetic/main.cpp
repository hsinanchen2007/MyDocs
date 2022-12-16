#include <iostream>

#include "dss/swapInts/swap.h"

namespace dss
{
void printArray(int* a, int size);
};

int main()
{
  using namespace std;
  using dss::printArray;

  const int totalNumbers = 5;
  int numbers[totalNumbers];

  for (int* p = numbers; p != numbers + totalNumbers; ++p)
  {
    cout << "Enter a number (integer): ";
    cin >> *p;
  }

  cout << "\nPerforming bubble sort...\n";
  printArray(numbers, totalNumbers);

  for (int* end = numbers + totalNumbers - 2; end >= numbers; --end)
  {
    for (int* p = numbers; p <= end; ++p)
    {
      cout << "If " << *p << " > " << *(p + 1) << ", then swap\n";

      if (*p > *(p + 1))
        dss::swap(p, p + 1);

      printArray(numbers, totalNumbers);
    }
  }

  cout << "\nThe sorted sequence is:\n";
  printArray(numbers, totalNumbers);

  return 0;
}

namespace dss
{
void printArray(int* a, int size)
{
  using namespace std;

  for (int* p = a; p != a + size; ++p)
    cout << *p << ' ';

  cout << endl;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.