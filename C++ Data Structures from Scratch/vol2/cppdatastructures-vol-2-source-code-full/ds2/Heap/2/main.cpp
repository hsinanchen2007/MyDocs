#include <iostream>

#include "ds2/Heap/2/Heap.h"

int main()
{
  using namespace std;
  using namespace ds2;

  Heap<int> h;

  h.push(5);
  h.push(3);
  h.push(7);
  h.push(2);
  h.push(4);
  h.push(6);
  h.push(8);

  while (!h.empty())
  {
    cout << "top " << h.top() << endl;
    h.pop();
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.