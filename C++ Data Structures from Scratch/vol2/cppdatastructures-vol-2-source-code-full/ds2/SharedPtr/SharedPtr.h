#ifndef DS2_SHAREDPTR_SHAREDPTR
#define DS2_SHAREDPTR_SHAREDPTR

#include <cstddef>

namespace ds2
{
template <class T>
class SharedPtr
{
 public:
  typedef T element_type;

  SharedPtr();
  SharedPtr(element_type* element);
  SharedPtr(const SharedPtr& source);

  ~SharedPtr();

  element_type* get() const;
  operator bool() const;
  element_type& operator*() const;
  element_type* operator->() const;
  std::size_t use_count() const;

  SharedPtr& operator=(const SharedPtr& rhs);
  void reset();

 private:
  typedef std::size_t Count;

  element_type* _element;
  Count* _totalOwners;
};

template <class T>
inline SharedPtr<T>::SharedPtr():
  _element(nullptr),
  _totalOwners(new Count(1))
{
  // ...
}

template <class T>
inline SharedPtr<T>::SharedPtr(element_type* element):
  _element(element),
  _totalOwners(new Count(1))
{
  // ...
}

template <class T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& source):
  _element(source._element),
  _totalOwners(source._totalOwners)
{
  ++(*_totalOwners);
}

template <class T>
SharedPtr<T>::~SharedPtr()
{
  --(*_totalOwners);

  if (*_totalOwners == 0)
  {
    delete _element;
    delete _totalOwners;
  }
}

template <class T>
inline typename SharedPtr<T>::element_type* SharedPtr<T>::get() const
{
  return _element;
}

template <class T>
inline SharedPtr<T>::operator bool() const
{
  return _element;
}

template <class T>
inline typename SharedPtr<T>::element_type& SharedPtr<T>::operator*() const
{
  return *_element;
}

template <class T>
inline typename SharedPtr<T>::element_type* SharedPtr<T>::operator->() const
{
  return _element;
}

template <class T>
inline std::size_t SharedPtr<T>::use_count() const
{
  return *_totalOwners;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& rhs)
{
  ++(*rhs._totalOwners);
  --(*_totalOwners);

  if (*_totalOwners == 0)
  {
    delete _element;
    delete _totalOwners;
  }

  _element = rhs._element;
  _totalOwners = rhs._totalOwners;

  return *this;
}

template <class T>
void SharedPtr<T>::reset()
{
  --(*_totalOwners);

  if (*_totalOwners == 0)
  {
    delete _element;
    *_totalOwners = 1;
  }
  else
  {
    _totalOwners = new Count(1);
  }

  _element = nullptr;
}
};

#endif // DS2_SHAREDPTR_SHAREDPTR

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.