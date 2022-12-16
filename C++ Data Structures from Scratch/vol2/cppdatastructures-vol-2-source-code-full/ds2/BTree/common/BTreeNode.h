#ifndef DS2_BTREE_COMMON_BTREENODE
#define DS2_BTREE_COMMON_BTREENODE

#include <cstddef>
#include <deque>

#include "ds2/KmPair/KmPair.h"
#include "ds2/KmPairBound/KmPairBound.h"

namespace ds2
{
template <class Key, class Mapped, class KeyPred, std::size_t Order>
class BTreeNode
{
 public:
  typedef Key key_type;
  typedef Mapped mapped_type;
  typedef KmPair<Key, Mapped> KmPair;
  typedef typename KmPair::StdPair StdPair;
  typedef const StdPair& StdPairConstRef;
  typedef StdPair& StdPairRef;
  typedef std::size_t size_type;
  typedef std::size_t Index;
  typedef BTreeNode Node;
  typedef std::deque<KmPair> KmPairDeque;
  typedef typename KmPairDeque::const_iterator KmPairConstIter;
  typedef typename KmPairDeque::iterator KmPairIter;
  typedef typename KmPairDeque::reference KmPairRef;

  BTreeNode();

  size_type totalElements() const;
  size_type totalChildren() const;
  bool isAtLeastHalfFull() const;
  bool isMoreThanHalfFull() const;
  bool hasOverflow() const;
  bool hasElement(Index index) const;
  bool hasLeftChild(Index atElement) const;
  bool hasRightChild(Index atElement) const;
  bool isRoot() const;
  bool isLeaf() const;
  bool isLeftChild() const;
  bool isRightChild() const;
  StdPairConstRef frontElement() const;
  StdPairConstRef backElement() const;
  StdPairConstRef element(Index index) const;
  const key_type& key(Index index) const;
  Index backElementIndex() const;
  Index lowerBound(const key_type& key) const;
  Node* parent() const;
  Node* child(Index index) const;
  Node* leftChild(Index atElement) const;
  Node* rightChild(Index atElement) const;
  Node* frontChild() const;
  Node* backChild() const;
  Node* leftSibling() const;
  Node* rightSibling() const;

  StdPairRef frontElement();
  StdPairRef backElement();
  StdPairRef element(Index index);
  KmPairRef kmPair(Index index);
  KmPairIter insertElement(Index index, StdPairConstRef newElement);
  void overwriteElement(Index index, StdPairConstRef newElement);
  void eraseElement(Index index);
  void insertChild(Index index, Node* child);
  void eraseChild(Index index);
  void setParent(Node* newParent);
  void pushFrontElement(StdPairConstRef newElement);
  void pushBackElement(StdPairConstRef newElement);
  void pushFrontChild(Node* child);
  void pushBackChild(Node* child);
  void popFrontElement();
  void popBackElement();
  void popFrontChild();
  void popBackChild();

