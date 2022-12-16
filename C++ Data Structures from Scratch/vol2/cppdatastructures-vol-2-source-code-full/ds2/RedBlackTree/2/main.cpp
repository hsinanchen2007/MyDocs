#include <iostream>
#include <utility>

#include "dss/inOrderRecursive/inOrderRecursive.h"

#include "ds2/PrintRedBlackNode/PrintRedBlackNode.h"
#include "ds2/RedBlackTree/2/RedBlackTree.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef RedBlackTree<int, int> RedBlackTree;

  RedBlackTree r;
  PrintRedBlackNode<RedBlackTree::Node> printNode;

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

      r.insert(make_pair(keyValue, 0));
    }
    else if (command == 'p')
    {
      cout << endl;
      dss::traverseInOrder(r.root(), printNode);
    }
    else if (command == 'c')
    {
      r.clear();
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

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.