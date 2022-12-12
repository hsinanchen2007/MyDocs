/*

https://www.educative.io/module/lesson/cpp-basics/N0lWARMMO8K

Problem statement
You are given a decimal number. Your task is to convert it into a binary number. 
See the figure below:

To convert the decimal number into binary, we should keep dividing the number by 
2 until the quotient is equal to 0. The resultant remainder will be the number in 
binary.

Input
We have already initialized the input variable decimal at the backend.

Output
We have declared the variable binary for you. Your task is to store your output 
in the binary.

Sample input
int decimal = 10;

Sample output
binary = 1010


Explanation
To convert the decimal number into binary, we should keep dividing the number by 2 
until the quotient is not equal to 0. The resultant remainder is the number in binary.

In the code above, we keep iterating through the loop until the decimal is not equal 
to 0. We first divide the number by 2 and store the remainder in the remainder variable. 
Then, we multiply the remainder by product, add binary in it, and store the answer 
in binary. For the next iteration, we divide the decimal by 2 and multiply the product 
by 10.

*/

#include <iostream>

using namespace std;

int main() {
  // Initialize variables
  int decimal = 10, binary = 0;
  int remainder, product = 1;
  // Prints value of decimal
  cout << "Decimal Number = " << decimal << endl;
  // while block
  /*Checks if the value of `decimal` is not equal to `0`. 
  If yes, then execute line No. 17 to 21.
  If no, then execute line No. 23.
  */
  while (decimal != 0) {
    remainder = decimal % 2;
    binary = binary + (remainder * product);
    decimal = decimal / 2;
    product *= 10;
  }
  // while exit
  cout << "Binary Number = " << binary;
  return 0;
}