 private:
  KmPairDeque _kmPairs;
  Node* _parent;
  std::deque<Node*> _children;
};

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline BTreeNode<Key, Mapped, KeyPred, Order>::BTreeNode():
  _parent(nullptr)
{
  // ...
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::size_type
BTreeNode<Key, Mapped, KeyPred, Order>::totalElements() const
{
  return _kmPairs.size();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::size_type
BTreeNode<Key, Mapped, KeyPred, Order>::totalChildren() const
{
  return _children.size();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::isAtLeastHalfFull() const
{
  return totalElements() >= (Order - 1) / 2;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::isMoreThanHalfFull() const
{
  return totalElements() > (Order - 1) / 2;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::hasOverflow() const
{
  return totalElements() > Order - 1;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::hasElement(
  Index index) const
{
  return index < totalElements();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::hasLeftChild(
  Index atElement) const
{
  return atElement < _children.size();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::hasRightChild(
  Index atElement) const
{
  return atElement + 1 < _children.size();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::isRoot() const
{
  return _parent == nullptr;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline bool BTreeNode<Key, Mapped, KeyPred, Order>::isLeaf() const
{
  return _children.empty();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
bool BTreeNode<Key, Mapped, KeyPred, Order>::isLeftChild() const
{
  if (!isRoot())
    return this != parent()->backChild();
  else
    return false;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
bool BTreeNode<Key, Mapped, KeyPred, Order>::isRightChild() const
{
  if (!isRoot())
    return this != parent()->frontChild();
  else
    return false;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairConstRef
BTreeNode<Key, Mapped, KeyPred, Order>::frontElement() const
{
  return _kmPairs.front().stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairConstRef
BTreeNode<Key, Mapped, KeyPred, Order>::backElement() const
{
  return _kmPairs.back().stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairConstRef
BTreeNode<Key, Mapped, KeyPred, Order>::element(Index index) const
{
  return _kmPairs[index].stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline const typename BTreeNode<Key, Mapped, KeyPred, Order>::key_type&
BTreeNode<Key, Mapped, KeyPred, Order>::key(Index index) const
{
  return _kmPairs[index].key();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Index
BTreeNode<Key, Mapped, KeyPred, Order>::backElementIndex() const
{
  return totalElements() - 1;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Index
BTreeNode<Key, Mapped, KeyPred, Order>::lowerBound(const key_type& key) const
{
  KmPairConstIter i = kmPairLowerBound(_kmPairs.begin(),
    _kmPairs.end(),
    key,
    KeyPred());

  return i - _kmPairs.begin();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::parent() const
{
  return _parent;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::child(Index index) const
{
  return _children[index];
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::leftChild(Index atElement) const
{
  return _children[atElement];
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::rightChild(Index atElement) const
{
  return _children[atElement + 1];
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::frontChild() const
{
  return _children.front();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::backChild() const
{
  return _children.back();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::leftSibling() const
{
  if (!isRoot() && this != _parent->frontChild())
  {
    Index parentElementIndex = _parent->lowerBound(key(0));

    return _parent->leftChild(parentElementIndex - 1);
  }
  else
  {
    return nullptr;
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
typename BTreeNode<Key, Mapped, KeyPred, Order>::Node*
BTreeNode<Key, Mapped, KeyPred, Order>::rightSibling() const
{
  if (!isRoot() && this != _parent->backChild())
  {
    Index parentElementIndex = _parent->lowerBound(key(0));

    return _parent->rightChild(parentElementIndex);
  }
  else
  {
    return nullptr;
  }
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairRef
BTreeNode<Key, Mapped, KeyPred, Order>::frontElement()
{
  return _kmPairs.front().stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairRef
BTreeNode<Key, Mapped, KeyPred, Order>::backElement()
{
  return _kmPairs.back().stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::StdPairRef
BTreeNode<Key, Mapped, KeyPred, Order>::element(Index index)
{
  return _kmPairs[index].stdPair();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::KmPairRef
BTreeNode<Key, Mapped, KeyPred, Order>::kmPair(Index index)
{
  return _kmPairs[index];
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline typename BTreeNode<Key, Mapped, KeyPred, Order>::KmPairIter
BTreeNode<Key, Mapped, KeyPred, Order>::insertElement(Index index,
  StdPairConstRef newElement)
{
  return _kmPairs.insert(_kmPairs.begin() + index, newElement);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::overwriteElement(
  Index index,
  StdPairConstRef newElement)
{
  _kmPairs[index] = newElement;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::eraseElement(Index index)
{
  _kmPairs.erase(_kmPairs.begin() + index);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::insertChild(Index index,
  Node* child)
{
  _children.insert(_children.begin() + index, child);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::eraseChild(Index index)
{
  _children.erase(_children.begin() + index);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::setParent(Node* newParent)
{
  _parent = newParent;
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::pushFrontElement(
  StdPairConstRef newElement)
{
  _kmPairs.push_front(newElement);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::pushBackElement(
  StdPairConstRef newElement)
{
  _kmPairs.push_back(newElement);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::pushFrontChild(
  Node* child)
{
  _children.push_front(child);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::pushBackChild(
  Node* child)
{
  _children.push_back(child);
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::popFrontElement()
{
  _kmPairs.pop_front();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::popBackElement()
{
  _kmPairs.pop_back();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::popFrontChild()
{
  _children.pop_front();
}

template <class Key, class Mapped, class KeyPred, std::size_t Order>
inline void BTreeNode<Key, Mapped, KeyPred, Order>::popBackChild()
{
  _children.pop_back();
}
};

#endif // DS2_BTREE_COMMON_BTREENODE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.