/*

https://www.educative.io/courses/grokking-the-coding-interview/3wEkKy6Pr9A

Solution
This problem follows the Cyclic Sort pattern and shares similarities with Find the Missing Number. 
Following a similar approach, we will try to place each number on its correct index. Since there is 
only one duplicate, if while swapping the number with its index both the numbers being swapped are 
same, we have found our duplicate!

Time complexity
The time complexity of the above algorithm is O(n)

Space complexity
The algorithm runs in constant space O(1) but modifies the input array.

*/

using namespace std;

#include <iostream>
#include <vector>

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != i + 1) {
        if (nums[i] != nums[nums[i] - 1]) {
          swap(nums, i, nums[i] - 1);
        } else  // we have found the duplicate
        {
          return nums[i];
        }
      } else {
        i++;
      }
    }

    return -1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 4, 3, 2};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 1, 3, 3, 5, 4};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 4, 1, 4, 4};
  cout << FindDuplicate::findNumber(v1) << endl;
}
