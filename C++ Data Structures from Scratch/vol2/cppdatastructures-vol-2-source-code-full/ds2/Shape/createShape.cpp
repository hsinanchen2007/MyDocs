#include "ds2/Shape/createShape.h"
#include "ds2/Shape/Subtypes/Circle.h"
#include "ds2/Shape/Subtypes/Square.h"
#include "ds2/Shape/Subtypes/Triangle.h"

namespace ds2
{
Shape* createShape(char subtype)
{
  if (subtype == 'c')
    return new Circle();
  else if (subtype == 's')
    return new Square();
  else if (subtype == 't')
    return new Triangle();
  else
    return nullptr;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.