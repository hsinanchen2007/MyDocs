/*

https://www.educative.io/courses/grokking-the-coding-interview/mEGORlpZYJE

Search Bitonic Array (medium)#
Given a Bitonic array, find if a given ‘key’ is present in it. An array is considered bitonic 
if it is monotonically increasing and then monotonically decreasing. Monotonically increasing 
or decreasing means that for any index i in the array arr[i] != arr[i+1].

Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.

Example 1:

Input: [1, 3, 8, 4, 3], key=4
Output: 3

Example 2:

Input: [3, 8, 3, 1], key=8
Output: 1

Example 3:

Input: [1, 3, 8, 12], key=12
Output: 3

Example 4:

Input: [10, 9, 8], key=10
Output: 0

*/

using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int search(const vector<int> &arr, int key) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] < key) {
        if (middle < arr.size() - 1 && arr[middle] < arr[middle + 1]) {
          // increasing
          left = middle + 1;
        } else if (middle > 0) {
          // decreasing
          right = middle - 1;
        }
      } else if (arr[middle] > key) {
        if (middle > 0 && arr[middle] < arr[middle + 1]) {
          // increasing
          right = middle - 1;
        } else if (middle < arr.size() - 1) {
          // decreasing
          left = middle + 1;
        }
      } else if (arr[middle] == key) {
        // found
        return middle;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}
