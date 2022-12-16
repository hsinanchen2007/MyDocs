#include <iostream>

#include "dss/DemoBinaryTree/1/DemoBinaryTree.h"
#include "dss/inOrderIterative/inOrderIterative.h"
#include "dss/Pair/PairIo.h"

int main()
{
  using namespace std;
  using namespace dss;

  DemoBinaryTree t;

  for (const DemoBinaryTree::Node* n = t.head();
    n != nullptr;
    n = inOrderSuccessor(n))
  {
    cout << n->element << ' ';
  }

  cout << endl << endl;

  for (const DemoBinaryTree::Node* n = t.tail();
    n != nullptr;
    n = inOrderPredecessor(n))
  {
    cout << n->element << ' ';
  }

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.