/*

https://www.educative.io/courses/grokking-the-coding-interview/R1v4P0R7VZw

Solution#
This problem follows the Binary Search pattern. We can use a similar strategy as discussed 
in Search in Rotated Array.

In this problem, actually, we are asked to find the index of the minimum element. The number 
of times the minimum element is moved to the right will be equal to the number of rotations. 
An interesting fact about the minimum element is that it is the only element in the given 
array which is smaller than its previous element. Since the array is sorted in ascending order, 
all other elements are bigger than their previous element.

After calculating the middle, we can compare the number at index middle with its previous and 
next number. This will give us two options:

If arr[middle] > arr[middle + 1], then the element at middle + 1 is the smallest.
If arr[middle - 1] > arr[middle], then the element at middle is the smallest.
To adjust the ranges we can follow the same approach as discussed in Search in Rotated Array. 
Comparing the numbers at indices start and middle will give us two options:

If arr[start] < arr[middle], the numbers from start to middle are sorted.
Else, the numbers from middle + 1 to end are sorted.

Time complexity#
Since we are reducing the search range by half at every step, this means that the time complexity 
of our algorithm will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
      int mid = start + (end - start) / 2;

      if (mid < end && arr[mid] > arr[mid + 1]) {  // if mid is greater than the next element
        return mid + 1;
      }
      if (mid > start && arr[mid - 1] > arr[mid]) {  // if mid is smaller than the previous element
        return mid;
      }

      if (arr[start] < arr[mid]) {  // left side is sorted, so the pivot is on right side
        start = mid + 1;
      } else {  // right side is sorted, so the pivot is on the left side
        end = mid - 1;
      }
    }

    return 0;  // the array has not been rotated
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
