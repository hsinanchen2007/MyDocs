#ifndef DS2_HASHTABLE_COMMON_LOCALITER
#define DS2_HASHTABLE_COMMON_LOCALITER

namespace ds2
{
template <class HashTable, class Element>
class LocalIter
{
 public:
  friend HashTable;

  typedef Element* pointer;
  typedef Element& reference;
  typedef typename HashTable::difference_type difference_type;
  typedef typename HashTable::value_type value_type;
  typedef typename HashTable::BucketIter BucketIter;
  typedef typename BucketIter::iterator_category iterator_category;

  LocalIter();

  template <class OtherElement>
  LocalIter(const LocalIter<HashTable, OtherElement>& localIter);

  BucketIter base() const;
  bool operator==(const LocalIter& rhs) const;
  bool operator!=(const LocalIter& rhs) const;
  pointer operator->() const;
  reference operator*() const;

  LocalIter& operator++();
  LocalIter operator++(int n);

 private:
  LocalIter(const BucketIter& bucketIter);

  BucketIter _bucketIter;
};

template <class HashTable, class Element>
inline LocalIter<HashTable, Element>::LocalIter()
{
  // ...
}

template <class HashTable, class Element>
template <class OtherElement>
inline LocalIter<HashTable, Element>::LocalIter(
  const LocalIter<HashTable, OtherElement>& localIter):
    _bucketIter(localIter.base())
{
  // ...
}

template <class HashTable, class Element>
inline typename LocalIter<HashTable, Element>::BucketIter
LocalIter<HashTable, Element>::base() const
{
  return _bucketIter;
}

template <class HashTable, class Element>
inline bool LocalIter<HashTable, Element>::operator==(
  const LocalIter& rhs) const
{
  return _bucketIter == rhs._bucketIter;
}

template <class HashTable, class Element>
inline bool LocalIter<HashTable, Element>::operator!=(
  const LocalIter& rhs) const
{
  return _bucketIter != rhs._bucketIter;
}

template <class HashTable, class Element>
inline typename LocalIter<HashTable, Element>::pointer
LocalIter<HashTable, Element>::operator->() const
{
  return &(**_bucketIter);
}

template <class HashTable, class Element>
inline typename LocalIter<HashTable, Element>::reference
LocalIter<HashTable, Element>::operator*() const
{
  return **_bucketIter;
}

template <class HashTable, class Element>
inline LocalIter<HashTable, Element>&
LocalIter<HashTable, Element>::operator++()
{
  ++_bucketIter;

  return *this;
}

template <class HashTable, class Element>
inline LocalIter<HashTable, Element>
LocalIter<HashTable, Element>::operator++(int n)
{
  LocalIter original(*this);

  ++(*this);

  return original;
}

template <class HashTable, class Element>
inline LocalIter<HashTable, Element>::LocalIter(const BucketIter& bucketIter):
  _bucketIter(bucketIter)
{
  // ...
}
};

#endif // DS2_HASHTABLE_COMMON_LOCALITER

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.