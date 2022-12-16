#ifndef DS2_PRINTSKIPLIST_PRINTSKIPLIST
#define DS2_PRINTSKIPLIST_PRINTSKIPLIST

#include <iostream>

namespace ds2
{
template <class SkipList>
void printSkipList(const SkipList& skipList);

template <class SkipList>
void printAvailableNodes(const SkipList& skipList);

template <class SkipList>
void printSkipList(const SkipList& skipList)
{
  using namespace std;

  typedef typename SkipList::Node Node;
  typedef typename SkipList::Level Level;

  const typename SkipList::NodeVector& head = skipList.head();

  for (Level i = 0; i != head.size(); ++i)
  {
    cout << "head[" << i << "]     ";

    if (head[i] != nullptr)
      cout << head[i]->element.first << endl;
    else
      cout << "null\n";
  }

  cout << endl;

  for (const Node* n = head[0]; n != nullptr; n = n->right[0])
  {
    cout << "node        " << n->element.first << endl;
    cout << "  left      ";

    if (n->left != nullptr)
      cout << n->left->element.first << endl;
    else
      cout << "null\n";

    for (Level i = 0; i <= n->topLevel(); ++i)
    {
      cout << "  right[" << i << "]  ";

      if (n->right[i] != nullptr)
        cout << n->right[i]->element.first << endl;
      else
        cout << "null\n";
    }

    cout << endl;
  }
}

template <class SkipList>
void printAvailableNodes(const SkipList& skipList)
{
  using namespace std;

  const typename SkipList::CountVector& availableNodes =
    skipList.availableNodes();

  for (typename SkipList::Level i = 0; i != availableNodes.size(); ++i)
    cout << "availableNodes[" << i << "] = " << availableNodes[i] << endl;

  cout << endl;
}
};

#endif // DS2_PRINTSKIPLIST_PRINTSKIPLIST

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.