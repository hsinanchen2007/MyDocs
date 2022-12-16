namespace ds2
{
template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::const_local_iterator
HashTable<Key, Mapped, Hash, Predicate>::begin(size_type index) const
{
  return _buckets[index]->begin();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::const_local_iterator
HashTable<Key, Mapped, Hash, Predicate>::end(size_type index) const
{
  return _buckets[index]->end();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::const_iterator
HashTable<Key, Mapped, Hash, Predicate>::find(const key_type& key) const
{
  return const_cast<HashTable*>(this)->find(key);
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::local_iterator
HashTable<Key, Mapped, Hash, Predicate>::begin(size_type index)
{
  return _buckets[index]->begin();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::local_iterator
HashTable<Key, Mapped, Hash, Predicate>::end(size_type index)
{
  return _buckets[index]->end();
}

template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::iterator
HashTable<Key, Mapped, Hash, Predicate>::find(const key_type& key)
{
  Index index = _index(key);
  BucketIter iter = _findIter(_buckets[index], key);

  if (iter != _buckets[index]->end())
    return *iter;
  else
    return end();
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.