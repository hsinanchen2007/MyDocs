#ifndef DS2_BTREEINORDERITERATIVE_BTREEINORDERITERATIVE
#define DS2_BTREEINORDERITERATIVE_BTREEINORDERITERATIVE

namespace ds2
{
template <class Location>
Location bTreeInOrderPredecessor(Location current);

template <class Location>
Location bTreeInOrderSuccessor(Location current);

template <class Location>
Location bTreeInOrderPredecessor(Location current)
{
  typedef typename Location::Node Node;

  Node* n = current.node;
  typename Location::Index i = current.index;

  if (!n->isLeaf())
  {
    n = n->leftChild(i);

    while (!n->isLeaf())
      n = n->rightChild(n->backElementIndex());

    return Location(n, n->backElementIndex());
  }
  else if (i != 0)
  {
    return Location(n, --i);
  }
  else if (n->isRightChild())
  {
    return Location(n->parent(),
      n->parent()->lowerBound(n->key(i)) - 1);
  }
  else
  {
    for (Node* p = n->parent(); p != nullptr; p = p->parent())
      if (p->isRightChild())
        return Location(p->parent(),
          p->parent()->lowerBound(n->key(i)) - 1);

    return Location(nullptr, 0);
  }
}

template <class Location>
Location bTreeInOrderSuccessor(Location current)
{
  typedef typename Location::Node Node;

  Node* n = current.node;
  typename Location::Index i = current.index;

  if (!n->isLeaf())
  {
    n = n->rightChild(i);

    while (!n->isLeaf())
      n = n->leftChild(0);

    return Location(n, 0);
  }
  else if (i != n->backElementIndex())
  {
    return Location(n, ++i);
  }
  else if (n->isLeftChild())
  {
    return Location(n->parent(),
      n->parent()->lowerBound(n->key(i)));
  }
  else
  {
    for (Node* p = n->parent(); p != nullptr; p = p->parent())
      if (p->isLeftChild())
        return Location(p->parent(),
          p->parent()->lowerBound(n->key(i)));

    return Location(nullptr, 0);
  }
}
};

#endif // DS2_BTREEINORDERITERATIVE_BTREEINORDERITERATIVE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.