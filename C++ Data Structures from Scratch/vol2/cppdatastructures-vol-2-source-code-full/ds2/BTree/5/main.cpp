#include <cctype>
#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/BTree/5/BTree.h"
#include "ds2/BTreeInOrderRecursive/BTreeInOrderRecursive.h"
#include "ds2/PrintBTreeNode/PrintBTreeNode.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;
  using namespace ds2;

  typedef BTree<Traceable<int>, int> BTree;

  BTree x;

  for (int i = 0; i != 46; i += 2)
    x.insert(make_pair(i, 0));

  BTree y(x);

  BTree z;

  for (int i = 0; i != 5; ++i)
    z.insert(make_pair(i, 0));

  z = y;

  cout << "\nForward:\n\n";

  printContainer(x);
  cout << endl;
  printContainer(y);
  cout << endl;
  printContainer(z);
  cout << endl;

  cout << "Reverse:\n\n";

  printContainerReverse(x);
  cout << endl;
  printContainerReverse(y);
  cout << endl;
  printContainerReverse(z);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.