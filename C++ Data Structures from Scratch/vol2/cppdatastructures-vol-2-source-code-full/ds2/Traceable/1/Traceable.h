#ifndef DS2_TRACEABLE_1_TRACEABLE
#define DS2_TRACEABLE_1_TRACEABLE

#include <iostream>

namespace ds2
{
template <class T>
class Traceable;

template <class T>
std::ostream& operator<<(std::ostream& lhs, const Traceable<T>& rhs);

template <class T>
std::istream& operator>>(std::istream& lhs, Traceable<T>& rhs);

template <class T>
class Traceable
{
 public:
  typedef T value_type;

  Traceable();
  Traceable(const Traceable& source);
  Traceable(const T& value);
  ~Traceable();

  const T& value() const;

  bool operator==(const Traceable& rhs) const;
  bool operator!=(const Traceable& rhs) const;
  bool operator>=(const Traceable& rhs) const;
  bool operator<=(const Traceable& rhs) const;
  bool operator>(const Traceable& rhs) const;
  bool operator<(const Traceable& rhs) const;

  Traceable& operator=(const Traceable& rhs);

  friend std::ostream& operator<< <>(std::ostream& lhs, const Traceable& rhs);
  friend std::istream& operator>> <>(std::istream& lhs, Traceable& rhs);

 private:
  static int _totalObjects;

  T _value;
};

template <class T>
int Traceable<T>::_totalObjects = 0;

template <class T>
inline Traceable<T>::Traceable():
  _value(T())
{
  std::cout << "d " << _value << std::endl;
  ++_totalObjects;
}

template <class T>
inline Traceable<T>::Traceable(const Traceable& source):
  _value(source._value)
{
  std::cout << "c " << _value << std::endl;
  ++_totalObjects;
}

template <class T>
inline Traceable<T>::Traceable(const T& value):
  _value(value)
{
  std::cout << "v " << _value << std::endl;
  ++_totalObjects;
}

template <class T>
Traceable<T>::~Traceable()
{
  using namespace std;

  cout << "~ " << _value << endl;
  --_totalObjects;

  if (_totalObjects == 0)
    cout << "\nAll Traceables destroyed\n\n";
}

template <class T>
inline const T& Traceable<T>::value() const
{
  return _value;
}

template <class T>
inline bool Traceable<T>::operator==(const Traceable& rhs) const
{
  return _value == rhs._value;
}

template <class T>
inline bool Traceable<T>::operator!=(const Traceable& rhs) const
{
  return _value != rhs._value;
}

template <class T>
inline bool Traceable<T>::operator>=(const Traceable& rhs) const
{
  return _value >= rhs._value;
}

template <class T>
inline bool Traceable<T>::operator<=(const Traceable& rhs) const
{
  return _value <= rhs._value;
}

template <class T>
inline bool Traceable<T>::operator>(const Traceable& rhs) const
{
  return _value > rhs._value;
}

template <class T>
inline bool Traceable<T>::operator<(const Traceable& rhs) const
{
  return _value < rhs._value;
}

template <class T>
Traceable<T>& Traceable<T>::operator=(const Traceable& rhs)
{
  std::cout << "  " << _value << " -> " << rhs._value << std::endl;

  _value = rhs._value;

  return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& lhs, const Traceable<T>& rhs)
{
  lhs << rhs._value;

  return lhs;
}

template <class T>
std::istream& operator>>(std::istream& lhs, Traceable<T>& rhs)
{
  T originalValue = rhs._value;

  lhs >> rhs._value;

  std::cout << "  " << originalValue << " -> " << rhs._value << std::endl;

  return lhs;
}
};

#endif // DS2_TRACEABLE_1_TRACEABLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.