#include "dss/predicates/predicates.h"

namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_iterator
BTree<Key, Mapped, KeyPred, Order>::begin() const
{
  return const_cast<BTree*>(this)->begin();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_iterator
BTree<Key, Mapped, KeyPred, Order>::end() const
{
  return const_cast<BTree*>(this)->end();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_reverse_iterator
BTree<Key, Mapped, KeyPred, Order>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_reverse_iterator
BTree<Key, Mapped, KeyPred, Order>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::const_iterator
BTree<Key, Mapped, KeyPred, Order>::find(const key_type& key) const
{
  return const_cast<BTree*>(this)->find(key);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::iterator
BTree<Key, Mapped, KeyPred, Order>::begin()
{
  return iterator(this, Location(_head, 0));
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::iterator
BTree<Key, Mapped, KeyPred, Order>::end()
{
  return iterator(this, Location(nullptr, 0));
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::reverse_iterator
BTree<Key, Mapped, KeyPred, Order>::rbegin()
{
  return reverse_iterator(end());
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::reverse_iterator
BTree<Key, Mapped, KeyPred, Order>::rend()
{
  return reverse_iterator(begin());
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTree<Key, Mapped, KeyPred, Order>::iterator
BTree<Key, Mapped, KeyPred, Order>::find(const key_type& key)
{
  return iterator(this, _location(key));
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTree<Key, Mapped, KeyPred, Order>::Location
BTree<Key, Mapped, KeyPred, Order>::_location(const key_type& key) const
{
  Node* n = _root;

  while (n != nullptr)
  {
    Index i = n->lowerBound(key);

    if (n->hasElement(i) &&
      dss::isReflexivelyEqual(n->key(i), key, _keyPred))
    {
      return Location(n, i);
    }
    else if (n->hasLeftChild(i))
    {
      n = n->leftChild(i);
    }
    else
    {
      break;
    }
  }

  return Location(nullptr, 0);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.