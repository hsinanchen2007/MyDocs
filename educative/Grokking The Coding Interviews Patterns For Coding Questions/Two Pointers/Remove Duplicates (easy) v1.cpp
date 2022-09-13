/*

https://www.educative.io/courses/grokking-the-coding-interview/mEEA22L5mNA

Problem Statement#
Given an array of sorted numbers, remove all duplicate number instances from it in-place, such that 
each element appears only once. The relative order of the elements should be kept the same and you 
should not use any extra space so that that the solution have a space complexity of O(1).

Move all the unique elements at the beginning of the array and after moving return the length of the 
subarray that has no duplicate in it.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].

Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].

*/

using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    // TODO: Write your code here
    int end = 1;
    for (int start = 0; start < arr.size(); start++) {
      // very tricky and nice small code to handle from index 0 to the end
      // for start = 0, it will be arr[0] v.s arr[0] itself, end remains same
      // for start = 1, it will be arr[0] v.s arr[1], if they are different, do arr[1] = arr[1], 
      //                which is assigning value to itself
      // if any arr[i - 1] == arr[i], end will remains same until next different value happened
      if (arr[end - 1] != arr[start]) {
        arr[end] = arr[start];
        end++;
      }
    }
    return end;
  }
};

