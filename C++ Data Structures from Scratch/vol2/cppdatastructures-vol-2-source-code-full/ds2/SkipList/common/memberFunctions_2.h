#include <cmath>

namespace ds2
{
template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::increaseTopLevel(Level newTopLevel)
{
  using std::pow;

  if (newTopLevel <= topLevel())
    return;

  for (Level i = 0; i <= topLevel(); ++i)
  {
    NodeCount existingNodes =
      static_cast<size_type>(pow(2, topLevel() - i)) - _availableNodes[i];

    NodeCount newCapacity = static_cast<size_type>(pow(2, newTopLevel - i));

    _availableNodes[i] = newCapacity - existingNodes;
  }

  for (Level i = topLevel() + 1; i <= newTopLevel; ++i)
    _availableNodes.push_back(
      static_cast<size_type>(pow(2, newTopLevel - i)));

  _head.resize(newTopLevel + 1, nullptr);
}

template <class Key, class Mapped, class Predicate>
void SkipList<Key, Mapped, Predicate>::reserve(size_type newCapacity)
{
  using namespace std;

  if (newCapacity > capacity())
  {
    Level newTopLevel = static_cast<Level>(ceil(log2(newCapacity + 1))) - 1;
    increaseTopLevel(newTopLevel);
  }
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.