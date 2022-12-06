/*

https://www.educative.io/courses/grokking-the-coding-interview/Y52qNM0ljWK

Solution
This problem follows the Cyclic Sort pattern and shares similarities with Find the Missing Number 
with one difference. In this problem, there can be many duplicates whereas in ‘Find the Missing 
Number’ there were no duplicates and the range was greater than the length of the array.

However, we will follow a similar approach though as discussed in Find the Missing Number to place 
the numbers on their correct indices. Once we are done with the cyclic sort we will iterate the array 
to find all indices that are missing the correct numbers.

Time complexity
The time complexity of the above algorithm is O(n)

Space complexity
Ignoring the space required for the output array, the algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
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

    vector<int> missingNumbers;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        missingNumbers.push_back(i + 1);
      }
    }

    return missingNumbers;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 4, 1, 2};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 2, 1};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}


