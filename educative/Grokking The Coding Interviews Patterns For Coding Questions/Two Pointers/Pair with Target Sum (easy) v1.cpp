/*

Introduction
In problems where we deal with sorted arrays (or LinkedLists) and need to find a set of elements 
that fulfill certain constraints, the Two Pointers approach becomes quite useful. The set of elements 
could be a pair, a triplet or even a subarray. For example, take a look at the following problem:

Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the 
given target.

To solve this problem, we can consider each element one by one (pointed out by the first pointer) and 
iterate through the remaining elements (pointed out by the second pointer) to find a pair with the given sum. 
The time complexity of this algorithm will be O(N^2)

O(N2) where ‘N’ is the number of elements in the input array.

Given that the input array is sorted, an efficient way would be to start with one pointer in the beginning 
and another pointer at the end. At every step, we will see if the numbers pointed by the two pointers add 
up to the target sum. If they do not, we will do one of two things:

If the sum of the two numbers pointed by the two pointers is greater than the target sum, this means that 
we need a pair with a smaller sum. So, to try more pairs, we can decrement the end-pointer.
If the sum of the two numbers pointed by the two pointers is smaller than the target sum, this means that 
we need a pair with a larger sum. So, to try more pairs, we can increment the start-pointer.

Here is the visual representation of this algorithm:

    1   
    2   
    3   
    4   
    6   
 target sum = 6  
 1 + 6 > target sum, therefore let's decrement Pointer2  
    1   
    2   
    3   
    4   
    6   
 1 + 4 < target sum, therefore let's increment Pointer1  
    1   
    2   
    3   
    4   
    6   
 2 + 4 == target sum, we have found our pair!  
The time complexity of the above algorithm will be O(N)
O(N)
.

In the following chapters, we will apply the Two Pointers approach to solve a few problems.

https://www.educative.io/courses/grokking-the-coding-interview/xog6q15W9GP

Problem Statement#
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to 
the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to 
the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11

*/

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
      if (arr[start] + arr[end] > targetSum) {
        // need to decrease end
        end--;
      } else if (arr[start] + arr[end] < targetSum) {
        // need to increase start
        start++;
      } else {
        // same as target, return
        return make_pair(start, end);
      }
    }
    return make_pair(-1, -1);
  }
};


