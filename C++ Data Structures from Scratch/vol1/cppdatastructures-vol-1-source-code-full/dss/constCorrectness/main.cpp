#include <iostream>

namespace dss
{
void printArray(const int* begin, const int* end);
void swap(int& a, int& b);
void insertionSort(int* begin, int* end);
};

int main()
{
  using namespace std;
  using namespace dss;

  const int totalNumbers = 9;
  int numbers[totalNumbers];

  for (int i = 0; i != totalNumbers; ++i)
  {
    cout << "Enter a number (integer): ";
    cin >> numbers[i];
  }

  cout << "\nPerforming insertion sort...\n";
  insertionSort(numbers, numbers + totalNumbers);

  cout << "\nThe sorted sequence is:\n";
  printArray(numbers, numbers + totalNumbers);

  return 0;
}

namespace dss
{
void printArray(const int* begin, const int* end)
{
  while (begin != end)
  {
    std::cout << *begin << ' ';
    ++begin;
  }
}

void swap(int& a, int& b)
{
  int c = a;
  a = b;
  b = c;
}

void insertionSort(int* begin, int* end)
{
  for (int* current = begin; current != end; ++current)
  {
    int* y = current;
    int* x = current;
    --x;

    while (y != begin && *y < *x)
    {
      swap(*y, *x);
      --y;
      --x;
    }
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.