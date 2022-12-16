#include <cmath>
#include <iostream>

double area(double length);
double area(double length, double width);
double area(double length, double width, double height);

int main()
{
  using namespace std;

  double length;
  double width;
  double height;

  cout << "Enter length (e.g. for 2.5 m, enter 2.5): ";
  cin >> length;

  cout << "Enter width (e.g. for 2.5 m, enter 2.5): ";
  cin >> width;

  cout << "Enter height (e.g. for 2.5 m, enter 2.5): ";
  cin >> height;

  cout << "\nThe area of a square is " << area(length) << " sq m\n";
  cout << "The area of a rectangle is " << area(length, width) << " sq m\n";
  cout << "The area of a cuboid is " << area(length, width, height) <<
    " sq m\n";

  return 0;
}

double area(double length)
{
  return pow(length, 2);
}

double area(double length, double width)
{
  return length * width;
}

double area(double length, double width, double height)
{
  return (2 * length * width) +
    (2 * length * height) +
    (2 * width * height);
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.