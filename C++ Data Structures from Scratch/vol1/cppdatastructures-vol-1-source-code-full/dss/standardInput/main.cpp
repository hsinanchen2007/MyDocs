#include <iostream>
#include <string>

int main()
{
  using namespace std;

  string firstName;
  string lastName;
  int age;

  cout << "Please enter your first name: ";
  cin >> firstName;

  cout << "Please enter your last name and age (separated by whitespace): ";
  cin >> lastName >> age;

  cout << "\nHello, " << firstName << " " << lastName << ".\n";
  cout << "In 5 years, you will be " << age + 5 << " years old.\n";

  return 0;
}

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.