namespace dss
{
template <class T>
Ring<T>::Ring():
  _head(nullptr),
  _tail(nullptr),
  _size(0),
  _capacity(3)
{
  _block = _alloc.allocate(_capacity);
  _endOfBlock = _block + _capacity - 1;
}

template <class T>
inline Ring<T>::~Ring()
{
  _destroyAllElements();
  _alloc.deallocate(_block);
}

template <class T>
inline bool Ring<T>::empty() const
{
  return _size == 0;
}

template <class T>
inline typename Ring<T>::size_type Ring<T>::size() const
{
  return _size;
}

template <class T>
inline typename Ring<T>::size_type Ring<T>::capacity() const
{
  return _capacity;
}

template <class T>
inline typename Ring<T>::const_reference Ring<T>::front() const
{
  return *_head;
}

template <class T>
inline typename Ring<T>::const_reference Ring<T>::back() const
{
  return *_tail;
}

template <class T>
inline typename Ring<T>::reference Ring<T>::front()
{
  return *_head;
}

template <class T>
inline typename Ring<T>::reference Ring<T>::back()
{
  return *_tail;
}

template <class T>
void Ring<T>::reserve(size_type newCapacity)
{
  if (newCapacity > capacity())
    _reallocate(newCapacity);
}

template <class T>
void Ring<T>::push_back(const T& source)
{
  if (empty())
  {
    _head = _block;
    _tail = _block;
  }
  else if (size() == capacity())
  {
    _reallocate(static_cast<size_type>(1.5 * (capacity() + 2)));
    ++_tail;
  }
  else
  {
    if (_tail == _endOfBlock)
      _tail = _block;
    else
      ++_tail;
  }

  _alloc.construct(_tail, source);
  ++_size;
}

template <class T>
void Ring<T>::_reallocate(size_type newCapacity)
{
  T* newBlock = _alloc.allocate(newCapacity);

  {
    size_type totalElementsCopied = 0;
    T* sourceElement = _head;
    T* newElement = newBlock;

    while (totalElementsCopied != size())
    {
      _alloc.construct(newElement, *sourceElement);
      _alloc.destroy(sourceElement);

      ++totalElementsCopied;
      ++newElement;

      if (sourceElement == _endOfBlock)
        sourceElement = _block;
      else
        ++sourceElement;
    }
  }

  _alloc.deallocate(_block);
  _block = newBlock;
  _endOfBlock = newBlock + newCapacity - 1;
  _head = newBlock;
  _tail = newBlock + size() - 1;
  _capacity = newCapacity;
}

template <class T>
void Ring<T>::_destroyAllElements()
{
  size_type totalElementsDestroyed = 0;
  T* element = _head;

  while (totalElementsDestroyed != size())
  {
    _alloc.destroy(element);

    ++totalElementsDestroyed;

    if (element == _endOfBlock)
      element = _block;
    else
      ++element;
  }
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.