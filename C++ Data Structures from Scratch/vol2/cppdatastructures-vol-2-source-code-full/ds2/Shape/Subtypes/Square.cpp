#include <cmath>
#include <iostream>

#include "ds2/Shape/Subtypes/Square.h"

namespace ds2
{
Square::~Square()
{
  std::cout << "~Square()\n";
}

std::string Square::subtype() const
{
  return "Square";
}

double Square::area() const
{
  return std::pow(_length, 2);
}

void Square::getDimensions()
{
  using namespace std;

  cout << "length: ";
  cin >> _length;
}
};

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.