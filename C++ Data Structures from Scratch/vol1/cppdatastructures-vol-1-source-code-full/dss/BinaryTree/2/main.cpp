#include <iostream>

#include "dss/BinaryTree/2/BinaryTree.h"
#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/Pair/PairIo.h"
#include "dss/PrintBtNode/PrintBtNode.h"
#include "dss/printContainer/printContainer.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef BinaryTree<Traceable<int>, int> BinaryTree;

  BinaryTree t;

  t.insert(makePair(21, 0));
  cout << endl;

  t.insert(makePair(9, 0));
  cout << endl;

  t.insert(makePair(33, 0));
  cout << endl;

  t.insert(makePair(15, 0));
  cout << endl;

  t.insert(makePair(39, 0));
  cout << endl;

  Pair<BinaryTree::iterator, bool> p = t.insert(makePair(9, 1));
  cout << endl;

  if (p.second == false)
    cout << "The tree already contains element " << *p.first << endl;

  cout << "\nt contains " << t.size() << " elements:\n";
  printContainer(t);

  cout << "\nThe reverse sequence is:\n";
  printContainerReverse(t);
  cout << endl;

  traverseInOrder(t.root(), PrintBtNode<BinaryTree::Node>());
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.