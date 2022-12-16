#include <iostream>

#include "dss/printContainer/printContainer.h"
#include "dss/Traceable/Traceable.h"
#include "dss/Vector/3/Vector.h"

int main()
{
  using namespace std;
  using namespace dss;

  typedef Vector<Traceable<char>> Vector;

  Vector v;

  v.push_back('a');
  v.push_back('b');
  v.push_back('c');
  v.push_back('d');
  v.push_back('e');
  v.push_back('f');
  cout << endl;

  printContainer(v);
  cout << endl;

  cout << "Inserting element X at v.begin() + 3...\n\n";
  Vector::iterator newElement = v.insert(v.begin() + 3, 'X');
  cout << endl;

  printContainer(v);
  cout << endl;

  cout << "Inserted element " << *newElement << endl;
  cout << "Preceding element is " << *(newElement - 1) << endl;
  cout << "Proceeding element is " << *(newElement + 1) << endl << endl;

  cout << "Erasing element " << *newElement << "...\n\n";
  Vector::iterator proceedingElement = v.erase(newElement);
  cout << endl;

  printContainer(v);
  cout << endl;

  cout << "The element proceeding the erased element is " <<
    *proceedingElement << endl;

  cout << "The element preceding the erased element is " <<
    *(proceedingElement - 1) << endl << endl;

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.