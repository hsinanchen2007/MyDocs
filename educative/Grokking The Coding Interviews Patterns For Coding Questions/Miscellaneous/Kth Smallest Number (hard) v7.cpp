/*

https://www.educative.io/courses/grokking-the-coding-interview/myJK6Wvj00R

7. Using the Median of Medians
We can use the Median of Medians algorithm to choose a good pivot for the partitioning 
algorithm of the Quicksort. This algorithm finds an approximate median of an array in 
linear time O(N). When this approximate median is used as the pivot, the worst-case 
complexity of the partitioning procedure reduces to linear O(N), which is also the asymptotically 
optimal worst-case complexity of any sorting/selection algorithm. This algorithm was 
originally developed by Blum, Floyd, Pratt, Rivest, and Tarjan and was describe in their 
1973 paper.

This is how the partitioning algorithm works:

If we have 5 or less than 5 elements in the input array, we simply take its first element 
as the pivot. If not then we divide the input array into subarrays of five elements (for 
simplicity we can ignore any subarray having less than five elements). Sort each subarray to 
determine its median. Sorting a small and fixed numbered array takes constant time. At the end 
of this step, we have an array containing medians of all the subarray. Recursively call the 
partitioning algorithm on the array containing medians until we get our pivot. Every time the 
partition procedure needs to find a pivot, it will follow the above three steps. 

Here is what this algorithm will look like:

Time & Space Complexity
The above algorithm has a guaranteed O(N) worst-case time. Please see the proof of its running 
time here and under “Selection-based pivoting”. The worst-case space complexity is O(N).

Conclusion
Theoretically, the Median of Medians algorithm gives the best time complexity of O(N) but practically 
both the Median of Medians and the Randomized Partitioning algorithms nearly perform equally.

In the context of Quicksort, given an O(N) selection algorithm using the Median of Medians, one 
can use it to find the ideal pivot (the median) at every step of quicksort and thus produce a 
sorting algorithm with O(NlogN) running time in the worst-case. Though practical implementations 
of this variant are considerably slower on average, they are of theoretical interest because they 
show that an optimal selection algorithm can yield an optimal sorting algorithm.

*/

using namespace std;

#include <algorithm>
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

    if (p > k - 1) { // search lower part
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

    int median = medianOfMedians(nums, low, high);
    // find the median in the array and swap it with 'nums[high]' which will become our pivot
    for (int i = low; i < high; i++) {
      if (nums[i] == median) {
        swap(nums, i, high);
        break;
      }
    }

    int pivot = nums[high];
    for (int i = low; i < high; i++) {
      // all elements less than 'pivot' will be before the index 'low'
      if (nums[i] < pivot) {
        swap(nums, low++, i);
      }
    }
    // put the pivot in its correct place, remember nums[high] is our pivot
    swap(nums, low, high);
    return low;
  }

  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  static int medianOfMedians(vector<int> &nums, int low, int high) {
    int n = high - low + 1;
    // if we have less than 5 elements, ignore the partitioning algorithm
    if (n < 5) {
      return nums[low];
    }

    // for simplicity, lets ignore any partition with less than 5 elements
    int numOfPartitions = n / 5; // represents total number of 5 elements partitions
    vector<int> medians(numOfPartitions);
    for (int i = 0; i < numOfPartitions; i++) {
      int partitionStart = low + i * 5; // starting index of the current partition
      sort(nums.begin() + partitionStart,
           nums.begin() + partitionStart + 5); // sort the 5 elements array
      medians[i] = nums[partitionStart + 2];   // get the middle element (or the median)
    }

    return partition(medians, 0, numOfPartitions - 1);
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
