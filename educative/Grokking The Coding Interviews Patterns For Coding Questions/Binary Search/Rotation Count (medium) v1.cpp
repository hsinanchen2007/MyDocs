/*

https://www.educative.io/courses/grokking-the-coding-interview/7nPmB8mZ6vj

Rotation Count (medium)#
Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.
    1   
    3   
    8   
    10   
    15   
 Original array:  
 Array after 2 rotations:  
    10   
    15   
    1   
    3   
    8   
Example 2:

Input: [4, 5, 7, 9, 10, -1, 2]
Output: 5
Explanation: The array has been rotated 5 times.
 Original array:  
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
 Array after 5 rotations:  
Example 3:

Input: [1, 3, 8, 10]
Output: 0
Explanation: The array has been not been rotated.

*/

using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (middle < right && arr[middle] > arr[middle + 1]) return middle + 1;
      if (middle > left && arr[middle] < arr[middle - 1]) return middle;
      if (arr[left] < arr[middle]) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return 0;
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{9, 10, 1, 2, 3, 4, 5, 6, 7, 8}) << endl;
}
