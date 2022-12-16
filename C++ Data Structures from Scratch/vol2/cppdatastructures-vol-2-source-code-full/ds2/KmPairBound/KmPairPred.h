#ifndef DS2_KMPAIRBOUND_KMPAIRPRED
#define DS2_KMPAIRBOUND_KMPAIRPRED

namespace ds2
{
template <class KmPair, class KeyPred>
class KmPairLowerBoundPred
{
 public:
  typedef typename KmPair::key_type key_type;

  KmPairLowerBoundPred();
  KmPairLowerBoundPred(KeyPred keyPred);

  bool operator()(const KmPair& midpoint, const key_type& value) const;

 private:
  KeyPred _keyPred;
};

template <class KmPair, class KeyPred>
class KmPairUpperBoundPred
{
public:
  typedef typename KmPair::key_type key_type;

  KmPairUpperBoundPred();
  KmPairUpperBoundPred(KeyPred keyPred);

  bool operator()(const KmPair& midpoint, const key_type& value) const;

private:
  KeyPred _keyPred;
};

template <class KmPair, class KeyPred>
inline KmPairLowerBoundPred<KmPair, KeyPred>::KmPairLowerBoundPred()
{
  // ...
}

template <class KmPair, class KeyPred>
inline KmPairLowerBoundPred<KmPair, KeyPred>::KmPairLowerBoundPred(
  KeyPred keyPred):
    _keyPred(keyPred)
{
  // ...
}

template <class KmPair, class KeyPred>
inline bool KmPairLowerBoundPred<KmPair, KeyPred>::operator()(
  const KmPair& midpoint,
  const key_type& value) const
{
  return _keyPred(midpoint.key(), value);
}

template <class KmPair, class KeyPred>
inline KmPairUpperBoundPred<KmPair, KeyPred>::KmPairUpperBoundPred()
{
  // ...
}

template <class KmPair, class KeyPred>
inline KmPairUpperBoundPred<KmPair, KeyPred>::KmPairUpperBoundPred(
  KeyPred keyPred):
    _keyPred(keyPred)
{
  // ...
}

template <class KmPair, class KeyPred>
inline bool KmPairUpperBoundPred<KmPair, KeyPred>::operator()(
  const KmPair& midpoint,
  const key_type& value) const
{
  return !_keyPred(value, midpoint.key());
}
};

#endif // DS2_KMPAIRBOUND_KMPAIRPRED

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.