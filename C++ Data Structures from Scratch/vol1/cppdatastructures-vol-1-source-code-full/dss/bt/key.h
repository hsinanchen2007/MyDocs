#ifndef DSS_BT_KEY
#define DSS_BT_KEY

namespace dss
{
namespace bt
{
template <class Node>
const typename Node::key_type& key(const Node* node);

template <class Pair>
const typename Pair::first_type& key(const Pair& pair);

template <class Node>
inline const typename Node::key_type& key(const Node* node)
{
  return node->element.first;
}

template <class Pair>
inline const typename Pair::first_type& key(const Pair& pair)
{
  return pair.first;
}
};
};

#endif // DSS_BT_KEY

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.