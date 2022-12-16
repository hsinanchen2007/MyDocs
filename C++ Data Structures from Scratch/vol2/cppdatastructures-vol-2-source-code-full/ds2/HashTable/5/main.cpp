#include <iostream>
#include <string>
#include <utility>

#include "dss/printContainer/printContainer.h"

#include "ds2/HashTable/5/HashTable.h"
#include "ds2/printBuckets/printBuckets.h"
#include "ds2/stdPairIo/stdPairIo.h"

int main()
{
  using namespace std;
  using namespace ds2;
  using dss::printContainer;

  typedef HashTable<string, string> HashTable;

  HashTable h;

  h.insert(make_pair<string, string>("Shanghai", "China"));
  h.insert(make_pair<string, string>("Karachi", "Pakistan"));
  h.insert(make_pair<string, string>("Lagos", "Nigeria"));
  h.insert(make_pair<string, string>("Delhi", "India"));
  h.insert(make_pair<string, string>("Istanbul", "Turkey"));
  h.insert(make_pair<string, string>("Tokyo", "Japan"));
  h.insert(make_pair<string, string>("Seoul", "South Korea"));
  h.insert(make_pair<string, string>("Moscow", "Russia"));
  h.insert(make_pair<string, string>("Sao Paulo", "Brazil"));
  h.insert(make_pair<string, string>("Jakarta", "Indonesia"));
  cout << endl;

  printBuckets(h);

  h.max_load_factor(0.5);
  printBuckets(h);

  h.rehash(100);
  printBuckets(h);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.