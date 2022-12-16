#include <cmath>

namespace ds2
{
template <class Key, class Mapped, class Hash, class Predicate>
HashTable<Key, Mapped, Hash, Predicate>::HashTable():
  _maxLoadFactor(1.0),
  _buckets(10, nullptr)
{
  for (auto& bucket : _buckets)
    bucket = _createBucket();
}

template <class Key, class Mapped, class Hash, class Predicate>
HashTable<Key, Mapped, Hash, Predicate>::~HashTable()
{
  for (auto& bucket : _buckets)
    _destroyBucket(bucket);
}

template <class Key, class Mapped, class Hash, class Predicate>
inline bool HashTable<Key, Mapped, Hash, Predicate>::empty() const
{
  return _elements.empty();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::size_type
HashTable<Key, Mapped, Hash, Predicate>::size() const
{
  return _elements.size();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::size_type
HashTable<Key, Mapped, Hash, Predicate>::bucket(const key_type& key) const
{
  return _index(key);
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::size_type
HashTable<Key, Mapped, Hash, Predicate>::bucket_count() const
{
  return _buckets.size();
}

template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::size_type
HashTable<Key, Mapped, Hash, Predicate>::bucket_size(size_type index) const
{
  return _buckets[index]->size();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::const_iterator
HashTable<Key, Mapped, Hash, Predicate>::begin() const
{
  return _elements.begin();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::const_iterator
HashTable<Key, Mapped, Hash, Predicate>::end() const
{
  return _elements.end();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::hasher
HashTable<Key, Mapped, Hash, Predicate>::hash_function() const
{
  return _hash;
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::key_equal
HashTable<Key, Mapped, Hash, Predicate>::key_eq() const
{
  return _isEqual;
}

template <class Key, class Mapped, class Hash, class Predicate>
inline float HashTable<Key, Mapped, Hash, Predicate>::load_factor() const
{
  return static_cast<float>(size()) / bucket_count();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline float HashTable<Key, Mapped, Hash, Predicate>::max_load_factor() const
{
  return _maxLoadFactor;
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::iterator
HashTable<Key, Mapped, Hash, Predicate>::begin()
{
  return _elements.begin();
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::iterator
HashTable<Key, Mapped, Hash, Predicate>::end()
{
  return _elements.end();
}

template <class Key, class Mapped, class Hash, class Predicate>
std::pair<typename HashTable<Key, Mapped, Hash, Predicate>::iterator, bool>
HashTable<Key, Mapped, Hash, Predicate>::insert(const value_type& newElement)
{
  Index index = _index(newElement.first);

  BucketIter preexistingElement = _findIter(_buckets[index], newElement.first);

  if (preexistingElement != _buckets[index]->end())
    return std::make_pair(*preexistingElement, false);

  if (size() == _capacity())
  {
    size_type newCapacity = static_cast<size_type>(1.5 * (_capacity() + 2));

    size_type newBucketCount = static_cast<size_type>(
      std::ceil(newCapacity / _maxLoadFactor));

    _rehash(newBucketCount);

    index = _index(newElement.first);
  }

  _elements.push_front(newElement);

  iterator iterNewElement = _elements.begin();
  _buckets[index]->push_front(iterNewElement);

  return std::make_pair(iterNewElement, true);
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::size_type
HashTable<Key, Mapped, Hash, Predicate>::_capacity() const
{
  return static_cast<size_type>(bucket_count() * _maxLoadFactor);
}

template <class Key, class Mapped, class Hash, class Predicate>
inline typename HashTable<Key, Mapped, Hash, Predicate>::Index
HashTable<Key, Mapped, Hash, Predicate>::_index(const key_type& key) const
{
  return _hash(key) % bucket_count();
}

template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::BucketIter
HashTable<Key, Mapped, Hash, Predicate>::_findIter(Bucket* bucket,
  const key_type& key)
{
  BucketIter i = bucket->begin();

  while (i != bucket->end())
  {
    if (_isEqual((**i).first, key))
      break;

    ++i;
  }

  return i;
}

template <class Key, class Mapped, class Hash, class Predicate>
void HashTable<Key, Mapped, Hash, Predicate>::_rehash(size_type newBucketCount)
{
  for (auto &bucket : _buckets)
    bucket->clear();

  while (_buckets.size() != newBucketCount)
    _buckets.push_back(_createBucket());

  for (iterator i = _elements.begin(); i != _elements.end(); ++i)
  {
    Index newIndex = _index(i->first);
    _buckets[newIndex]->push_front(i);
  }
}

template <class Key, class Mapped, class Hash, class Predicate>
typename HashTable<Key, Mapped, Hash, Predicate>::Bucket*
HashTable<Key, Mapped, Hash, Predicate>::_createBucket()
{
  Bucket* newBucket = _alloc.allocate(1);
  _alloc.construct(newBucket, Bucket());

  return newBucket;
}

template <class Key, class Mapped, class Hash, class Predicate>
inline void HashTable<Key, Mapped, Hash, Predicate>::_destroyBucket(
  Bucket* bucket)
{
  _alloc.destroy(bucket);
  _alloc.deallocate(bucket, 1);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.