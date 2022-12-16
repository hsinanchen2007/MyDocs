#include <cmath>

namespace ds2
{
template <class Key, class Mapped, class Hash, class Predicate>
void HashTable<Key, Mapped, Hash, Predicate>::max_load_factor(
  float newMaxLoadFactor)
{
  if (newMaxLoadFactor < _maxLoadFactor)
  {
    size_type newBucketCount = static_cast<size_type>(
      std::ceil(_capacity() / newMaxLoadFactor));

    _rehash(newBucketCount);
    _maxLoadFactor = newMaxLoadFactor;
  }
  else if (newMaxLoadFactor > _maxLoadFactor)
  {
    _maxLoadFactor = newMaxLoadFactor;
  }
}

template <class Key, class Mapped, class Hash, class Predicate>
void HashTable<Key, Mapped, Hash, Predicate>::rehash(size_type newBucketCount)
{
  if (newBucketCount > bucket_count())
    _rehash(newBucketCount);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.