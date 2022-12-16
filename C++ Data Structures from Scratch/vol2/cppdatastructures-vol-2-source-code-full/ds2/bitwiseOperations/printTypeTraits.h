#ifndef DS2_BITWISEOPERATIONS_PRINTTYPETRAITS
#define DS2_BITWISEOPERATIONS_PRINTTYPETRAITS

#include <climits>
#include <limits>

namespace ds2
{
template <class T>
void printTypeTraits();

template <class T>
void printTypeTraits()
{
  using namespace std;

  cout << "Type        = " << typeid(T).name() << endl;

  cout << "  Size      = " << sizeof(T) << " byte(s) = " <<
    sizeof(T) * CHAR_BIT << " bits\n";

  cout << "  Is signed = " << numeric_limits<T>::is_signed << endl;
  cout << "  Digits    = " << numeric_limits<T>::digits << endl << endl;
}
};

#endif // DS2_BITWISEOPERATIONS_PRINTTYPETRAITS

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.