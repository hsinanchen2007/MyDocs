#include <cmath>
#include <iostream>

const double pi = 3.14159;

double calculateArea(double r);
double calculateCircumference(double r);

int main()
{
  using namespace std;

  cout << "This program calculates the area and circumference of 3 circles,\n"
    "as well as running totals of the area and circumference.\n\n";

  double sumAreas = 0;
  double sumCircumferences = 0;

  for (int c = 1; c <= 3; ++c)
  {
    double radius;

    cout << "Enter the radius of circle " <<
      c <<
      " (e.g. for 3.5 m, enter 3.5): ";

    cin >> radius;

    double area = calculateArea(radius);
    double circumference = calculateCircumference(radius);

    sumAreas += area;
    sumCircumferences += circumference;

    cout << "\nArea of circle " << c << " = " << area << " sq m\n";
    cout << "Circumference of circle " << c << " = " << circumference << " m\n";
    cout << "Sum of areas = " << sumAreas << " sq m\n";
    cout << "Sum of circumferences = " << sumCircumferences << " m\n\n";
  }

  return 0;
}

double calculateArea(double r)
{
  return pi * pow(r, 2);
}

double calculateCircumference(double r)
{
  double diameter = 2 * r;

  return pi * diameter;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.