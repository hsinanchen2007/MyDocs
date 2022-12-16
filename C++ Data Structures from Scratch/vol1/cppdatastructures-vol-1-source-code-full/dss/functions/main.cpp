#include <iostream>

double salesTax(double price, double rate);
double shippingCost(double weight);

int main()
{
  using namespace std;

  double retailPrice;
  double salesTaxRate;
  double itemWeight;

  cout << "Enter retail price (e.g. for $24.99, enter 24.99): ";
  cin >> retailPrice;

  cout << "Enter sales tax rate (e.g. for 6.25%, enter 6.25): ";
  cin >> salesTaxRate;

  cout << "Enter item weight (e.g. for 2.50 lbs, enter 2.50): ";
  cin >> itemWeight;

  double totalCost = retailPrice +
    salesTax(retailPrice, salesTaxRate) +
    shippingCost(itemWeight);

  cout << "\nThe total cost is $" << totalCost << endl;

  return 0;
}

double salesTax(double price, double rate)
{
  return price * (rate / 100);
}

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