#include <iostream>
#include <string>
#include <utility>

#include "dss/printContainer/printContainer.h"

#include "ds2/HashTable/1/HashTable.h"
#include "ds2/stdPairIo/stdPairIo.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef HashTable<string, string> HashTable;

  HashTable h;
  pair<HashTable::iterator, bool> p;

  p = h.insert(make_pair<string, string>("Shanghai", "China"));

  if (p.second == true)
    cout << "\nInserted " << *p.first << endl;

  p = h.insert(make_pair<string, string>("Shanghai", "Virginia"));

  if (p.second == false)
    cout << "\nHash table already contains " << *p.first << endl << endl;

  h.insert(make_pair<string, string>("Karachi", "Pakistan"));
  h.insert(make_pair<string, string>("Lagos", "Nigeria"));
  h.insert(make_pair<string, string>("Delhi", "India"));
  h.insert(make_pair<string, string>("Istanbul", "Turkey"));
  h.insert(make_pair<string, string>("Tokyo", "Japan"));
  h.insert(make_pair<string, string>("Seoul", "South Korea"));
  h.insert(make_pair<string, string>("Moscow", "Russia"));
  h.insert(make_pair<string, string>("Sao Paulo", "Brazil"));
  h.insert(make_pair<string, string>("Jakarta", "Indonesia"));

  cout << h.size() << " elements (" << h.bucket_count() << " buckets):\n\n";
  dss::printContainer(h);
  cout << endl;

  h.insert(make_pair<string, string>("Kinshasa", "Congo"));

  cout << h.size() << " elements (" << h.bucket_count() << " buckets):\n\n";
  dss::printContainer(h);

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.