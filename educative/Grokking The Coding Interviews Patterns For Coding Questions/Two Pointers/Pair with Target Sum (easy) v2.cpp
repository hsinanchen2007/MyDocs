/*

https://www.educative.io/courses/grokking-the-coding-interview/xog6q15W9GP

Solution#
Since the given array is sorted, a brute-force solution could be to iterate through the array, 
taking one number at a time and searching for the second number through Binary Search. The time 
complexity of this algorithm will be O(N*logN). Can we do better than this?

We can follow the Two Pointers approach. We will start with one pointer pointing to the beginning 
of the array and another pointing at the end. At every step, we will see if the numbers pointed 
by the two pointers add up to the target sum. If they do, we have found our pair; otherwise, we 
will do one of two things:

If the sum of the two numbers pointed by the two pointers is greater than the target sum, this 
means that we need a pair with a smaller sum. So, to try more pairs, we can decrement the end-pointer.
If the sum of the two numbers pointed by the two pointers is smaller than the target sum, this 
means that we need a pair with a larger sum. So, to try more pairs, we can increment the start-pointer.

Here is the visual representation of this algorithm for Example-1:

    1   
    2   
    3   
    4   
    6   
 target sum = 6  
 1 + 6 > target sum, therefore let's decrement Pointer2  
    1   
    2   
    3   
    4   
    6   
 1 + 4 < target sum, therefore let's increment Pointer1  
    1   
    2   
    3   
    4   
    6   
 2 + 4 == target sum, we have found our pair!  

Time Complexity#
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements in 
the given array.

Space Complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
public:
  static pair<int, int> search(const vector<int> &arr, int targetSum) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
      int currentSum = arr[left] + arr[right];
      if (currentSum == targetSum) { // found the pair
        return make_pair(left, right);
      }

      if (targetSum > currentSum)
        left++; // we need a pair with a bigger sum
      else
        right--; // we need a pair with a smaller sum
    }
    return make_pair(-1, -1);
  }
};

int main(int argc, char *argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}



