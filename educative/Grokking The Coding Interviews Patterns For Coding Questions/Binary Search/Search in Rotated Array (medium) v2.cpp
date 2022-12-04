/*

Solution #
The problem follows the Binary Search pattern. We can use a similar approach as discussed in Order-agnostic 
Binary Search and modify it similar to Search Bitonic Array to search for the ‘key’ in the rotated array.

After calculating the middle, we can compare the numbers at indices start and middle. This will give us two 
options:

If arr[start] <= arr[middle], the numbers from start to middle are sorted in ascending order.
Else, the numbers from middle+1 to end are sorted in ascending order.
Once we know which part of the array is sorted, it is easy to adjust our ranges. For example, if option-1 is 
true, we have two choices:

By comparing the ‘key’ with the numbers at index start and middle we can easily find out if the ‘key’ lies 
between indices start and middle; if it does, we can skip the second part => end = middle -1. Else, we can 
skip the first part => start = middle + 1.

Let’s visually see this with the above-mentioned Example-2:

 Search 'key' = 10  
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted 
 part, hence start = middle +1  
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted 
 part, hence end = middle - 1  
 
 We have found the key!  
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
 Since arr[start] <= arr[middle], we can conclude that all numbers from start --> middle are sorted in ascending 
 order  
 Since arr[start] >  arr[middle], we can conclude that all numbers from middle --> end are sorted in ascending 
 order  

Since there are no duplicates in the given array, it is always easy to skip one part of the array in each iteration. 
However, if there are duplicates, it is not always possible to know which part is sorted. We will look into this 
case in the ‘Similar Problems’ section.

Time complexity#
Since we are reducing the search range by half at every step, this means that the time complexity of our algorithm 
will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key) {
        return mid;
      }

      if (arr[start] <= arr[mid]) {  // left side is sorted in ascending order
        if (key >= arr[start] && key < arr[mid]) {
          end = mid - 1;
        } else {  // key > arr[mid]
          start = mid + 1;
        }
      } else {  // right side is sorted in ascending order
        if (key > arr[mid] && key <= arr[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }

    // we are not able to find the element in the given array
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}




