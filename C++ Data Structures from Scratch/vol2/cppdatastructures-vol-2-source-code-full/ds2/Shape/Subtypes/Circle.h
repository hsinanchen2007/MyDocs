#ifndef DS2_SHAPE_SUBTYPES_CIRCLE
#define DS2_SHAPE_SUBTYPES_CIRCLE

#include "ds2/Shape/Shape.h"

namespace ds2
{
class Circle : public Shape
{
 public:
  virtual ~Circle();

  virtual std::string subtype() const;
  virtual double area() const;

  virtual void getDimensions();

 private:
  static const double _pi;

  double _radius;
};
};

#endif // DS2_SHAPE_SUBTYPES_CIRCLE

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.