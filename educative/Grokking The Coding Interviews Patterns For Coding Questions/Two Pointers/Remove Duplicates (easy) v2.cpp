/*

https://www.educative.io/courses/grokking-the-coding-interview/mEEA22L5mNA

Solution#

In this problem, we need to separate the duplicates in-place such that the resultant length of 
the array remains sorted. As the input array is sorted, therefore, one way to do this is to shift 
the elements left whenever we encounter duplicates. In other words, we will keep one pointer for 
iterating the array and one pointer for placing the next non-duplicate number. So our algorithm 
will be to iterate the array and whenever we see a non-duplicate number we move it next to the 
last non-duplicate number we’ve seen.

Time Complexity#
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements 
in the given array.

Space Complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    int nextNonDuplicate = 1;  // index of the next non-duplicate element
    for (int i = 0; i < arr.size(); i++) {
      if (arr[nextNonDuplicate - 1] != arr[i]) {
        arr[nextNonDuplicate] = arr[i];
        nextNonDuplicate++;
      }
    }

    return nextNonDuplicate;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}

