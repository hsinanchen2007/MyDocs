#include <cctype>
#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/BTree/4/BTree.h"
#include "ds2/BTreeInOrderRecursive/BTreeInOrderRecursive.h"
#include "ds2/PrintBTreeNode/PrintBTreeNode.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

namespace ds2
{
typedef BTree<Traceable<int>, int> _BTree;

void getKeyAndEraseElement(_BTree& b);
};

int main()
{
  using namespace std;
  using namespace ds2;

  _BTree b;

  for (int i = 0; i != 46; i += 2)
    b.insert(make_pair(i, 0));

  b.insert(make_pair(1, 0));
  b.insert(make_pair(13, 0));
  cout << endl;

  dss::printContainer(b);
  cout << endl;

  while (true)
  {
    cout << "(e)rase (q)uit: ";

    char command;
    cin >> command;
    command = toupper(command);

    if (command == 'Q')
      break;
    else if (command == 'E')
      getKeyAndEraseElement(b);
    else
      cout << "\nInvalid command\n\n";
  }

  cout << endl;

  return 0;
}

namespace ds2
{
void getKeyAndEraseElement(_BTree& b)
{
  using namespace std;

  cout << "\nKey: ";

  int key;
  cin >> key;

  _BTree::const_iterator i = b.find(key);

  if (i != b.end())
  {
    cout << "\nErasing element " << *i << "...\n\n";

    i = b.erase(i);

    cout << "\nNext element = ";

    if (i != b.end())
      cout << *i;
    else
      cout << "end";

    cout << "\n\nForward:\n";
    dss::printContainer(b);

    cout << "\nReverse:\n";
    dss::printContainerReverse(b);
    cout << endl;

    traverseBTreeInOrder(b.root(), PrintBTreeNode<_BTree::Node>());
  }
  else
  {
    cout << "\nKey " << key << " not found\n\n";
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.