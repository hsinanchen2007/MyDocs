#include <iostream>

#include "dss/DemoBinaryTree/1/DemoBinaryTree.h"
#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/Pair/PairIo.h"
#include "dss/PrintBtNode/PrintBtNode.h"

int main()
{
  using namespace std;
  using namespace dss;

  DemoBinaryTree t;
  PrintBtNode<DemoBinaryTree::Node> printNode;

  traverseInOrder(t.root(), printNode);

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.