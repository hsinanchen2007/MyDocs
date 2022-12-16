/*

https://www.educative.io/courses/grokking-the-coding-interview/myJK6Wvj00R

1. Brute-force 
The simplest brute-force algorithm will be to find the Kth smallest number in a 
step by step fashion. This means that, first, we will find the smallest element, 
then 2nd smallest, then 3rd smallest and so on, until we have found the Kth smallest 
element. Here is what the algorithm will look like:

Time & Space Complexity
The time complexity of the above algorithm will be O(N*K). The algorithm runs in 
constant space O(1)

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    // to handle duplicates, we will keep track of previous smallest number and its index
    int previousSmallestNum = numeric_limits<int>::min();
    int previousSmallestIndex = -1;
    int currentSmallestNum = numeric_limits<int>::max();
    int currentSmallestIndex = -1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] > previousSmallestNum && nums[j] < currentSmallestNum) {
          // found the next smallest number
          currentSmallestNum = nums[j];
          currentSmallestIndex = j;
        } else if (nums[j] == previousSmallestNum && j > previousSmallestIndex) {
          // found a number which is equal to the previous smallest number; since numbers can
          // repeat, we will consider 'nums[j]' only if it has a different index than previous
          // smallest
          currentSmallestNum = nums[j];
          currentSmallestIndex = j;
          break;  // break here as we have found our definitive next smallest number
        }
      }
      // current smallest number becomes previous smallest number for the next iteration
      previousSmallestNum = currentSmallestNum;
      previousSmallestIndex = currentSmallestIndex;
      currentSmallestNum = numeric_limits<int>::max();
    }

    return previousSmallestNum;
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}


