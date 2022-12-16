#include <iostream>

#include "dss/BinaryTree/5/BinaryTree.h"
#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/PrintBtNode/PrintBtNode.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef BinaryTree<int, int> BinaryTree;
  typedef BinaryTree::iterator Iter;

  BinaryTree t;
  PrintBtNode<BinaryTree::Node> printNode;

  Iter i5 = t.insert(makePair(5, 0)).first;
  Iter i3 = t.insert(makePair(3, 0)).first;
  t.insert(makePair(6, 0));
  Iter i1 = t.insert(makePair(1, 0)).first;
  t.insert(makePair(4, 0));
  t.insert(makePair(0, 0));
  t.insert(makePair(2, 0));

  t.rotate(i1);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  t.rotate(i1);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  t.rotate(i3);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  t.rotate(i5);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  t.rotate(i5);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  t.rotate(i3);
  traverseInOrder(t.root(), printNode);
  cout << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.