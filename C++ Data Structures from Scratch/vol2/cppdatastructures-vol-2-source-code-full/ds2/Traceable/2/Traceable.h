#ifndef DS2_TRACEABLE_2_TRACEABLE
#define DS2_TRACEABLE_2_TRACEABLE

#include "ds2/FnvHash/FnvHash.h"
#include "ds2/Traceable/1/Traceable.h"

namespace ds2
{
template <class Key>
struct FnvHash<Traceable<Key>>
{
  typedef Traceable<Key> argument_type;
  typedef std::size_t result_type;

  std::size_t operator()(const Traceable<Key>& key) const;
};

template <>
struct FnvHash<Traceable<std::string>>
{
  typedef Traceable<std::string> argument_type;
  typedef std::size_t result_type;

  std::size_t operator()(const Traceable<std::string>& key) const;
};

template <class Key>
inline std::size_t FnvHash<Traceable<Key>>::operator()(
  const Traceable<Key>& key) const
{
  return fnvHash(
    reinterpret_cast<const unsigned char*>(&key.value()),
    sizeof(Traceable<Key>::value_type));
}

inline std::size_t FnvHash<Traceable<std::string>>::operator()(
  const Traceable<std::string>& key) const
{
  return fnvHash(
    reinterpret_cast<const unsigned char*>(key.value().c_str()),
    key.value().size());
}
};

#endif // DS2_TRACEABLE_2_TRACEABLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.