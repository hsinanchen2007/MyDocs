double shippingCost(double weight)
{
  double cost;

  if (weight < 5.0)
    cost = 7.99;
  else
    cost = 2.00 * weight;

  return cost;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.