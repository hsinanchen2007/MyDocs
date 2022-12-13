/*

https://www.educative.io/module/lesson/cpp-basics/m7rE7y0NqPn

Problem statement
You are given a number. Your task is to find whether the given number is a palindrome or not.

📝 A number is a palindrome if it reads the same backward as forward, e.g., 1221.

Input
We have already initialized the variable number at the backend.

Output
If the given number is a palindrome, then you should print is palindrome to the console.

If the given number is not a palindrome, then you should print not a palindrome to the console.

Sample input
int number = 212

Sample output
is palindrome


Explanation
To check if given the number is a palindrome or not, we will first reverse a given number. 
If the reverse of the number is equal to the original number, the number is a palindrome, 
else it is not.

To reverse a given number, we store our number in temp and then iterate through the while 
loop while the temp is not equal to 0. In the body of the while loop, we get the last digit 
of temp and store it in the remainder. We add the remainder in reverse after the initially 
stored value in reverse. Then, we divide the temp by 10 to remove the very last digit.

*/

#include <iostream>

using namespace std;

int main() {
  // Initialize variable
  int number = 2002;
  int remainder = 0, reverse = 0;
  // To reverse a number store it in temp
  int temp = number;
  // while loop
  while (temp != 0) {
    // Get the last digit of temp
    remainder = temp % 10;
    // Store the remainder after the initially stored value in reverse
    reverse = reverse * 10 + remainder;
    // Remove the last digit of temp
    temp = temp / 10;
  }
  // if condition
  if (number == reverse) {
    cout << "is palindrome";
  } else {
    cout << "not a palindrome";
  }
  return 0;
}
