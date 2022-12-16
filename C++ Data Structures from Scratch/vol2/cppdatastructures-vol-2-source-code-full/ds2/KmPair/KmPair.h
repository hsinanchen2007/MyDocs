#ifndef DS2_KMPAIR_KMPAIR
#define DS2_KMPAIR_KMPAIR

#include <iostream>
#include <memory>
#include <utility>

namespace ds2
{
template <class Key, class Mapped>
class KmPair;

template <class Key, class Mapped>
std::ostream& operator<<(std::ostream& lhs, const KmPair<Key, Mapped>& rhs);

template <class Key, class Mapped>
std::istream& operator<<(std::istream& lhs, const KmPair<Key, Mapped>& rhs);

template <class Key, class Mapped>
class KmPair
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef std::pair<const Key, Mapped> StdPair;
  typedef const StdPair* const_pointer;
  typedef const StdPair& const_reference;
  typedef StdPair* pointer;
  typedef StdPair& reference;

  KmPair();
  KmPair(const StdPair& stdPair);
  KmPair(const key_type& key, const mapped_type& mapped);
  KmPair(const KmPair& source);

  ~KmPair();

  const StdPair& stdPair() const;
  const key_type& key() const;
  const mapped_type& mapped() const;

  StdPair& stdPair();
  key_type& key();
  mapped_type& mapped();
  KmPair& operator=(const KmPair& rhs);

 private:
  StdPair* _p;
  std::allocator<StdPair> _alloc;
};

template <class Key, class Mapped>
inline std::ostream& operator<<(std::ostream& lhs,
  const KmPair<Key, Mapped>& rhs)
{
  return (lhs << rhs.stdPair());
}

template <class Key, class Mapped>
inline std::istream& operator<<(std::istream& lhs,
  const KmPair<Key, Mapped>& rhs)
{
  return (lhs >> rhs.stdPair());
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>::KmPair()
{
  _p = _alloc.allocate(1);
  _alloc.construct(_p, StdPair());
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>::KmPair(const StdPair& stdPair)
{
  _p = _alloc.allocate(1);
  _alloc.construct(_p, stdPair);
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>::KmPair(const key_type& key,
  const mapped_type& mapped)
{
  _p = _alloc.allocate(1);
  _alloc.construct(_p, StdPair(key, mapped));
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>::KmPair(const KmPair& source)
{
  _p = _alloc.allocate(1);
  _alloc.construct(_p, source.stdPair());
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>::~KmPair()
{
  _alloc.destroy(_p);
  _alloc.deallocate(_p, 1);
}

template <class Key, class Mapped>
inline typename KmPair<Key, Mapped>::const_reference
KmPair<Key, Mapped>::stdPair() const
{
  return *_p;
}

template <class Key, class Mapped>
inline const typename KmPair<Key, Mapped>::key_type&
KmPair<Key, Mapped>::key() const
{
  return _p->first;
}

template <class Key, class Mapped>
inline const typename KmPair<Key, Mapped>::mapped_type&
KmPair<Key, Mapped>::mapped() const
{
  return _p->second;
}

template <class Key, class Mapped>
inline typename KmPair<Key, Mapped>::reference KmPair<Key, Mapped>::stdPair()
{
  return *_p;
}

template <class Key, class Mapped>
inline typename KmPair<Key, Mapped>::key_type& KmPair<Key, Mapped>::key()
{
  return _p->first;
}

template <class Key, class Mapped>
inline typename KmPair<Key, Mapped>::mapped_type& KmPair<Key, Mapped>::mapped()
{
  return _p->second;
}

template <class Key, class Mapped>
inline KmPair<Key, Mapped>& KmPair<Key, Mapped>::operator=(const KmPair& rhs)
{
  _alloc.destroy(_p);
  _alloc.construct(_p, rhs.stdPair());

  return *this;
}
};

#endif // DS2_KMPAIR_KMPAIR

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.