#include <iostream>
#include <string>
#include <utility>

#include "dss/printContainer/printContainer.h"

#include "ds2/HashTable/4/HashTable.h"
#include "ds2/printBuckets/printBuckets.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/2/Traceable.h"

int main()
{
  using namespace std;
  using namespace ds2;
  using dss::printContainer;

  typedef HashTable<Traceable<string>, string> HashTable;

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
  h.insert(make_pair<string, string>("Kinshasa", "Congo"));
  cout << endl;

  HashTable t(h);
  cout << endl;

  printBuckets(t);
  printContainer(t);
  cout << endl;

  HashTable x;
  x = t;
  cout << endl;

  printBuckets(x);
  printContainer(x);
  cout << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.