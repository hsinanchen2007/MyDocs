#include <iostream>
#include <vector>

#include "ds2/Shape/createShape.h"
#include "ds2/Shape/getSubtype.h"

int main()
{
  using namespace std;
  using namespace ds2;

  vector<Shape*> shapes;

  while (true)
  {
    char subtype = getSubtype();

    if (subtype == 'd')
      break;

    Shape* shape = createShape(subtype);

    if (shape != nullptr)
    {
      shape->getDimensions();
      shapes.push_back(shape);
    }
    else
    {
      cout << "invalid subtype\n";
    }
  }

  cout << endl;
  for (const auto& shape : shapes)
    cout << shape->subtype() << " area = " << shape->area() << endl;

  cout << endl;
  for (const auto& shape : shapes)
    delete shape;

  return 0;
}

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.