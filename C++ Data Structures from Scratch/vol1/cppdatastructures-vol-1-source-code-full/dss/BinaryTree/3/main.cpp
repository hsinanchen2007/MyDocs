#include <iostream>

#include "dss/BinaryTree/3/BinaryTree.h"
#include "dss/checkBtIntegrity/checkBtIntegrity.h"
#include "dss/Pair/PairIo.h"
#include "dss/PrintBtNode/PrintBtNode.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef BinaryTree<Traceable<int>, int> BinaryTree;

  BinaryTree t;
  BinaryTree::iterator i;
  PrintBtNode<BinaryTree::Node> printNode;

  t.insert(makePair(21, 0));
  t.insert(makePair(9, 0));
  t.insert(makePair(33, 0));
  t.insert(makePair(3, 0));
  t.insert(makePair(15, 0));
  t.insert(makePair(27, 0));
  cout << endl;

  cout << "Erasing element " << *t.begin() << "...\n";
  i = t.erase(t.begin());
  cout << "The next element is " << *i << endl << endl;
  checkBtIntegrity(t, printNode);

  i = t.find(33);
  cout << "Erasing element " << *i << "...\n";
  i = t.erase(i);

  if (i == t.end())
    cout << "The next element is null\n\n";

  checkBtIntegrity(t, printNode);

  i = t.find(21);
  cout << "Erasing element " << *i << "...\n";
  i = t.erase(i);
  cout << "The next element is " << *i << endl << endl;
  checkBtIntegrity(t, printNode);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.