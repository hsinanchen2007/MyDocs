#ifndef DSS_BT_ATTACHNEWNODE
#define DSS_BT_ATTACHNEWNODE

#include "dss/bt/key.h"
#include "dss/bt/relatives.h"
#include "dss/inOrderIterative/inOrderIterative.h"

namespace dss
{
namespace bt
{
template <class Node, class Predicate>
void attachNewNode(Node* newNode, Node* insertionPoint, Predicate predicate);

template <class Node, class Predicate>
void attachNewNode(Node* newNode, Node* insertionPoint, Predicate predicate)
{
  newNode->parent = insertionPoint;

  if (predicate(key(newNode), key(insertionPoint)))
    insertionPoint->left = newNode;
  else
    insertionPoint->right = newNode;

  newNode->predecessor = inOrderPredecessor(newNode);

  if (hasPredecessor(newNode))
    newNode->predecessor->successor = newNode;

  newNode->successor = inOrderSuccessor(newNode);

  if (hasSuccessor(newNode))
    newNode->successor->predecessor = newNode;
}
};
};

#endif // DSS_BT_ATTACHNEWNODE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.