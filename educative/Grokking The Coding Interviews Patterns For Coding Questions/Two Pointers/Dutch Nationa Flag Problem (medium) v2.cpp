/*

https://www.educative.io/courses/grokking-the-coding-interview/RMBxV6jz6Q0

Solution#
The brute force solution will be to use an in-place sorting algorithm like Heapsort which will 
take O(N*logN). Can we do better than this? Is it possible to sort the array in one iteration?

We can use a Two Pointers approach while iterating through the array. Let’s say the two pointers 
are called low and high which are pointing to the first and the last element of the array respectively. 
So while iterating, we will move all 0s before low and all 2s after high so that in the end, 
all 1s will be between low and high.

Time complexity#
The time complexity of the above algorithm will be O(N) as we are iterating the input array only once.

Space complexity#
The algorithm runs in constant space O(1).

*/

using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    // all elements < low are 0 and all elements > high are 2
    // all elements from >= low < i are 1
    int low = 0, high = arr.size() - 1;
    for (int i = 0; i <= high;) {
      if (arr[i] == 0) {
        swap(arr, i, low);
        i++;
        low++;
      } else if (arr[i] == 1) {
        i++;
      } else {  // the case for arr[i] == 2
        swap(arr, i, high);
        // decrement 'high' only, after the swap the number at index 'i' could be 0, 1 or 2
        high--;
      }
    }
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 0, 2, 1, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 2, 0, 1, 2, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
}
