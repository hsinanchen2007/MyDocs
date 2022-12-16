#include <cctype>
#include <iostream>

#include "ds2/BTree/1/BTree.h"
#include "ds2/BTreeInOrderRecursive/BTreeInOrderRecursive.h"
#include "ds2/PrintBTreeNode/PrintBTreeNode.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

namespace ds2
{
typedef BTree<Traceable<int>, int> _BTree;

void getKeyAndInsertElement(_BTree& b);
};

int main()
{
  using namespace std;
  using namespace ds2;

  _BTree b;

  while (true)
  {
    cout << "\n(i)nsert (q)uit: ";

    char command;
    cin >> command;
    command = toupper(command);

    if (command == 'Q')
      break;
    else if (command == 'I')
      getKeyAndInsertElement(b);
    else
      cout << "\nInvalid command\n";
  }

  cout << endl;

  return 0;
}

namespace ds2
{
void getKeyAndInsertElement(_BTree& b)
{
  using namespace std;

  cout << "\nKey: ";

  int key;
  cin >> key;
  _BTree::value_type newElement = make_pair(key, 0);

  cout << "\nInserting element " << newElement << "...\n\n";

  b.insert(newElement);
  cout << endl;

  traverseBTreeInOrder(b.root(), PrintBTreeNode<_BTree::Node>());

  cout << "Front element = " << b.front() << endl;
  cout << "Back element = " << b.back() << endl << endl;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.