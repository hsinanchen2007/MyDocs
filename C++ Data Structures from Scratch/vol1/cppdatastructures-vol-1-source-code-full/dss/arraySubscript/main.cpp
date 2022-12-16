#include <iostream>

#include "dss/swapInts/swap.h"

namespace dss
{
void printArray(int a[], int size);
};

int main()
{
  using namespace std;
  using dss::printArray;

  const int totalNumbers = 5;
  int numbers[totalNumbers];

  for (int i = 0; i != totalNumbers; ++i)
  {
    cout << "Enter a number (integer): ";
    cin >> numbers[i];
  }

  cout << "\nPerforming bubble sort...\n";
  printArray(numbers, totalNumbers);

  for (int end = totalNumbers - 2; end >= 0; --end)
  {
    for (int i = 0; i <= end; ++i)
    {
      cout << "If " << numbers[i] << " > " << numbers[i + 1] << ", then swap\n";

      if (numbers[i] > numbers[i + 1])
        dss::swap(&numbers[i], &numbers[i + 1]);

      printArray(numbers, totalNumbers);
    }
  }

  cout << "\nThe sorted sequence is:\n";
  printArray(numbers, totalNumbers);

  return 0;
}

namespace dss
{
void printArray(int a[], int size)
{
  using namespace std;

  for (int i = 0; i != size; ++i)
    cout << a[i] << ' ';

  cout << endl;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.