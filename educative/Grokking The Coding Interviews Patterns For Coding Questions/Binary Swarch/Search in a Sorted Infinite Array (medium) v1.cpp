/*

https://www.educative.io/courses/grokking-the-coding-interview/B1ZW38kXJB2

Problem Statement#
Given an infinite sorted array (or an array with unknown size), find if a given number ‘key’ is 
present in the array. Write a function to return the index of the ‘key’ if it is present in the 
array, otherwise return -1.

Since it is not possible to define an array with infinite (unknown) size, you will be provided 
with an interface ArrayReader to read elements of the array. ArrayReader.get(index) will return 
the number at index; if the array’s size is smaller than the index, it will return Integer.MAX_VALUE.

Example 1:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
Output: 6
Explanation: The key is present at index '6' in the array.

Example 2:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
Output: -1
Explanation: The key is not present in the array.

Example 3:

Input: [1, 3, 8, 10, 15], key = 15
Output: 4
Explanation: The key is present at index '4' in the array.

Example 4:

Input: [1, 3, 8, 10, 15], key = 200
Output: -1
Explanation: The key is not present in the array.

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    // TODO: Write your code here
    int left = 0;
    int right = 1;
    // find most right and keep updating left
    while (reader->get(right) < key) {
      int newLeft = right + 1;
      right = right + (right - left + 1) * 2;
      left = newLeft;
    }
    // now we got left and right and know the key is within this range
    // perform binary search
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (reader->get(middle) < key) {
        left = middle + 1;
      } else if (reader->get(middle) > key) {
        right = middle - 1;
      } else if (reader->get(middle) == key) {
        return middle;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}


