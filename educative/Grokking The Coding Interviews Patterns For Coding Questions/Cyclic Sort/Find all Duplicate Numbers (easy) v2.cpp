/*

https://www.educative.io/courses/grokking-the-coding-interview/RLw1Pjk1GQ0

Solution
This problem follows the Cyclic Sort pattern and shares similarities with Find the Duplicate Number. 
Following a similar approach, we will place each number at its correct index. After that, we will 
iterate through the array to find all numbers that are not at the correct indices. All these numbers 
are duplicates.

Time complexity
The time complexity of the above algorithm is O(n)

Space complexity
Ignoring the space required for storing the duplicates, the algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
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

    vector<int> duplicateNumbers;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        duplicateNumbers.push_back(nums[i]);
      }
    }

    return duplicateNumbers;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 4, 4, 5, 5};
  vector<int> duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {5, 4, 7, 2, 3, 5, 3};
  duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;
}

