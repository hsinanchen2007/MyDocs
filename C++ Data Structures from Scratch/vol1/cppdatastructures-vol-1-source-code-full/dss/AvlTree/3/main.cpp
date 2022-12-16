#include <iostream>

#include "dss/AvlTree/3/AvlTree.h"
#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/PrintAvlNode/PrintAvlNode.h"

namespace dss
{
char getCommandFromUser();
int getKeyValueFromUser();
};

int main()
{
  using namespace std;
  using namespace dss;

  typedef AvlTree<int, int> AvlTree;

  AvlTree t;
  PrintAvlNode<AvlTree::Node> printNode;

  while (true)
  {
    char command = getCommandFromUser();

    if (command == 'i')
    {
      t.insert(makePair(getKeyValueFromUser(), 0));
    }
    else if (command == 'e')
    {
      AvlTree::const_iterator trash = t.find(getKeyValueFromUser());
      if (trash != t.end())
        t.erase(trash);
      else
        cout << "\nKey value not found\n";
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
      return 0;
    }
    else
    {
      cout << "\nInvalid command\n";
    }
  }

  return 0;
}

namespace dss
{
char getCommandFromUser()
{
  char command;
  std::cout << "\n(i)nsert, (e)rase, (p)rint, (c)lear, (q)uit: ";
  std::cin >> command;

  return command;
}

int getKeyValueFromUser()
{
  int keyValue;
  std::cout << "\nEnter key value: ";
  std::cin >> keyValue;

  return keyValue;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.