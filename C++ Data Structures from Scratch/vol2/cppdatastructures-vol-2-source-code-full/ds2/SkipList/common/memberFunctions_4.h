namespace ds2
{
template <class Key, class Mapped, class Predicate>
typename SkipList<Key, Mapped, Predicate>::iterator
SkipList<Key, Mapped, Predicate>::erase(const_iterator element)
{
  Node* trash = element._i._node;
  Node* next = trash->right[0];
  LinkVector rightLinks;

  _findRightLinksOnErase(trash, rightLinks);
  _detachNode(trash, rightLinks);

  ++_availableNodes[trash->topLevel()];
  --_size;

  _destroyNode(trash);

  return iterator(this, next);
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::_findRightLinksOnErase(Node* trash,
  LinkVector& rightLinks)
{
  rightLinks.resize(trash->topLevel() + 1);

  SignedLevel currentLevel = trash->topLevel();
  Node* n = _head[currentLevel];
  NodeVector* v = &_head;

  while (true)
  {
    if (n == trash)
    {
      rightLinks[currentLevel] = &(*v)[currentLevel];
      --currentLevel;

      if (currentLevel < 0)
        break;

      n = (*v)[currentLevel];
      continue;
    }

    v = &n->right;
    n = n->right[currentLevel];
  }
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::_detachNode(Node* trash,
  const LinkVector& rightLinks)
{
  if (trash == _tail)
    _tail = trash->left;
  else
    trash->right[0]->left = trash->left;

  for (Level i = 0; i <= trash->topLevel(); ++i)
    *rightLinks[i] = trash->right[i];
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.