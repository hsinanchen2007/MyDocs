#ifndef DS2_HASHTABLE_2_HASHTABLE
#define DS2_HASHTABLE_2_HASHTABLE

#include <functional>
#include <list>
#include <memory>
#include <utility>
#include <vector>

#include "ds2/FnvHash/FnvHash.h"
#include "ds2/ForwardListSize/1/ForwardListSize.h"
#include "ds2/HashTable/common/LocalIter.h"

namespace ds2
{
template <class Key,
  class Mapped,
  class Hash = FnvHash<Key>,
  class Predicate = std::equal_to<Key>>
class HashTable
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> value_type;
  typedef Hash hasher;
  typedef Predicate key_equal;
  typedef std::list<value_type> ElementList;
  typedef typename ElementList::difference_type difference_type;
  typedef typename ElementList::size_type size_type;
  typedef typename ElementList::const_iterator const_iterator;
  typedef typename ElementList::const_pointer const_pointer;
  typedef typename ElementList::const_reference const_reference;
  typedef typename ElementList::iterator iterator;
  typedef typename ElementList::pointer pointer;
  typedef typename ElementList::reference reference;
  typedef ForwardListSize<iterator> Bucket;
  typedef typename Bucket::iterator BucketIter;
  typedef LocalIter<HashTable, const value_type> const_local_iterator;
  typedef LocalIter<HashTable, value_type> local_iterator;

  HashTable();
  ~HashTable();

  bool empty() const;
  size_type size() const;
  size_type bucket(const key_type& key) const;
  size_type bucket_count() const;
  size_type bucket_size(size_type index) const;
  const_local_iterator begin(size_type index) const;
  const_local_iterator end(size_type index) const;
  const_iterator begin() const;
  const_iterator end() const;
  const_iterator find(const key_type& key) const;
  hasher hash_function() const;
  key_equal key_eq() const;
  float load_factor() const;
  float max_load_factor() const;

  local_iterator begin(size_type index);
  local_iterator end(size_type index);
  iterator begin();
  iterator end();
  iterator find(const key_type& key);
  std::pair<iterator, bool> insert(const value_type& newElement);

 private:
  typedef std::vector<Bucket*> BucketArray;
  typedef size_type Index;

  size_type _capacity() const;
  Index _index(const key_type& key) const;

  BucketIter _findIter(Bucket* bucket, const key_type& key);
  void _rehash(size_type newBucketCount);
  Bucket* _createBucket();
  void _destroyBucket(Bucket* bucket);

  float _maxLoadFactor;
  Hash _hash;
  Predicate _isEqual;
  ElementList _elements;
  BucketArray _buckets;
  std::allocator<Bucket> _alloc;
};
};

#include "ds2/HashTable/common/memberFunctions_1.h"
#include "ds2/HashTable/common/memberFunctions_2.h"

#endif // DS2_HASHTABLE_2_HASHTABLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.