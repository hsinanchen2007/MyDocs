#ifndef DS2_PRINTREDBLACKNODE_PRINTREDBLACKNODE
#define DS2_PRINTREDBLACKNODE_PRINTREDBLACKNODE

#include <iostream>

#include "dss/PrintBtNode/PrintBtNode.h"

namespace ds2
{
template <class Node>
class PrintRedBlackNode
{
 public:
  void operator()(const Node* n) const;

 private:
  dss::PrintBtNode<Node> _printBtNode;
};

template <class Node>
void PrintRedBlackNode<Node>::operator()(const Node* n) const
{
  using namespace std;

  _printBtNode(n);

  if (n->isRed())
    cout << "  red\n";
  else
    cout << "  black\n";
}
};

#endif // DS2_PRINTREDBLACKNODE_PRINTREDBLACKNODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.