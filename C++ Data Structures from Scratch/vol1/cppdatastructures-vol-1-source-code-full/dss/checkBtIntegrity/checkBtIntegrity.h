#ifndef DSS_CHECKBTINTEGRITY_CHECKBTINTEGRITY
#define DSS_CHECKBTINTEGRITY_CHECKBTINTEGRITY

#include <iostream>

#include "dss/inOrderRecursive/inOrderRecursive.h"
#include "dss/printContainer/printContainer.h"

namespace dss
{
template <class Tree, class Function>
void checkBtIntegrity(const Tree& tree, Function printNode);

template <class Tree, class Function>
void checkBtIntegrity(const Tree& tree, Function printNode)
{
  using namespace std;

  printContainer(tree);
  printContainerReverse(tree);
  cout << endl;

  traverseInOrder(tree.root(), printNode);
  cout << endl;
}
};

#endif // DSS_CHECKBTINTEGRITY_CHECKBTINTEGRITY

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.