#include <iostream>

#include "dss/List/5/List.h"
#include "dss/printContainer/printContainer.h"
#include "dss/Traceable/Traceable.h"

namespace dss
{
void testAssignmentOperatorCase1();
void testAssignmentOperatorCase2();
};

int main()
{
  dss::testAssignmentOperatorCase1();
  dss::testAssignmentOperatorCase2();

  return 0;
}

namespace dss
{
typedef List<Traceable<char>> _List;

void testAssignmentOperatorCase1()
{
  using namespace std;

  cout << "\nAssignment operator (left operand larger than right)\n\n";

  _List x;

  x.push_back('a');
  x.push_back('b');
  x.push_back('c');
  x.push_back('d');
  x.push_back('e');
  x.push_back('f');

  _List y;

  y.push_back('P');
  y.push_back('Q');
  y.push_back('R');
  cout << endl;

  x = y;
  cout << endl;

  printContainer(x);
  cout << endl;
}

void testAssignmentOperatorCase2()
{
  using namespace std;

  cout << "\nAssignment operator (left operand smaller than right)\n\n";

  _List x;

  x.push_back('a');
  x.push_back('b');
  x.push_back('c');

  _List y;

  y.push_back('P');
  y.push_back('Q');
  y.push_back('R');
  y.push_back('S');
  y.push_back('T');
  y.push_back('U');
  cout << endl;

  x = y;
  cout << endl;

  printContainer(x);
  cout << endl;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.