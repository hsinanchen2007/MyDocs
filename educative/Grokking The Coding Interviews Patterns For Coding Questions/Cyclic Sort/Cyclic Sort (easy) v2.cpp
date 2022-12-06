/*

https://www.educative.io/courses/grokking-the-coding-interview/B8qXVqVwDKY

Solution
As we know, the input array contains numbers from the range 1 to n. We can use this fact to devise 
an efficient way to sort the numbers. Since all numbers are unique, we can try placing each number 
at its correct place, i.e., placing 1 at index ‘0’, placing 2 at index ‘1’, and so on.

To place a number (or an object in general) at its correct index, we first need to find that number. 
If we first find a number and then place it at its correct place, it will take us O(N^2), which is 
not acceptable.

Instead, what if we iterate the array one number at a time, and if the current number we are iterating 
is not at the correct index, we swap it with the number at its correct index. This way, we will go 
through all numbers and place them at their correct indices, hence, sorting the whole array.

Let’s see this visually with the above-mentioned Example-2:

After the swap, number '2' is placed at its correct index.
Number '2' is not at its correct place, let's swap it with the correct index.

2
6
4
3
1
5
6
2
4
3
1
5
1
2
3
4
5
6

Whole array is sorted.
6
2
4
3
1
5

Number '6' is not at its correct place, let's swap it with the correct index.
We'll not move on to the next number until we have a correct number at 'start'.
5
2
4
3
1
6

After the swap, number '6' is placed at its correct index.
We'll not move on to the next number until we have a correct number at 'start'.
Number '5' is not at its correct place, let's swap it with the correct index.
1
2
4
3
5
6

After the swap, both '6' and '1' are placed at their correct place.
Number '1' is at its correct index, let's move on to the next number.
1
2
4
3
5
6
1
2
4
3
5
6
Number '2' is at its correct index, let's move on to the next number.
1
2
3
4
5
6

After the swap, both '3' and '4' are placed at their correct place.
All the remaining numbers are at their correct places.

Time complexity
The time complexity of the above algorithm is O(n). Although we are not incrementing the index i 
when swapping the numbers, this will result in more than n iterations of the loop, but in the 
worst-case scenario, the while loop will swap a total of n-1 numbers, and once a number is at its 
correct index, we will move on to the next number by incrementing i. So overall, our algorithm 
will take O(n) + O(n-1) which is asymptotically equivalent to O(n)

Space complexity
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      int j = nums[i] - 1;
      if (nums[i] != nums[j]) {
        swap(nums, i, j);
      } else {
        i++;
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
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{1, 5, 6, 4, 3, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

