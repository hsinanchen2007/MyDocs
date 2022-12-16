#include <iostream>

#include "dss/printContainer/printContainer.h"

#include "ds2/BTree/3/BTree.h"
#include "ds2/stdPairIo/stdPairIo.h"

namespace ds2
{
typedef BTree<int, int> _BTree;

void getKeyAndInsertElement(_BTree& b);
void getKeyAndFindElement(const _BTree& b);
};

int main()
{
  using namespace std;
  using namespace ds2;

  _BTree b;

  while (true)
  {
    cout << "\n(i)nsert (f)ind (q)uit: ";

    char command;
    cin >> command;
    command = toupper(command);

    if (command == 'Q')
      break;
    else if (command == 'I')
      getKeyAndInsertElement(b);
    else if (command == 'F')
      getKeyAndFindElement(b);
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

  pair<_BTree::const_iterator, bool> p = b.insert(make_pair(key, 0));

  if (p.second == true)
    cout << "\nInserted element " << *p.first;
  else
    cout << "\nElement " << *p.first << " already exists";

  cout << "\n\nForward:\n";
  dss::printContainer(b);
  cout << endl;

  cout << "Reverse:\n";
  dss::printContainerReverse(b);
}

void getKeyAndFindElement(const _BTree& b)
{
  using namespace std;

  cout << "\nKey: ";

  int key;
  cin >> key;

  _BTree::const_iterator i = b.find(key);

  if (i != b.end())
    cout << "\nFound element " << *i << endl;
  else
    cout << "\nKey " << key << " not found\n";
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.