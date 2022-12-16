#ifndef DS2_PRINTBTREENODE_PRINTBTREENODE
#define DS2_PRINTBTREENODE_PRINTBTREENODE

#include <iostream>

namespace ds2
{
template <class Node>
struct PrintBTreeNode
{
  typedef typename Node::Index Index;

  void operator()(const Node* n, Index element);
};

template <class Node>
void PrintBTreeNode<Node>::operator()(const Node* n, Index element)
{
  using namespace std;

  cout << "key              " << n->key(element) << endl;

  if (!n->isRoot())
    cout << "  parent->front  " << n->parent()->key(0) << endl;

  if (n->hasLeftChild(element))
    cout << "  left           " << n->leftChild(element)->key(0) << endl;

  if (n->hasRightChild(element))
    cout << "  right          " << n->rightChild(element)->key(0) << endl;

  cout << endl;
}
};

#endif // DS2_PRINTBTREENODE_PRINTBTREENODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.