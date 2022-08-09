/*

Problem Statement#
Given an array of positive integers and a number ‘S,’ find the length of the 
smallest contiguous subarray whose sum is greater than or equal to ‘S’. 
Return 0 if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [5, 2].

Example 2:

Input: [2, 1, 5, 2, 8], S=7
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to ‘7’ is [8].

Example 3:

Input: [3, 4, 1, 1, 6], S=8
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to ‘8’ are [3, 4, 1] 
or [1, 1, 6].

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  // 2022.8.9, by Hsinan. "while" condition is the key for none-fixed slidding window
  // that it will increase start based on the condition, cannot use "if" condition
  static int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    int sum = 0;
    int start = 0;
    int answer = numeric_limits<int>::max();
    for (int end = 0; end < arr.size(); end++) {
      sum = sum + arr[end];
      while (sum >= S) {
        answer = min(answer, end - start + 1);
        sum = sum - arr[start];
        start++;
      }
    }

    return (answer != numeric_limits<int>::max()) ? answer : -1;
  }
};

