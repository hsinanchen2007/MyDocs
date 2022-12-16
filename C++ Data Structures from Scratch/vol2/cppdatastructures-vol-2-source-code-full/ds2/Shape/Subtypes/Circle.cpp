#include <cmath>
#include <iostream>

#include "ds2/Shape/Subtypes/Circle.h"

namespace ds2
{
Circle::~Circle()
{
  std::cout << "~Circle()\n";
}

std::string Circle::subtype() const
{
  return "Circle";
}

double Circle::area() const
{
  return _pi * std::pow(_radius, 2);
}

void Circle::getDimensions()
{
  using namespace std;

  cout << "radius: ";
  cin >> _radius;
}

const double Circle::_pi = 3.14159;
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.