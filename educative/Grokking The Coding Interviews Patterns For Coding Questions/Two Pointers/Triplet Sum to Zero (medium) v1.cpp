/*

https://www.educative.io/courses/grokking-the-coding-interview/gxk639mrr5r

Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.

Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 && arr[i - 1] == arr [i]) continue;
      int needed = 0 - arr[i];
      int start = i + 1;
      int end = arr.size() - 1;
      while (start < end) {
        if (arr[start] + arr[end] == needed) {
          triplets.push_back({arr[i], arr[start], arr[end]});
          start++;
          end--;
        } else if (arr[start] + arr[end] > needed) {
          end--;
        } else {
          start++;
        }
      }
    }
    return triplets;
  }
};
  
