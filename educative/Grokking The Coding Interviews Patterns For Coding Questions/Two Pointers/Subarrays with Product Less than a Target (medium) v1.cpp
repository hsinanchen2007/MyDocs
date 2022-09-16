/*

https://www.educative.io/courses/grokking-the-coding-interview/RMV1GV1yPYz

Problem Statement#
Given an array with positive numbers and a positive target number, find all of its contiguous 
subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30 
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.

Example 2:

Input: [8, 2, 6, 5], target=50 
Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5] 
Explanation: There are seven contiguous subarrays whose product is less than the target.

*/

using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    // TODO: Write your code here
    double product = 1;
    int left = 0;

    // below line 16 ~ 20 is the key of the question
    for (int right = 0; right < arr.size(); right++) {
      product *= arr[right];
      while (product >= target && left <= right) {
        product /= arr[left++];
      }

      // put all valid answers into result, note that it is not simply
      // putting {arr[i], arr[left], arr[right]} into result
      deque<int> tempList;
      for (int i = right; i >= left; i--) {
        tempList.push_front(arr[i]);
        vector<int> resultVec;
        std::move(std::begin(tempList), std::end(tempList), std::back_inserter(resultVec));
        result.push_back(resultVec);
      }
    }
    return result;
  }
};


