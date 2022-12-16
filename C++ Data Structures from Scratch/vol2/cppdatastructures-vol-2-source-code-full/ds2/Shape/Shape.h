#ifndef DS2_SHAPE_SHAPE
#define DS2_SHAPE_SHAPE

#include <iostream>
#include <string>

namespace ds2
{
class Shape
{
 public:
  virtual ~Shape();

  virtual std::string subtype() const = 0;
  virtual double area() const = 0;

  virtual void getDimensions() = 0;
};

inline Shape::~Shape()
{
  std::cout << "~Shape()\n\n";
}
};

#endif // DS2_SHAPE_SHAPE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.