#include <iostream>
#include <utility>

#include "dss/inOrderRecursive/inOrderRecursive.h"

#include "ds2/PrintRedBlackNode/PrintRedBlackNode.h"
#include "ds2/RedBlackTree/3/RedBlackTree.h"

namespace ds2
{
char getCommandFromUser();
int getKeyValueFromUser();
};

int main()
{
  using namespace std;
  using namespace ds2;

  typedef RedBlackTree<int, int> RedBlackTree;

  RedBlackTree r;
  PrintRedBlackNode<RedBlackTree::Node> printNode;

  while (true)
  {
    char command = getCommandFromUser();

    if (command == 'i')
    {
      r.insert(make_pair(getKeyValueFromUser(), 0));
    }
    else if (command == 'e')
    {
      RedBlackTree::const_iterator trash = r.find(getKeyValueFromUser());
      if (trash != r.end())
        r.erase(trash);
      else
        cout << "\nKey value not found\n";
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
      return 0;
    }
    else
    {
      cout << "\nInvalid command\n";
    }
  }

  return 0;
}

namespace ds2
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

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.