#ifndef DS2_FNVHASH_FNVHASH
#define DS2_FNVHASH_FNVHASH

#include <cstddef>
#include <string>

namespace ds2
{
template <class Key>
struct FnvHash
{
  typedef Key argument_type;
  typedef std::size_t result_type;

  std::size_t operator()(const Key& key) const;
};

template <>
struct FnvHash<std::string>
{
  typedef std::string argument_type;
  typedef std::size_t result_type;

  std::size_t operator()(const std::string& key) const;
};

std::size_t fnvHash(const unsigned char* first, std::size_t length);

template <class Key>
inline std::size_t FnvHash<Key>::operator()(const Key& key) const
{
  return fnvHash(reinterpret_cast<const unsigned char*>(&key), sizeof(Key));
}

inline std::size_t FnvHash<std::string>::operator()(
  const std::string& key) const
{
  return fnvHash(
    reinterpret_cast<const unsigned char*>(key.c_str()),
    key.size());
}

std::size_t fnvHash(const unsigned char* first, std::size_t length)
{
  using std::size_t;

  size_t offsetBasis = 2166136261;
  size_t fnvPrime = 16777619;

  size_t hash = offsetBasis;

  for (const unsigned char* byte = first; byte != first + length; ++byte)
  {
    hash ^= *byte;
    hash *= fnvPrime;
  }

  return hash;
}
};

#endif // DS2_FNVHASH_FNVHASH

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.