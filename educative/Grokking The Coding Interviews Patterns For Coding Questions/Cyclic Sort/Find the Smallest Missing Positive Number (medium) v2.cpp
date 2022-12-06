/*

https://www.educative.io/courses/grokking-the-coding-interview/R1GXQ071GQ0

Solution
This problem follows the Cyclic Sort pattern and shares similarities with Find the Missing Number with 
one big difference. In this problem, the numbers are not bound by any range so we can have any number 
in the input array.

However, we will follow a similar approach though as discussed in Find the Missing Number to place the 
numbers on their correct indices and ignore all numbers that are out of the range of the array (i.e., 
all negative numbers and all numbers greater than the length of the array). Once we are done with the 
cyclic sort we will iterate the array and the first index that does not have the correct number will be 
the smallest missing positive number!

Time complexity
The time complexity of the above algorithm is O(n)

Space complexity
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
}

