#ifndef DS2_SHAPE_SUBTYPES_TRIANGLE
#define DS2_SHAPE_SUBTYPES_TRIANGLE

#include "ds2/Shape/Shape.h"

namespace ds2
{
class Triangle : public Shape
{
 public:
  virtual ~Triangle();

  virtual std::string subtype() const;
  virtual double area() const;

  virtual void getDimensions();

 private:
  double _base;
  double _height;
};
};

#endif // DS2_SHAPE_SUBTYPES_TRIANGLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.