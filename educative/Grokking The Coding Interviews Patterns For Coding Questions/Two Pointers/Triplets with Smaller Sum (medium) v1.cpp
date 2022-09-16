/*

https://www.educative.io/courses/grokking-the-coding-interview/mElknO5OKBO

Problem Statement#
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that 
arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function 
to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]

Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    // erase any possible duplicated one
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 0; i < arr.size(); i++) {
      int start = i + 1;
      int end = arr.size() - 1;
      while (start < end) {
        if (arr[i] + arr[start] + arr[end] < target) {
          // below (end - start) is the key
          // as arr[end] will be the largest one, that means all start to (end - 1) ones 
          // will be also smaller than target with arr[start]
          count = count + (end -start);
          start++;
        } else {
          end--;
        }
      }
    }
    return count;
  }
};

