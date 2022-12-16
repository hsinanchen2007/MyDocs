#include <cmath>
#include <utility>

namespace ds2
{
template <class T, class Predicate>
inline bool Heap<T, Predicate>::empty() const
{
  return _deque.empty();
}

template <class T, class Predicate>
inline typename Heap<T, Predicate>::size_type Heap<T, Predicate>::size() const
{
  return _deque.size();
}

template <class T, class Predicate>
inline const T& Heap<T, Predicate>::top() const
{
  return _deque.front();
}

template <class T, class Predicate>
void Heap<T, Predicate>::push(const T& value)
{
  using namespace std;

  _deque.push_back(value);

  for (Node n = _deque.size() - 1; n > 0; true)
  {
    Node nParent = static_cast<Node>(ceil(n / 2.0)) - 1;

    if (_predicate(_deque[n], _deque[nParent]))
    {
      break;
    }
    else
    {
      swap(_deque[n], _deque[nParent]);
      n = nParent;
    }
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.