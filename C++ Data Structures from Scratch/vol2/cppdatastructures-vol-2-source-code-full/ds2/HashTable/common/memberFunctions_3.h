namespace ds2
{
template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::iterator
HashTable<Key, Mapped, Hash, Predicate>::erase(const_iterator element)
{
  Index index = _index(element->first);
  BucketIter beforeTrash = _findIterBefore(_buckets[index], element->first);

  _buckets[index]->erase_after(beforeTrash);

  return _elements.erase(element);
}

template <class Key, class Mapped, class Hash, class Predicate>
void HashTable<Key, Mapped, Hash, Predicate>::clear()
{
  for (auto &bucket : _buckets)
    bucket->clear();

  _elements.clear();
}

template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::BucketIter
HashTable<Key, Mapped, Hash, Predicate>::_findIterBefore(Bucket* bucket,
  const key_type& key)
{
  BucketIter current = bucket->begin();
  BucketIter before = bucket->before_begin();

  while (current != bucket->end())
  {
    if (_isEqual((**current).first, key))
      break;

    ++current;
    ++before;
  }

  return before;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.