#ifndef DSS_HEADERFILES_SALESTAX
#define DSS_HEADERFILES_SALESTAX

double salesTax(double price, double rate);

inline double salesTax(double price, double rate)
{
  return price * (rate / 100);
}

#endif // DSS_HEADERFILES_SALESTAX

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.