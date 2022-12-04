/*

https://www.educative.io/courses/grokking-the-coding-interview/mymvP915LY9

Solution#
The problem follows the Binary Search pattern. Since Binary Search helps us find a number in a sorted array 
efficiently, we can use a modified version of the Binary Search to find the number that has the minimum 
difference with the given ‘key’.

We can use a similar approach as discussed in Order-agnostic Binary Search. We will try to search for the 
‘key’ in the given array. If we find the ‘key’ we will return it as the minimum difference number. If we can’t 
find the ‘key’, (at the end of the loop) we can find the differences between the ‘key’ and the numbers pointed 
out by indices start and end, as these two numbers will be closest to the ‘key’. The number that gives minimum 
difference will be our required number.

Time complexity#
Since, we are reducing the search range by half at every step, this means the time complexity of our algorithm 
will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    if (key < arr[0]) {
      return arr[0];
    }
    if (key > arr[arr.size() - 1]) {
      return arr[arr.size() - 1];
    }

    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {
        return arr[mid];
      }
    }

    // at the end of the while loop, 'start == end+1'
    // we are not able to find the element in the given array
    // return the element which is closest to the 'key'
    if ((arr[start] - key) < (key - arr[end])) {
      return arr[start];
    }
    return arr[end];
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}

