namespace dss
{
template <class T>
typename List<T>::iterator List<T>::insert(const_iterator insertionPoint,
  const T& source)
{
  if (insertionPoint == begin())
  {
    push_front(source);

    return iterator(this, _head);
  }
  else if (insertionPoint == end())
  {
    push_back(source);

    return iterator(this, _tail);
  }
  else
  {
    Node* newNode = _createNode(source);

    Node* leftNeighbor = insertionPoint._i._node->left;
    Node* rightNeighbor = insertionPoint._i._node;

    newNode->left = leftNeighbor;
    newNode->right = rightNeighbor;

    leftNeighbor->right = newNode;
    rightNeighbor->left = newNode;

    ++_size;

    return iterator(this, newNode);
  }
}

template <class T>
typename List<T>::iterator List<T>::erase(const_iterator erasurePoint)
{
  if (erasurePoint == begin())
  {
    pop_front();

    return iterator(this, _head);
  }
  else if (erasurePoint._i._node == _tail)
  {
    pop_back();

    return end();
  }
  else
  {
    Node* trash = erasurePoint._i._node;
    Node* leftNeighbor = trash->left;
    Node* rightNeighbor = trash->right;

    _destroyNode(trash);
    --_size;

    leftNeighbor->right = rightNeighbor;
    rightNeighbor->left = leftNeighbor;

    return iterator(this, rightNeighbor);
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.