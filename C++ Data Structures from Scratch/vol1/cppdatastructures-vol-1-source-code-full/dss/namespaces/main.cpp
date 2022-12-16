#include <iostream>

namespace userInterface
{
double getRetailPrice();
double getSalesTaxRate();
double getItemWeight();
};

namespace feeCalculator
{
double totalFees(double itemPrice, double salesTaxRate, double itemWeight);
double salesTax(double price, double rate);
double shippingCost(double weight);
};

int main()
{
  using namespace std;

  double retailPrice = userInterface::getRetailPrice();
  double salesTaxRate = userInterface::getSalesTaxRate();
  double itemWeight = userInterface::getItemWeight();

  double totalCost = retailPrice +
    feeCalculator::totalFees(retailPrice, salesTaxRate, itemWeight);

  cout << "\nThe total cost is $" << totalCost << endl;

  return 0;
}

namespace userInterface
{
double getRetailPrice()
{
  using namespace std;

  double x;

  cout << "Enter retail price (e.g. for $24.99, enter 24.99): ";
  cin >> x;

  return x;
}

double getSalesTaxRate()
{
  using namespace std;

  double x;

  cout << "Enter sales tax rate (e.g. for 6.25%, enter 6.25): ";
  cin >> x;

  return x;
}

double getItemWeight()
{
  using namespace std;

  double x;

  cout << "Enter item weight (e.g. for 2.50 lbs, enter 2.50): ";
  cin >> x;

  return x;
}
};

namespace feeCalculator
{
double totalFees(double itemPrice, double salesTaxRate, double itemWeight)
{
  return salesTax(itemPrice, salesTaxRate) + shippingCost(itemWeight);
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
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.