/*

https://www.educative.io/courses/grokking-the-coding-interview/3YlQz7PE7OA

Problem Statement#
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close 
to the target number as possible, return the sum of the triplet. If there are more than one such triplet, 
return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.

Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.

Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int minDiff = numeric_limits<int>::max();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
      int needed = targetSum - arr[i];
      int start = i + 1;
      int end = arr.size() - 1;
      while (start < end) {
        if (arr[start] + arr[end] == needed) {
          return targetSum;
        } else if (arr[start] + arr[end] > needed) {
          int tmp = targetSum - arr[i] - arr[start] - arr[end];
          // need to use abs below, as minDiff may be > or < 0
          if (abs(minDiff) > abs(tmp)) minDiff = tmp;
          end--;
        } else {
          int tmp = targetSum - arr[i] - arr[start] - arr[end];
          // need to use abs below, as minDiff may be > or < 0
          if (abs(minDiff) > abs(tmp)) minDiff = tmp;
          start++;
        }
      }
    }
    // note that we are asked to return closest sum, not diff
    return targetSum - minDiff;
  }
};
