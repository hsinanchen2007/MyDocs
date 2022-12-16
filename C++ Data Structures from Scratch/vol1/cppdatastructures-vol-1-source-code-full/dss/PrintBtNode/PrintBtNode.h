#ifndef DSS_DSS_PRINTBTNODE_PRINTBTNODE
#define DSS_DSS_PRINTBTNODE_PRINTBTNODE

#include <iostream>

#include "dss/bt/key.h"
#include "dss/bt/relatives.h"

namespace dss
{
template <class Node>
struct PrintBtNode
{
  void operator()(const Node* n) const;
};

template <class Node>
void PrintBtNode<Node>::operator()(const Node* n) const
{
  using namespace std;
  using namespace bt;

  cout << "node " << key(n) << endl;

  if (!isRoot(n))
    cout << "  parent " << key(n->parent) << endl;

  if (hasLeftChild(n))
    cout << "  left " << key(n->left) << endl;

  if (hasRightChild(n))
    cout << "  right " << key(n->right) << endl;
}
};

#endif // DSS_DSS_PRINTBTNODE_PRINTBTNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.