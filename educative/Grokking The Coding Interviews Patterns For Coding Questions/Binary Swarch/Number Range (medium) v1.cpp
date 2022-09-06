/*

https://www.educative.io/courses/grokking-the-coding-interview/R1B78K9oBEz

Problem Statement#
Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. 
The range of the ‘key’ will be the first and last position of the ‘key’ in the array.

Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].

Example 1:

Input: [4, 6, 6, 6, 9], key = 6Output: [1, 3]

Example 2:

Input: [1, 3, 8, 10, 15], key = 10Output: [3, 3]

Example 3:

Input: [1, 3, 8, 10, 15], key = 12Output: [-1, -1]

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    // TODO: Write your code here
    auto low = lower_bound(arr.begin(), arr.end(), key);
    auto high = upper_bound(arr.begin(), arr.end(), key);
    if (low == arr.end() || high == arr.end() || *low != key) return result;
    int indexL = distance(arr.begin(), low);
    int indexH = distance(arr.begin(), high) - 1; /* upper_bound return will be always next larger element */
    return {indexL, indexH};
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}


