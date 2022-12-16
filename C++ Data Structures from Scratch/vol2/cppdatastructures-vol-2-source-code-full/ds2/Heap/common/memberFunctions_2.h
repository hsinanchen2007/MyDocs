#include <utility>

namespace ds2
{
template <class T, class Predicate>
void Heap<T, Predicate>::pop()
{
  using std::swap;

  swap(_deque.front(), _deque.back());
  _deque.pop_back();

  for (Node n = 0; !_isLeaf(n); true)
  {
    Node nChild = _getChildForComparison(n);

    if (_predicate(_deque[n], _deque[nChild]))
    {
      swap(_deque[n], _deque[nChild]);
      n = nChild;
    }
    else
    {
      break;
    }
  }
}

template <class T, class Predicate>
inline typename Heap<T, Predicate>::Node Heap<T, Predicate>::_leftChild(
  Node n) const
{
  return 2*n + 1;
}

template <class T, class Predicate>
inline typename Heap<T, Predicate>::Node Heap<T, Predicate>::_rightChild(
  Node n) const
{
  return _leftChild(n) + 1;
}

template <class T, class Predicate>
typename Heap<T, Predicate>::Node Heap<T, Predicate>::_getChildForComparison(
  Node n) const
{
  Node nLeft = _leftChild(n);
  Node nRight = _rightChild(n);

  if (_hasTwoChildren(n))
  {
    if (_predicate(_deque[nLeft], _deque[nRight]))
      return nRight;
    else
      return nLeft;
  }
  else
  {
    return nLeft;
  }
}

template <class T, class Predicate>
inline bool Heap<T, Predicate>::_isLeaf(Node n) const
{
  return _leftChild(n) >= static_cast<Node>(_deque.size());
}

template <class T, class Predicate>
inline bool Heap<T, Predicate>::_hasTwoChildren(Node n) const
{
  return _rightChild(n) < static_cast<Node>(_deque.size());
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.