namespace dss
{
template <class Key, class Mapped, class Predicate>
typename AvlTree<Key, Mapped, Predicate>::Node*
AvlTree<Key, Mapped, Predicate>::_copyNode(Node* sourceNode, Node* newParent)
{
  if (sourceNode != nullptr)
  {
    Node* newNode = _createNode(sourceNode->element);

    newNode->parent = newParent;
    newNode->left = _copyNode(sourceNode->left, newNode);
    newNode->right = _copyNode(sourceNode->right, newNode);
    newNode->balanceFactor = sourceNode->balanceFactor;

    return newNode;
  }
  else
  {
    return nullptr;
  }
}

template <class Key, class Mapped, class Predicate>
void AvlTree<Key, Mapped, Predicate>::_overwriteElement(Node* n,
  const value_type& sourceElement)
{
  Node temp(sourceElement);

  temp.parent = n->parent;
  temp.left = n->left;
  temp.right = n->right;
  temp.predecessor = n->predecessor;
  temp.successor = n->successor;
  temp.balanceFactor = n->balanceFactor;

  _alloc.destroy(n);
  _alloc.construct(n, temp);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.