namespace ds2
{
template <class Key, class Mapped, class Predicate>
typename RedBlackTree<Key, Mapped, Predicate>::Node*
RedBlackTree<Key, Mapped, Predicate>::_copyNode(Node* sourceNode,
  Node* newParent)
{
  if (sourceNode != nullptr)
  {
    Node* newNode = _createNode(sourceNode->element);

    newNode->parent = newParent;
    newNode->left = _copyNode(sourceNode->left, newNode);
    newNode->right = _copyNode(sourceNode->right, newNode);

    newNode->matchColor(*sourceNode);

    return newNode;
  }
  else
  {
    return nullptr;
  }
}

template <class Key, class Mapped, class Predicate>
void RedBlackTree<Key, Mapped, Predicate>::_overwriteElement(Node* n,
  const value_type& sourceElement)
{
  Node temp(sourceElement);

  temp.parent = n->parent;
  temp.left = n->left;
  temp.right = n->right;
  temp.predecessor = n->predecessor;
  temp.successor = n->successor;

  temp.matchColor(*n);

  _alloc.destroy(n);
  _alloc.construct(n, temp);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.