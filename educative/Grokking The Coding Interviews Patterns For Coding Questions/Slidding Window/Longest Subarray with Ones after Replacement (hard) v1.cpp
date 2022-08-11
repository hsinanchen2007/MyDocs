/*

https://www.educative.io/courses/grokking-the-coding-interview/B6VypRxPolJ

Problem Statement#
Given an array containing 0s and 1s, if you are allowed to replace no more than 
‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Example 1:

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous 
subarray of 1s having length 6.

Example 2:

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous 
subarray of 1s having length 9.

*/

using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0;
    int maxRepeat = 0;
    for (int end = 0; end < arr.size(); end++) {
      if (arr[end] == 1) maxRepeat++;
      if (end - start + 1 - maxRepeat > k) {
        if (arr[start] == 1) maxRepeat--;
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};



