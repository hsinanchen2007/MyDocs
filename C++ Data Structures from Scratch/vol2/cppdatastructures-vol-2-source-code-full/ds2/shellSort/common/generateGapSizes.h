#ifndef DS2_SHELLSORT_COMMON_GENERATEGAPSIZES
#define DS2_SHELLSORT_COMMON_GENERATEGAPSIZES

#include <cmath>
#include <vector>

namespace ds2
{
namespace shell
{
template <class Size>
void generateGapSizes(std::vector<Size>* gapSizes, Size totalElements);

template <class Size>
void generateGapSizes(std::vector<Size>* gapSizes, Size totalElements)
{
  gapSizes->push_back(1);

  double g = 1;

  while (true)
  {
    g = 2.25*g + 1;

    Size actualGapSize = static_cast<Size>(std::ceil(g));

    if (actualGapSize < totalElements)
      gapSizes->push_back(actualGapSize);
    else
      break;
  }
}
};
};

#endif // DS2_SHELLSORT_COMMON_GENERATEGAPSIZES

// For the book "C++ Data Structures from Scratch, Vol. 2"
// www.cppdatastructures.com
// Copyright 2018 by Robert MacGregor.  All rights reserved.