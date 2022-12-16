#include <iostream>

#include "ds2/Heap/1/Heap.h"

namespace ds2
{
void pushAndPrintTop(Heap<int>* h, int i);
};

int main()
{
  using namespace std;
  using namespace ds2;

  Heap<int> h;

  pushAndPrintTop(&h, 5);
  pushAndPrintTop(&h, 3);
  pushAndPrintTop(&h, 7);
  pushAndPrintTop(&h, 2);
  pushAndPrintTop(&h, 4);
  pushAndPrintTop(&h, 6);
  pushAndPrintTop(&h, 8);

  return 0;
}

namespace ds2
{
void pushAndPrintTop(Heap<int>* h, int i)
{
  using namespace std;

  cout << "push " << i << endl;
  h->push(i);

  cout << "  size " << h->size() << endl;
  cout << "  top " << h->top() << endl << endl;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.