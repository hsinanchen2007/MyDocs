/*

https://www.educative.io/courses/grokking-the-coding-interview/RLPGq6Vx0YY

Introduction
We'll cover the following

What could go wrong with the above algorithm?
Important properties of XOR to remember
XOR is a logical bitwise operator that returns 0 (false) if both bits are the same and returns 1 
(true) otherwise. In other words, it only returns 1 if exactly one bit is set to 1 out of the two 
bits in comparison.

A	B	A xor B
0	0	0
0	1	1
1	0	1
1	1	0
It is surprising to know the approaches that the XOR operator enables us to solve certain problems. 
For example, let’s take a look at the following problem:

Given an array of n-1 integers in the range from 1 to n, find the one number that is missing from 
the array.

Example:

Input: 1, 5, 2, 6, 4
Answer: 3
A straight forward approach to solve this problem can be:

Find the sum of all integers from 1 to n; let’s call it s1.

Subtract all the numbers in the input array from s1; this will give us the missing number.
This is what the algorithm will look like:

*/

using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
public:
  static int findMissingNumber(vector<int> &arr) {
    int n = arr.size() + 1;
    // find sum of all numbers from 1 to n.
    int s1 = 0;
    for (int i = 1; i <= n; i++)
      s1 += i;

    // subtract all numbers in input from sum.
    for (int num : arr)
      s1 -= num;

    // s1, now, is the missing number
    return s1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 5, 2, 6, 4};
  cout << "Missing number is: " << MissingNumber::findMissingNumber(v1);
}

