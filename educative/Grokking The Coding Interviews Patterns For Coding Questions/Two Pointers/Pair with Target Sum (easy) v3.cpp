/*

An Alternate approach#
Instead of using a two-pointer or a binary search approach, we can utilize a HashTable to search for 
the required pair. We can iterate through the array one number at a time. Let’s say during our iteration 
we are at number ‘X’, so we need to find ‘Y’ such that “X + Y == Target”. We will do two things here:

Search for ‘Y’ (which is equivalent to “Target - X”) in the HashTable. If it is there, we have found the 
required pair. Otherwise, insert “X” in the HashTable, so that we can search it for the later numbers.

Time Complexity#
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements in 
the given array.

Space Complexity#
The space complexity will also be O(N), as, in the worst case, we will be pushing ‘N’ numbers in the 
HashTable.

*/

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> nums;  // to store number and its index
    for (int i = 0; i < arr.size(); i++) {
      if (nums.find(targetSum - arr[i]) != nums.end()) {
        return make_pair(nums[targetSum - arr[i]], i);
      } else {
        nums[arr[i]] = i;  // put the number and its index in the map
      }
    }
    return make_pair(-1, -1);  // pair not found
  }
};

int main(int argc, char* argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}

