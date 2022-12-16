namespace dss
{
template <class T>
Vector<T>::Vector():
  _block(nullptr),
  _size(0),
  _capacity(0)
{
  // ...
}

template <class T>
inline Vector<T>::~Vector()
{
  _destroyAllElements();
  _alloc.deallocate(_block);
}

template <class T>
inline bool Vector<T>::empty() const
{
  return _size == 0;
}

template <class T>
inline typename Vector<T>::size_type Vector<T>::size() const
{
  return _size;
}

template <class T>
inline typename Vector<T>::size_type Vector<T>::capacity() const
{
  return _capacity;
}

template <class T>
inline typename Vector<T>::const_iterator Vector<T>::begin() const
{
  return _block;
}

template <class T>
inline typename Vector<T>::const_iterator Vector<T>::end() const
{
  return _block + size();
}

template <class T>
inline typename Vector<T>::const_reference Vector<T>::front() const
{
  return *_block;
}

template <class T>
inline typename Vector<T>::const_reference Vector<T>::back() const
{
  return *(_block + size() - 1);
}

template <class T>
inline typename Vector<T>::const_reference Vector<T>::operator[](
  size_type index) const
{
  return _block[index];
}

template <class T>
inline typename Vector<T>::iterator Vector<T>::begin()
{
  return _block;
}

template <class T>
inline typename Vector<T>::iterator Vector<T>::end()
{
  return _block + size();
}

template <class T>
inline typename Vector<T>::reference Vector<T>::front()
{
  return *_block;
}

template <class T>
inline typename Vector<T>::reference Vector<T>::back()
{
  return *(_block + size() - 1);
}

template <class T>
inline typename Vector<T>::reference Vector<T>::operator[](size_type index)
{
  return _block[index];
}

template <class T>
void Vector<T>::push_back(const T& source)
{
  if (size() == capacity())
    _reallocate(static_cast<size_type>(1.5 * (capacity() + 2)));

  _alloc.construct(end(), source);
  ++_size;
}

template <class T>
inline void Vector<T>::clear()
{
  _destroyAllElements();
  _size = 0;
}

template <class T>
void Vector<T>::_reallocate(size_type newCapacity)
{
  T* newBlock = _alloc.allocate(newCapacity);

  for (size_type i = 0; i != size(); ++i)
  {
    _alloc.construct(newBlock + i, _block[i]);
    _alloc.destroy(_block + i);
  }

  _alloc.deallocate(_block);
  _block = newBlock;
  _capacity = newCapacity;
}

template <class T>
void Vector<T>::_destroyAllElements()
{
  for (size_type i = 0; i != size(); ++i)
    _alloc.destroy(_block + i);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.