/*

https://www.educative.io/courses/grokking-the-coding-interview/N8XZQ1q1O46

Search in Rotated Array (medium)
Given an array of numbers which is sorted in ascending order and also rotated by some 
arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ 
is not present, return -1. You can assume that the given array does not have any 
duplicates.

Example 1:

Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
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

Input: [4, 5, 7, 9, 10, -1, 2], key = 10
Output: 4
Explanation: '10' is present in the array at index '4'.
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

*/

using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] == key) return middle;
      if (arr[left] <= arr[middle]) { // left side is increasing
        // now check middle and left with key
        if (arr[left] <= key && arr[middle] > key) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      } else { // right side is increasing
        // now check middle and right with key
        if (arr[middle] < key && arr[right] >= key) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}


