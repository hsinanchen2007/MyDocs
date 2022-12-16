#ifndef DS2_SHAPE_SUBTYPES_SQUARE
#define DS2_SHAPE_SUBTYPES_SQUARE

#include "ds2/Shape/Shape.h"

namespace ds2
{
class Square : public Shape
{
 public:
  virtual ~Square();

  virtual std::string subtype() const;
  virtual double area() const;

  virtual void getDimensions();

 private:
  double _length;
};
};

#endif // DS2_SHAPE_SUBTYPES_SQUARE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.