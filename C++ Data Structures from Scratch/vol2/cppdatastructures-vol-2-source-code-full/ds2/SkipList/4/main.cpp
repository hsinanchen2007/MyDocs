#include <iostream>

#include "ds2/printSkipList/printSkipList.h"
#include "ds2/SkipList/4/SkipList.h"
#include "ds2/stdPairIo/stdPairIo.h"
#include "ds2/Traceable/1/Traceable.h"

namespace ds2
{
typedef SkipList<Traceable<int>, int> _SkipList;

void eraseAndPrint(_SkipList* s, int key);
};

int main()
{
  using namespace ds2;

  _SkipList s;

  for (int i = 0; i != 10; ++i)
    s.insert(std::make_pair(i, 0));

  printSkipList(s);
  printAvailableNodes(s);

  eraseAndPrint(&s, 5);
  eraseAndPrint(&s, 0);
  eraseAndPrint(&s, 9);

  return 0;
}

namespace ds2
{
void eraseAndPrint(_SkipList* s, int key)
{
  using namespace std;
  using namespace ds2;

  cout << "Erasing key " << key << "...\n";

  _SkipList::const_iterator i = s->find(key);

  if (i != s->end())
  {
    i = s->erase(i);
    cout << "\nNext element = ";

    if (i != s->end())
      cout << *i << endl;
    else
      cout << "end\n";
  }
  else
  {
    cout << "Key " << key << " not found\n";
  }

  printSkipList(*s);
  printAvailableNodes(*s);
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.