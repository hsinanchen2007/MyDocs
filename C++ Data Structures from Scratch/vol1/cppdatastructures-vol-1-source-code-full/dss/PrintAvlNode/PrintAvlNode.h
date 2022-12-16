#ifndef DSS_PRINTAVLNODE_PRINTAVLNODE
#define DSS_PRINTAVLNODE_PRINTAVLNODE

#include <iostream>

#include "dss/PrintBtNode/PrintBtNode.h"

namespace dss
{
template <class Node>
class PrintAvlNode
{
 public:
  void operator()(const Node* n) const;

 private:
  PrintBtNode<Node> _printBtNode;
};

template <class Node>
void PrintAvlNode<Node>::operator()(const Node* n) const
{
  using namespace std;

  _printBtNode(n);

  cout << "  balanceFactor " << n->balanceFactor << endl;
}
};

#endif // DSS_PRINTAVLNODE_PRINTAVLNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.