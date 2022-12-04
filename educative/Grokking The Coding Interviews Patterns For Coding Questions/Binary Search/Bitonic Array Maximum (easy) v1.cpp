/*

https://www.educative.io/courses/grokking-the-coding-interview/RMyRR6wZoYK

Problem Statement#
Find the maximum value in a given Bitonic array. An array is considered bitonic if it is monotonically 
increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any 
index i in the array arr[i] != arr[i+1].

Example 1:

Input: [1, 3, 8, 12, 4, 2]
Output: 12
Explanation: The maximum number in the input bitonic array is '12'.

Example 2:

Input: [3, 8, 3, 1]
Output: 8

Example 3:

Input: [1, 3, 8, 12]
Output: 12

Example 4:

Input: [10, 9, 8]
Output: 10

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class MaxInBitonicArray100 {
 public:
  static int findMax(const vector<int>& arr) {
    // TODO: Write your code here
    auto item = max_element(arr.begin(), arr.end());
    if (item != arr.end()) return *item;
    return -1;
  }
};

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;

    // very tricky that this patterns cannot use (left <= right)
    // because it has no such arr[middle] == arr[middle + 1]
    // condition
    while (left < right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] > arr[middle + 1]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return arr[left];
  }
};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
