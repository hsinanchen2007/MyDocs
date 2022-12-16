#ifndef DSS_INORDERRECURSIVE_INORDERRECURSIVE
#define DSS_INORDERRECURSIVE_INORDERRECURSIVE

namespace dss
{
template <class Node, class Function>
void traverseInOrder(Node* n, Function visit);

template <class Node, class Function>
void traverseInOrder(Node* n, Function visit)
{
  if (n != nullptr)
  {
    traverseInOrder(n->left, visit);
    visit(n);
    traverseInOrder(n->right, visit);
  }
}
};

#endif // DSS_INORDERRECURSIVE_INORDERRECURSIVE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.