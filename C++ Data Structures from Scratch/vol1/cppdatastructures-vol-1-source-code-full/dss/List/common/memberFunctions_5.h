namespace dss
{
template <class T>
List<T>::List(const List& source):
  _head(nullptr),
  _tail(nullptr),
  _size(0)
{
  for (const_iterator i = source.begin(); i != source.end(); ++i)
    push_back(*i);
}

template <class T>
List<T>& List<T>::operator=(const List& rhs)
{
  if (size() >= rhs.size())
  {
    while (size() != rhs.size())
      pop_back();

    iterator e = begin();
    const_iterator c = rhs.begin();

    while (e != end())
      *e++ = *c++;
  }
  else
  {
    iterator e = begin();
    const_iterator c = rhs.begin();

    while (e != end())
      *e++ = *c++;

    while (c != rhs.end())
      push_back(*c++);
  }

  return *this;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.