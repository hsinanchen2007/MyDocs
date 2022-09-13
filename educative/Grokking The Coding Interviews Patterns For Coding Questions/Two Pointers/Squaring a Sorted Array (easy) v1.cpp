/*

https://www.educative.io/courses/grokking-the-coding-interview/R1ppNG3nV9R

Problem Statement
Given a sorted array, create a new array containing squares of all the numbers of the 
input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]

*/

using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class SortedArraySquares100 {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    vector<int> squares(n);
    multiset<int> squared;
    // TODO: Write your code here
    for (int i = 0; i < arr.size(); i++) {
      squared.insert(arr[i] * arr[i]);
    }
    for_each(squared.begin(), squared.end(), [&](int v){squares[counter]=v; counter++;});
    return squares;
  }
};

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    vector<int> squares(n);
    // TODO: Write your code here
    for_each(arr.begin(), arr.end(), [&](int v){squares[i] = arr[i] * arr[i]; i++;});
    sort(squares.begin(), squares.end());
    return squares;
  }
};


