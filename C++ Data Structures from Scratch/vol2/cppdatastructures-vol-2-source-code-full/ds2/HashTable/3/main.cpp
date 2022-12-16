#include <iostream>
#include <string>
#include <utility>

#include "dss/printContainer/printContainer.h"

#include "ds2/HashTable/3/HashTable.h"
#include "ds2/printBuckets/printBuckets.h"
#include "ds2/stdPairIo/stdPairIo.h"

int main()
{
  using namespace std;
  using namespace ds2;
  using dss::printContainer;

  typedef HashTable<string, string> HashTable;

  HashTable h;

  h.insert(make_pair<string, string>("Karachi", "Pakistan"));
  h.insert(make_pair<string, string>("Lagos", "Nigeria"));
  h.insert(make_pair<string, string>("Shanghai", "China"));
  h.insert(make_pair<string, string>("Delhi", "India"));
  h.insert(make_pair<string, string>("Jakarta", "Indonesia"));
  cout << endl;

  printBuckets(h);
  printContainer(h);

  HashTable::iterator i = h.find(string("Shanghai"));

  if (i != h.end())
  {
    cout << "\nErasing " << *i << "...\n\n";
    i = h.erase(i);
  }

  if (i != h.end())
    cout << "Next element = " << *i << endl << endl;

  printBuckets(h);
  printContainer(h);

  cout << "\nClearing table...\n\n";
  h.clear();

  printBuckets(h);
  printContainer(h);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.