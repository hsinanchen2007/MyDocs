#ifndef DS2_BTREEINORDERRECURSIVE_BTREEINORDERRECURSIVE
#define DS2_BTREEINORDERRECURSIVE_BTREEINORDERRECURSIVE

namespace ds2
{
template <class Node, class Function>
void traverseBTreeInOrder(const Node* n, Function visit);

template <class Node, class Function>
void traverseBTreeInOrder(const Node* n, Function visit)
{
  if (n != nullptr)
  {
    for (typename Node::Index i = 0; i != n->totalElements(); ++i)
    {
      if (n->hasLeftChild(i))
        traverseBTreeInOrder(n->leftChild(i), visit);

      visit(n, i);

      if (i == n->backElementIndex() && n->hasRightChild(i))
        traverseBTreeInOrder(n->rightChild(i), visit);
    }
  }
}
};

#endif // DS2_BTREEINORDERRECURSIVE_BTREEINORDERRECURSIVE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.