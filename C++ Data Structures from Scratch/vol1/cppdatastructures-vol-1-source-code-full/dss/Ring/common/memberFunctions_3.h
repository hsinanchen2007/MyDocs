namespace dss
{
template <class T>
void Ring<T>::pop_front()
{
  _alloc.destroy(_head);

  if (size() == 1)
  {
    _head = nullptr;
    _tail = nullptr;
  }
  else if (_head == _endOfBlock)
  {
    _head = _block;
  }
  else
  {
    ++_head;
  }

  --_size;
}

template <class T>
void Ring<T>::pop_back()
{
  _alloc.destroy(_tail);

  if (size() == 1)
  {
    _head = nullptr;
    _tail = nullptr;
  }
  else if (_tail == _block)
  {
    _tail = _endOfBlock;
  }
  else
  {
    --_tail;
  }

  --_size;
}

template <class T>
void Ring<T>::clear()
{
  _destroyAllElements();

  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.