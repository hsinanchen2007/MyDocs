#ifndef DSS_BT_ROTATE
#define DSS_BT_ROTATE

#include "dss/bt/relatives.h"

namespace dss
{
namespace bt
{
template <class Node>
void rotateLeft(Node* n, Node** root);

template <class Node>
void rotateRight(Node* n, Node** root);

template <class Node>
void rotateLeft(Node* n, Node** root)
{
  Node* n3 = n;
  Node* n2 = n3->left;
  Node* n1 = n3->parent;
  Node* n4 = n3->parent->parent;

  n3->parent = n4;
  if (isLeftChild(n1))
    n4->left = n3;
  else if (isRightChild(n1))
    n4->right = n3;
  else
    *root = n3;

  n1->parent = n3;
  n3->left = n1;

  n1->right = n2;
  if (n2 != nullptr)
    n2->parent = n1;
}

template <class Node>
void rotateRight(Node* n, Node** root)
{
  Node* n1 = n;
  Node* n2 = n1->right;
  Node* n3 = n1->parent;
  Node* n4 = n1->parent->parent;

  n1->parent = n4;
  if (isLeftChild(n3))
    n4->left = n1;
  else if (isRightChild(n3))
    n4->right = n1;
  else
    *root = n1;

  n3->parent = n1;
  n1->right = n3;

  n3->left = n2;
  if (n2 != nullptr)
    n2->parent = n3;
}
};
};

#endif // DSS_BT_ROTATE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.