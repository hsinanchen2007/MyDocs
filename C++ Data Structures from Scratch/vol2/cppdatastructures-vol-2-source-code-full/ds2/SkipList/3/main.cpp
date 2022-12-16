#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/SkipList/3/SkipList.h"
#include "ds2/stdPairIo/stdPairIo.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  typedef SkipList<int, int> SkipList;

  SkipList s;

  for (int i = 0; i != 10; i += 2)
    s.insert(make_pair(i, 0));

  printContainer(s);
  printContainerReverse(s);

  pair<SkipList::const_iterator, bool> p = s.insert(make_pair(7, 0));

  if (p.second == true)
    cout << "\nInserted element " << *p.first << endl << endl;

  printContainer(s);
  printContainerReverse(s);

  p = s.insert(make_pair(4, 1));

  if (p.second == false)
    cout << "\nElement " << *p.first << " already exists\n";

  SkipList::const_iterator i = s.find(6);

  if (i != s.end())
    cout << "\nFound element " << *i << endl;

  i = s.find(9);

  if (i == s.end())
    cout << "\nKey 9 not found\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.