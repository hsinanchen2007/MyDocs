#include <iostream>

#include "ds2/Shape/Subtypes/Circle.h"
#include "ds2/Shape/Subtypes/Square.h"
#include "ds2/Shape/Subtypes/Triangle.h"
#include "ds2/SharedPtr/SharedPtr.h"

namespace ds2
{
typedef SharedPtr<Shape> ShapePtr;

void printUseCountAndArea(const ShapePtr& a, const ShapePtr& b);
};

int main()
{
  using namespace std;
  using namespace ds2;

  ShapePtr a(new Circle());
  a->getDimensions();

  ShapePtr b(a);
  printUseCountAndArea(a, b);

  a = new Square();
  a->getDimensions();
  printUseCountAndArea(a, b);

  b = new Triangle();
  b->getDimensions();
  printUseCountAndArea(a, b);

  return 0;
}

namespace ds2
{
void printUseCountAndArea(const ShapePtr& a, const ShapePtr& b)
{
  using namespace std;

  cout << endl;
  cout << "a.use_count() = " << a.use_count() << endl;
  cout << "a->area()     = " << a->area() << endl << endl;

  cout << "b.use_count() = " << b.use_count() << endl;
  cout << "b->area()     = " << b->area() << endl << endl;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.