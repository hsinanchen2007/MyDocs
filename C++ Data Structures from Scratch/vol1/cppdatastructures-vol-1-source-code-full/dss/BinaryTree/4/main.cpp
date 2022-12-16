#include <iostream>

#include "dss/BinaryTree/4/BinaryTree.h"
#include "dss/checkBtIntegrity/checkBtIntegrity.h"
#include "dss/Pair/PairIo.h"
#include "dss/PrintBtNode/PrintBtNode.h"
#include "dss/Traceable/Traceable.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef BinaryTree<Traceable<int>, int> BinaryTree;

  PrintBtNode<BinaryTree::Node> printNode;

  BinaryTree a;
  a.insert(makePair(9, 0));
  a.insert(makePair(3, 0));
  a.insert(makePair(15, 0));
  a.insert(makePair(6, 0));
  a.insert(makePair(12, 0));
  cout << endl;

  BinaryTree b(a);
  cout << endl;
  checkBtIntegrity(b, printNode);

  BinaryTree c;
  c.insert(makePair(2, 0));
  c.insert(makePair(0, 0));
  c.insert(makePair(4, 0));
  cout << endl;

  a = c;
  cout << endl;
  checkBtIntegrity(c, printNode);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.