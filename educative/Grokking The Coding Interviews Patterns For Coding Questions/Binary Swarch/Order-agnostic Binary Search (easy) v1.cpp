/*

Introduction
As we know, whenever we are given a sorted Array or LinkedList or Matrix, and we are asked to find a 
certain element, the best algorithm we can use is the Binary Search.

This pattern describes an efficient way to handle all problems involving Binary Search. We will go 
through a set of problems that will help us build an understanding of this pattern so that we can apply 
this technique to other problems we might come across in the interviews.

Let’s start with our first problem.


https://www.educative.io/courses/grokking-the-coding-interview/R8LzZQlj8lO

Problem Statement #
Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know 
that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should 
assume that the array can have duplicates.

Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

Example 1:

Input: [4, 6, 10], key = 10
Output: 2

Example 2:

Input: [1, 2, 3, 4, 5, 6, 7], key = 5
Output: 4

Example 3:

Input: [10, 6, 4], key = 10
Output: 0

Example 4:

Input: [10, 6, 4], key = 4
Output: 2

*/

using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    bool isIncreasing = (arr[left] < arr[right]) ? true : false;

    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (isIncreasing) {
        // increasing order
        if (arr[middle] < key) {
          left = middle + 1;
        } else if (arr[middle] > key) {
          right = middle - 1;
        } else if (arr[middle == key]) {
          return middle;
        }
      } else {
        // decreasing order
        if (arr[middle] < key) {
          right = middle - 1;
        } else if (arr[middle] > key) {
          left = middle + 1;
        } else if (arr[middle == key]) {
          return middle;
        }
      }
    }
    
    return -1; 
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}



