/*

https://www.educative.io/module/lesson/cpp-basics/N8AkLJmyvvD

factorial function 
Line No. 6: The recursive factorial function takes a value of type int, whose factorial 
is to be calculated in its input parameters, and returns the factorial of value in the 
output.

Line No. 8: Since we cannot calculate the factorial of negative integers for n < 0, factorial 
simply returns -1 in the output. -1 indicates that we have entered an invalid value.

Line No. 12: If n = 1 or n = 0, the function terminates after returning 1 to the calling 
point. There are no recursive calls in the factorial body since we cannot break the expression 
anymore. This is the base case of the factorial function.

Line No. 17: If n > 1, the factorial returns the product of n by the factorial (n-1). 
This is the recursive case.

Let’s run our code for n = 5 and see what happens inside the recursive factorial function.

*/

#include <iostream>

using namespace std;

// Recursive factorial function
int factorial(int n) {
  // Invalid value
  if (n < 0){
    return -1;
  }
  // Base case
  if (n == 1 || n == 0) {
    return 1;
  } 
  // Recursive Case
  else {
    return n * factorial(n - 1);
  }
}

// main function
int main() {
  int n = 5;
  int result;
  // Call factorial function in main and store the returned value in result
  result = factorial(n);
  // Prints value of result
  cout << "Factorial of " << n << " = " << result;
  return 0;
}

