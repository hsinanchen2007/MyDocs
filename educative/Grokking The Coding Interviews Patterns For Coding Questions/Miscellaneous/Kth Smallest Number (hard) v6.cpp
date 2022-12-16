/*

https://www.educative.io/courses/grokking-the-coding-interview/myJK6Wvj00R

6. Using Randomized Partitioning Scheme of Quicksort
As mentioned above, the worst case for Quicksort occurs when the partition procedure 
splits the N-length array into arrays of size ‘1’ and ‘N−1’. To mitigate this, instead 
of always picking a fixed index for pivot (e.g., in the above algorithm we always pick 
nums[high] as the pivot), we can randomly select an element as pivot. After randomly 
choosing the pivot element, we expect the split of the input array to be reasonably well 
balanced on average.

Here is what our algorithm will look like (only the highlighted lines have changed):

Time & Space Complexity
The above algorithm has the same worst and average case time complexities as mentioned 
for the previous algorithm. But choosing the pivot randomly has the effect of rendering 
the worst-case very unlikely, particularly for large arrays. Therefore, the expected time 
complexity of the above algorithm will be O(N), but the absolute worst case is still O(N^2)
. Practically, this algorithm is a lot faster than the non-randomized version.

*/

using namespace std;

#include <iostream>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(vector<int> &nums, int k) {
    return findKthSmallestNumberRec(nums, k, 0, nums.size() - 1);
  }

  static int findKthSmallestNumberRec(vector<int> &nums, int k, int start, int end) {
    int p = partition(nums, start, end);

    if (p == k - 1) {
      return nums[p];
    }

    if (p > k - 1)  // search lower part
    {
      return findKthSmallestNumberRec(nums, k, start, p - 1);
    }

    // search higher part
    return findKthSmallestNumberRec(nums, k, p + 1, end);
  }

 private:
  static int partition(vector<int> &nums, int low, int high) {
    if (low == high) {
      return low;
    }

    srand(time(0));
    int pivotIndex = low + rand() % (high - low);
    swap(nums, pivotIndex, high);

    int pivot = nums[high];
    for (int i = low; i < high; i++) {
      // all elements less than 'pivot' will be before the index 'low'
      if (nums[i] < pivot) {
        swap(nums, low++, i);
      }
    }
    // put the pivot in its correct place
    swap(nums, low, high);

    return low;
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {1, 5, 12, 2, 11, 5};
  int result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vec, 4);
  cout << "Kth smallest number is: " << result << endl;

  vec = {5, 12, 11, -1, 12};
  result = KthSmallestNumber::findKthSmallestNumber(vec, 3);
  cout << "Kth smallest number is: " << result << endl;
}
