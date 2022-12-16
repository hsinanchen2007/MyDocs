namespace dss
{
template <class T>
inline typename Ring<T>::const_reference Ring<T>::operator[](
  size_type index) const
{
  return _element(index);
}

template <class T>
inline typename Ring<T>::reference Ring<T>::operator[](size_type index)
{
  return _element(index);
}

template <class T>
void Ring<T>::push_front(const T& source)
{
  if (empty())
  {
    _head = _block;
    _tail = _block;
  }
  else if (size() == capacity())
  {
    _reallocate(static_cast<size_type>(1.5 * (capacity() + 2)));
    _head = _endOfBlock;
  }
  else
  {
    if (_head == _block)
      _head = _endOfBlock;
    else
      --_head;
  }

  _alloc.construct(_head, source);
  ++_size;
}

template <class T>
typename Ring<T>::reference Ring<T>::_element(size_type index) const
{
  size_type headToEndDistance = _endOfBlock - _head;

  if (index <= headToEndDistance)
    return _head[index];
  else
    return _block[index - headToEndDistance - 1];
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.