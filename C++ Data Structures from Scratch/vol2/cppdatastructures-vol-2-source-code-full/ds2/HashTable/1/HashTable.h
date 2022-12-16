#ifndef DS2_HASHTABLE_1_HASHTABLE
#define DS2_HASHTABLE_1_HASHTABLE

#include <functional>
#include <list>
#include <memory>
#include <utility>
#include <vector>

#include "ds2/FnvHash/FnvHash.h"
#include "ds2/ForwardListSize/1/ForwardListSize.h"

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

  HashTable();
  ~HashTable();

  bool empty() const;
  size_type size() const;
  size_type bucket(const key_type& key) const;
  size_type bucket_count() const;
  size_type bucket_size(size_type index) const;
  const_iterator begin() const;
  const_iterator end() const;
  hasher hash_function() const;
  key_equal key_eq() const;
  float load_factor() const;
  float max_load_factor() const;

  iterator begin();
  iterator end();
  std::pair<iterator, bool> insert(const value_type& newElement);

 private:
  typedef ForwardListSize<iterator> Bucket;
  typedef std::vector<Bucket*> BucketArray;
  typedef typename Bucket::iterator BucketIter;
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

#endif // DS2_HASHTABLE_1_HASHTABLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.