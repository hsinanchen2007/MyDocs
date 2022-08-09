/*

This problem follows the Sliding Window pattern, and we can use a similar strategy 
as discussed in Maximum Sum Subarray of Size K. There is one difference though: 
in this problem, the sliding window size is not fixed. Here is how we will solve 
this problem:

First, we will add-up elements from the beginning of the array until their sum 
becomes greater than or equal to ‘S.’ These elements will constitute our sliding 
window. We are asked to find the smallest such window having a sum greater than or 
equal to ‘S.’ We will remember the length of this window as the smallest window so 
far. After this, we will keep adding one element in the sliding window (i.e., slide 
the window ahead) in a stepwise fashion. In each step, we will also try to shrink 
the window from the beginning. We will shrink the window until the window’s sum 
is smaller than ‘S’ again. This is needed as we intend to find the smallest window. 
This shrinking will also happen in multiple steps; in each step, we will do two 
things: Check if the current window length is the smallest so far, and if so, 
remember its length. Subtract the first element of the window from the running sum 
to shrink the sliding window. Here is the visual representation of this algorithm 
for the Example-1:

Time Complexity#
The time complexity of the above algorithm will be O(N)

The outer for loop runs for all elements, and the inner while loop processes each 
element only once; therefore, the time complexity of the algorithm will be O(N+N)
, which is asymptotically equivalent to O(N)

Space Complexity#
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int minLength = numeric_limits<int>::max();
    int windowSum = 0;
      int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      windowSum += arr[windowEnd];
      // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
      while (windowSum >= S) {
        minLength = min(minLength, windowEnd - windowStart + 1);
        windowSum -= arr[windowStart];
        windowStart++;
        }      
      }
    return minLength == numeric_limits<int>::max() ? 0 : minLength;
  }
};

int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
}

