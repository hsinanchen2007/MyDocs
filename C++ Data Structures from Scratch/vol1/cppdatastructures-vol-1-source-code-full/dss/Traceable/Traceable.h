#ifndef DSS_TRACEABLE_TRACEABLE
#define DSS_TRACEABLE_TRACEABLE

#include <iostream>

namespace dss
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

  bool operator==(const Traceable& rhs) const;
  bool operator!=(const Traceable& rhs) const;
  bool operator>=(const Traceable& rhs) const;
  bool operator<=(const Traceable& rhs) const;
  bool operator>(const Traceable& rhs) const;
  bool operator<(const Traceable& rhs) const;

  void printValue() const;

  Traceable& operator=(const Traceable& rhs);

  friend std::ostream& operator<< <>(std::ostream& lhs, const Traceable& rhs);
  friend std::istream& operator>> <>(std::istream& lhs, Traceable& rhs);

 private:
  T _value;
};

template <class T>
inline Traceable<T>::Traceable():
  _value(T())
{
  std::cout << "d " << _value << std::endl;
}

template <class T>
inline Traceable<T>::Traceable(const Traceable& source):
  _value(source._value)
{
  std::cout << "c " << _value << std::endl;
}

template <class T>
inline Traceable<T>::Traceable(const T& value):
  _value(value)
{
  std::cout << "v " << _value << std::endl;
}

template <class T>
inline Traceable<T>::~Traceable()
{
  std::cout << "~ " << _value << std::endl;
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
inline void Traceable<T>::printValue() const
{
  std::cout << _value << std::endl;
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

#endif // DSS_TRACEABLE_TRACEABLE

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.