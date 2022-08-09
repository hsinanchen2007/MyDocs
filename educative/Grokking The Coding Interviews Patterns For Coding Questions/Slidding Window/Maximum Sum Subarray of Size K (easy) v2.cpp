/*

A basic brute force solution will be to calculate the sum of all ‘k’ 
sized subarrays of the given array to find the subarray with the highest 
sum. We can start from every index of the given array and add the 
next ‘k’ elements to find the subarray’s sum. Following is the visual 
representation of this algorithm for Example-1:

The above algorithm’s time complexity will be O(N*K), where ‘N’ is the 
total number of elements in the given array. Is it possible to find a 
better algorithm than this?

*/

using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0, windowSum;
    for (int i = 0; i <= arr.size() - k; i++) {
      windowSum = 0;
      for (int j = i; j < i + k; j++) {
        windowSum += arr[j];
      }
      maxSum = max(maxSum, windowSum);
    }

    return maxSum;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}

