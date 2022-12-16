namespace dss
{
template <class T>
Vector<T>::Vector(const Vector& source):
  _block(nullptr),
  _size(0),
  _capacity(0)
{
  _reallocate(source.capacity());

  for (const_iterator i = source.begin(); i != source.end(); ++i)
    push_back(*i);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
  if (size() >= rhs.size())
  {
    while (size() != rhs.size())
      pop_back();

    for (size_type i = 0; i != size(); ++i)
      (*this)[i] = rhs[i];
  }
  else
  {
    for (size_type i = 0; i != size(); ++i)
      (*this)[i] = rhs[i];

    for (size_type i = size(); i != rhs.size(); ++i)
      push_back(rhs[i]);
  }

  return *this;
}

template <class T>
void Vector<T>::reserve(size_type newCapacity)
{
  if (newCapacity > capacity())
    _reallocate(newCapacity);
}

template <class T>
inline void Vector<T>::pop_back()
{
  _alloc.destroy(&back());
  --_size;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.