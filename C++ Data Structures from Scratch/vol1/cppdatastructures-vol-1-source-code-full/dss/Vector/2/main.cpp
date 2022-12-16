#include <iostream>

#include "dss/printContainer/printContainer.h"
#include "dss/printSequence/printSequence.h"
#include "dss/Traceable/Traceable.h"
#include "dss/Vector/2/Vector.h"

namespace dss
{
void testReserveAndPopBack();
void testCopyConstructor();
void testAssignmentOperatorCase1();
void testAssignmentOperatorCase2();
};

int main()
{
  using namespace dss;

  testReserveAndPopBack();
  testCopyConstructor();
  testAssignmentOperatorCase1();
  testAssignmentOperatorCase2();

  return 0;
}

namespace dss
{
typedef Vector<Traceable<char>> _Vector;

void testReserveAndPopBack()
{
  using namespace std;

  cout << "Reserve\n\n";

  _Vector v;
  v.reserve(8);

  v.push_back('a');
  v.push_back('b');
  v.push_back('c');
  v.push_back('d');
  v.push_back('e');
  v.push_back('f');
  v.push_back('g');
  v.push_back('h');

  cout << "\nPop back\n\n";

  while (!v.empty())
    v.pop_back();

  cout << endl;
}

void testCopyConstructor()
{
  using namespace std;

  cout << "Copy constructor\n\n";

  _Vector v;

  v.push_back('a');
  v.push_back('b');
  v.push_back('c');
  v.push_back('d');
  cout << endl;

  _Vector w(v);
  cout << endl;

  printContainer(w);
  cout << endl;
}

void testAssignmentOperatorCase1()
{
  using namespace std;

  cout << "\nAssignment operator (left operand larger than right)\n\n";

  _Vector x;

  x.push_back('A');
  x.push_back('B');
  x.push_back('C');
  x.push_back('D');
  x.push_back('E');

  _Vector y;

  y.push_back('1');
  y.push_back('2');
  y.push_back('3');
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

  _Vector x;

  x.push_back('A');
  x.push_back('B');
  x.push_back('C');

  _Vector y;

  y.push_back('1');
  y.push_back('2');
  y.push_back('3');
  y.push_back('4');
  y.push_back('5');
  cout << endl;

  x = y;
  cout << endl;

  printContainer(x);
  cout << endl;
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.