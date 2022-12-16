namespace dss
{
void swap(int* a, int* b)
{
  int c = *a;
  *a = *b;
  *b = c;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.