#ifndef DS2_KMPAIRBOUND_KMPAIRBOUND
#define DS2_KMPAIRBOUND_KMPAIRBOUND

#include "ds2/bound/bound.h"
#include "ds2/KmPairBound/KmPairPred.h"

namespace ds2
{
template <class KmPairIter, class KeyPred>
KmPairIter kmPairLowerBound(KmPairIter begin,
  KmPairIter end,
  const typename KmPairIter::value_type::key_type& key,
  KeyPred keyPred);

template <class KmPairIter, class KeyPred>
KmPairIter kmPairUpperBound(KmPairIter begin,
  KmPairIter end,
  const typename KmPairIter::value_type::key_type& key,
  KeyPred keyPred);

template <class KmPairIter, class KeyPred>
inline KmPairIter kmPairLowerBound(KmPairIter begin,
  KmPairIter end,
  const typename KmPairIter::value_type::key_type& key,
  KeyPred keyPred)
{
  typedef KmPairLowerBoundPred<typename KmPairIter::value_type, KeyPred>
    KmPairLowerBoundPred;

  return bound(begin,
    end,
    key,
    KmPairLowerBoundPred(keyPred));
}

template <class KmPairIter, class KeyPred>
inline KmPairIter kmPairUpperBound(KmPairIter begin,
  KmPairIter end,
  const typename KmPairIter::value_type::key_type& key,
  KeyPred keyPred)
{
  typedef KmPairUpperBoundPred<typename KmPairIter::value_type, KeyPred>
    KmPairUpperBoundPred;

  return bound(begin,
    end,
    key,
    KmPairUpperBoundPred(keyPred));
}
};

#endif // DS2_KMPAIRBOUND_KMPAIRBOUND

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.