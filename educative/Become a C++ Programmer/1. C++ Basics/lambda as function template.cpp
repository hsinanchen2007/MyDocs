/*

https://www.educative.io/module/lesson/cpp-basics/7DG6JRGgqlQ

Generic lambda functions 
With C++14, we have generic lambdas, which means that lambdas can deduce their argument types. 
Therefore, we can define a lambda expression such as [](auto a, auto b){ return a + b; };. 
What does that mean for the call operator of AddObj?

The call operator becomes a template. I want to emphasize it explicitly: a generic lambda is a 
function template.

The difference between the usage of functions and lambda functions boils down to two points:
    1. We cannot overload lambdas.
    2. A lambda function can capture local variables.

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std::string_literals;

int main() {
  auto add11=[ ](int i, int i2){ return i + i2; }; 
  auto add14= [ ](auto i, auto i2){ return i + i2; };
  std::vector<int> myVec{1, 2, 3, 4, 5};
  auto res11= std::accumulate(myVec.begin(), myVec.end(), 0, add11); 
  auto res14= std::accumulate(myVec.begin(), myVec.end(), 0, add14);
  
  std::cout << res11 << std::endl;
  std::cout << res14 << std::endl;

  std::vector<std::string> myVecStr{"Hello"s, " World"s};
  auto st= std::accumulate(myVecStr.begin(), myVecStr.end(), ""s, add14);
  std::cout << st << std::endl; // Hello World
}

