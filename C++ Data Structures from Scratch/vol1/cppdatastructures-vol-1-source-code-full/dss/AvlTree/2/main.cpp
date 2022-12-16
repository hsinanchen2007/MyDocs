#include <iostream>

#include "dss/AvlTree/2/AvlTree.h"
#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/PrintAvlNode/PrintAvlNode.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef AvlTree<int, int> AvlTree;

  AvlTree t;
  PrintAvlNode<AvlTree::Node> printNode;

  while (true)
  {
    char command;
    cout << "\n(i)nsert, (p)rint, (c)lear, (q)uit: ";
    cin >> command;

    if (command == 'i')
    {
      int keyValue;
      cout << "\nEnter key value (int): ";
      cin >> keyValue;

      t.insert(makePair(keyValue, 0));
    }
    else if (command == 'p')
    {
      cout << endl;
      traverseInOrder(t.root(), printNode);
    }
    else if (command == 'c')
    {
      t.clear();
    }
    else if (command == 'q')
    {
      break;
    }
    else
    {
      cout << "\nInvalid command\n";
    }
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.