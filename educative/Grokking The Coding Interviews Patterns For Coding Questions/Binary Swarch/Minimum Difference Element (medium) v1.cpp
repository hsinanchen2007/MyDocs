/*

https://www.educative.io/courses/grokking-the-coding-interview/mymvP915LY9

Problem Statement#
Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given ‘key’.

Example 1:

Input: [4, 6, 10], key = 7
Output: 6
Explanation: The difference between the key '7' and '6' is minimum than any other number in the array 

Example 2:

Input: [4, 6, 10], key = 4
Output: 4

Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: 10

Example 4:

Input: [4, 6, 10], key = 17
Output: 10

*/

using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] < key) {
        left = middle + 1;
      } else if (arr[middle] > key) {
        right = middle - 1;
      } else if (arr[middle] == key) {
        return arr[middle];
      }
    }
    // here, left > right now, compare which one has smaller difference
    int diff1 = std::abs(arr[left] - key);
    int diff2 = std::abs(arr[right] - key);

    return (diff1 >= diff2) ? arr[right] : arr[left];
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}

