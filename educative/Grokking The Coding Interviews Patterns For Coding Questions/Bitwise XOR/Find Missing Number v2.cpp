/*

https://www.educative.io/courses/grokking-the-coding-interview/RLPGq6Vx0YY

Time & Space complexity: The time complexity of the above algorithm is O(n) and the space complexity 
is O(1)


What could go wrong with the above algorithm?
While finding the sum of numbers from 1 to n, we can get integer overflow when n is large.

How can we avoid this? Can XOR help us here?

Remember the important property of XOR that it returns 0 if both the bits in comparison are the same. 
In other words, XOR of a number with itself will always result in 0. This means that if we XOR all 
the numbers in the input array with all numbers from the range 1 to n then each number in the input is 
going to get zeroed out except the missing number. Following are the set of steps to find the missing 
number using XOR:

XOR all the numbers from 1 to n, let’s call it x1.
XOR all the numbers in the input array, let’s call it x2.
The missing number can be found by x1 XOR x2.
Here is what the algorithm will look like:

Time & Space complexity: The time complexity of the above algorithm is O(n) and the space complexity 
is O(1). The time and space complexities are the same as that of the previous solution but, in this 
algorithm, we will not have any integer overflow problem.

Important properties of XOR to remember
Following are some important properties of XOR to remember:

Taking XOR of a number with itself returns 0, e.g.,

1 ^ 1 = 0
29 ^ 29 = 0
Taking XOR of a number with 0 returns the same number, e.g.,

1 ^ 0 = 1
31 ^ 0 = 31
XOR is Associative & Commutative, which means:

(a ^ b) ^ c = a ^ (b ^ c)
a ^ b = b ^ a
In the following chapters, we will apply the XOR pattern to solve some interesting problems.

*/

using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
public:
  static int findMissingNumber(vector<int> &arr) {
    int n = arr.size() + 1;
    // x1 represents XOR of all values from 1 to n
    int x1 = 1;
    for (int i = 2; i <= n; i++)
      x1 = x1 ^ i;

    // x2 represents XOR of all values in arr
    int x2 = arr[0];
    for (int i = 1; i < n-1; i++)
      x2 = x2 ^ arr[i];

    // missing number is the xor of x1 and x2
    return x1 ^ x2;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 5, 2, 6, 4};
  cout << "Missing number is: " << MissingNumber::findMissingNumber(v1);
}

