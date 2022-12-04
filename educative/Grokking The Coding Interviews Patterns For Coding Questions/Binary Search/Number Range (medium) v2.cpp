/*

https://www.educative.io/courses/grokking-the-coding-interview/R1B78K9oBEz

Solution#
The problem follows the Binary Search pattern. Since Binary Search helps us find a number 
in a sorted array efficiently, we can use a modified version of the Binary Search to find 
the first and the last position of a number.

We can use a similar approach as discussed in Order-agnostic Binary Search. We will try to 
search for the ‘key’ in the given array; if the ‘key’ is found (i.e. key == arr[middle]) 
we have two options:

When trying to find the first position of the ‘key’, we can update end = middle - 1 to see 
if the key is present before middle.

When trying to find the last position of the ‘key’, we can update start = middle + 1 to see 
if the key is present after middle.

In both cases, we will keep track of the last position where we found the ‘key’. These positions 
will be the required range.

Time complexity#
Since, we are reducing the search range by half at every step, this means that the time 
complexity of our algorithm will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    result.first = search(arr, key, false);
    if (result.first != -1) {  // no need to search, if 'key' is not present in the input array
      result.second = search(arr, key, true);
    }
    return result;
  }

 private:
  // modified Binary Search
  static int search(const vector<int> &arr, int key, bool findMaxIndex) {
    int keyIndex = -1;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // key == arr[mid]
        keyIndex = mid;
        if (findMaxIndex) {
          start = mid + 1;  // search ahead to find the last index of 'key'
        } else {
          end = mid - 1;  // search behind to find the first index of 'key'
        }
      }
    }
    return keyIndex;
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
