/*

https://www.educative.io/module/lesson/cpp-basics/xVyzvQNmGKE

Problem statement
You are given a number. Your task is to find whether the given number is prime or not.

📝 A number is prime if it is only divisible by 1 and itself.

📝 1 is not a prime number, and 2 is the only even prime number.

Input
We have already initialized the variable number at the backend.

Output
If the given number is prime, you should print prime to the console.

If the given number is not prime, you should print not prime to the console.

Sample input
int number = 31;

Sample output
prime



Explanation
We have initialized the variable isPrime of type bool that keeps track of the number. 
If the given number is prime, we set isPrime to true. If not, we set it to false. Initially, 
isPrime is set to true.

We know that numbers less than 2 are not prime. Therefore, we write a condition on Line 
No. 13 that will checks if the number is less than or equal to 1 and then set the isPrime 
to false.

A number is prime if it is only divisible by 1 or itself. Therefore, we initialize a for 
loop with counter = 2, and we increase the value of the counter by 1 in each iteration. 
If the number is perfectly divisible by the loop counter variable, it is not a prime number. 
In this case, we set the isPrime to false and terminate the loop.

If the condition on Line No. 20 evaluates to false for every value of the counter, the given 
number is prime. In this case, the value of isPrime is true.

*/

#include <iostream>

using namespace std;

int main() {
  // Intitialize variables
  int number = 7;
  bool isPrime = true;
  // if block
  /*Checks if the value of a `number` is less than or equal to 
  1. If yes, then execute line No. 13 to 16. If no, then execute 
  line No. 18*/
  if (number <= 1) {
  //Sets the value of `isPrime` to false
    isPrime = false;
  }
  // for block
  for (int counter = 2; counter <= number / 2; counter++) {
    // if block
    if (number % counter == 0) {
      isPrime = false;
      // jump to line No. 27
      break;
    }
  }
  // if-else block
  /*If isPrime = true then execute line No. 30.
  If no, then execute line No. 32*/
  if (isPrime) {
    cout << "Number is prime";
  } else {
    cout << "Number is not prime";
  }

  return 0;
}
