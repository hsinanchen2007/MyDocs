#include <cmath>

namespace ds2
{
template <class Key, class Mapped, class Hash, class Predicate>
HashTable<Key, Mapped, Hash, Predicate>::HashTable(const HashTable& source):
  _maxLoadFactor(source._maxLoadFactor),
  _hash(source._hash),
  _isEqual(source._isEqual),
  _elements(source._elements),
  _buckets(source.bucket_count(), nullptr),
  _alloc(source._alloc)
{
  for (auto& bucket : _buckets)
    bucket = _createBucket();

  for (iterator i = _elements.begin(); i != _elements.end(); ++i)
  {
    Index index = _index(i->first);
    _buckets[index]->push_front(i);
  }
}

template <class Key, class Mapped, class Hash, class Predicate>
void HashTable<Key, Mapped, Hash, Predicate>::reserve(size_type newCapacity)
{
  if (newCapacity > _capacity())
  {
    size_type newBucketCount = static_cast<size_type>(
      std::ceil(newCapacity / _maxLoadFactor));

    _rehash(newBucketCount);
  }
}

template <class Key, class Mapped, class Hash, class Predicate>
HashTable<Key, Mapped, Hash, Predicate>&
HashTable<Key, Mapped, Hash, Predicate>::operator=(const HashTable& rhs)
{
  clear();
  reserve(rhs.size());

  for (const auto& element : rhs._elements)
  {
    Index index = _index(element.first);

    _elements.push_back(element);
    _buckets[index]->push_front(--_elements.end());
  }

  return *this;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.