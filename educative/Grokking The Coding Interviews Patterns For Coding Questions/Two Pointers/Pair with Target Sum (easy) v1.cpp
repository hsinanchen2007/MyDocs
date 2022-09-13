/*

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


