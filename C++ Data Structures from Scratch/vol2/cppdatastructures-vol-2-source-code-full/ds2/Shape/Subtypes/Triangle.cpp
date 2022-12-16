#include <iostream>

#include "ds2/Shape/Subtypes/Triangle.h"

namespace ds2
{
Triangle::~Triangle()
{
  std::cout << "~Triangle()\n";
}

std::string Triangle::subtype() const
{
  return "Triangle";
}

double Triangle::area() const
{
  return (_base * _height) / 2.0;
}

void Triangle::getDimensions()
{
  using namespace std;

  cout << "base: ";
  cin >> _base;

  cout << "height: ";
  cin >> _height;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.