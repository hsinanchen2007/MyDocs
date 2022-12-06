/*

https://www.educative.io/courses/grokking-the-coding-interview/N7Vw2GBQr6D

Solution
This problem follows the Cyclic Sort pattern and shares similarities with Find all Duplicate Numbers. 
Following a similar approach, we will place each number at its correct index. Once we are done with 
the cyclic sort, we will iterate through the array to find the number that is not at the correct index. 
Since only one number got corrupted, the number at the wrong index is the duplicated number and the 
index itself represents the missing number.

Time complexity
The time complexity of the above algorithm is O(n)

Space complexity
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return vector<int>{nums[i], i + 1};
      }
    }

    return vector<int>{-1, -1};
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}

