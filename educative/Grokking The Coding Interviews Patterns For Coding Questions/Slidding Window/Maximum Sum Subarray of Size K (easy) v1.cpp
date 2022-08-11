/*

https://www.educative.io/courses/grokking-the-coding-interview/JPKr0kqLGNP

Problem Statement#
Given an array of positive numbers and a positive number ‘k,’ find the maximum 
sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].

*/

using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  // 2022.8.9, by Hsinan, follow template
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    // TODO: Write your code here
    double sum = 0;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      sum = sum + arr[end];
      if (end >= k-1) {
        if (sum > maxSum) maxSum = sum;
        sum = sum - arr[start];
        start++;
      }
    }
    return maxSum;
  }
};

