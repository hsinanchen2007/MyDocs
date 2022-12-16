#include "dss/predicates/predicates.h"

namespace ds2
{
template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_iterator
SkipList<Key, Mapped, Predicate>::begin() const
{
  return const_cast<SkipList*>(this)->begin();
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_iterator
SkipList<Key, Mapped, Predicate>::end() const
{
  return const_cast<SkipList*>(this)->end();
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_reverse_iterator
SkipList<Key, Mapped, Predicate>::rbegin() const
{
  return const_reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_reverse_iterator
SkipList<Key, Mapped, Predicate>::rend() const
{
  return const_reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::const_iterator
SkipList<Key, Mapped, Predicate>::find(const key_type& key) const
{
  return const_cast<SkipList*>(this)->find(key);
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::iterator
SkipList<Key, Mapped, Predicate>::begin()
{
  return iterator(this, _head[0]);
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::iterator
SkipList<Key, Mapped, Predicate>::end()
{
  return iterator(this, nullptr);
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::reverse_iterator
SkipList<Key, Mapped, Predicate>::rbegin()
{
  return reverse_iterator(end());
}

template <class Key, class Mapped, class Predicate>
inline typename SkipList<Key, Mapped, Predicate>::reverse_iterator
SkipList<Key, Mapped, Predicate>::rend()
{
  return reverse_iterator(begin());
}

template <class Key, class Mapped, class Predicate>
typename SkipList<Key, Mapped, Predicate>::iterator
SkipList<Key, Mapped, Predicate>::find(const key_type& key)
{
  SignedLevel currentLevel = topLevel();
  Node* n = _head[currentLevel];
  NodeVector* v = &_head;

  while (true)
  {
    if (n != nullptr &&
      dss::isReflexivelyEqual(n->element.first, key, _predicate))
    {
      return iterator(this, n);
    }

    if (n != nullptr && _predicate(n->element.first, key))
    {
      v = &n->right;
      n = n->right[currentLevel];

      continue;
    }

    --currentLevel;

    if (currentLevel < 0 )
      return end();

    n = (*v)[currentLevel];
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.