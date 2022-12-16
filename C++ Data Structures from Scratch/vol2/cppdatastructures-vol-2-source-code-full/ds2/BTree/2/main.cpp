#include <iostream>

#include "ds2/BTree/2/BTree.h"
#include "ds2/BTreeInOrderIterative/BTreeInOrderIterative.h"

int main()
{
  using namespace std;
  using namespace ds2;

  typedef BTree<int, int> BTree;
  typedef BTree::Location Location;

  BTree b;

  for (int i = 0; i != 26; ++i)
    b.insert(make_pair(i, 0));

  cout << "\nIn-order successors:\n";

  for (Location current(b.head(), 0);
    current.node != nullptr;
    current = bTreeInOrderSuccessor(current))
  {
    cout << current.node->key(current.index) << ' ';
  }

  cout << "\n\nIn-order predecessors:\n";

  for (Location current(b.tail(), b.tail()->backElementIndex());
    current.node != nullptr;
    current = bTreeInOrderPredecessor(current))
  {
    cout << current.node->key(current.index) << ' ';
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.