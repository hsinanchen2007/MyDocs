/*

https://www.educative.io/courses/grokking-the-coding-interview/Bn2KLlOR0lQ

Solution#
This problem follows the Sliding Window pattern and is quite similar to Longest 
Substring with K Distinct Characters. In this problem, we need to find the length 
of the longest subarray with no more than two distinct characters (or fruit types!). 
This transforms the current problem into Longest Substring with K Distinct Characters 
where K=2.

Time Complexity#
The above algorithm’s time complexity will be O(N), where ‘N’ is the number of 
characters in the input array. The outer for loop runs for all characters, and the 
inner while loop processes each character only once; therefore, the time complexity 
of the algorithm will be O(N+N), which is asymptotically equivalent to O(N)

Space Complexity#
The algorithm runs in constant space O(1) as there can be a maximum of three types 
of fruits stored in the frequency map.

Similar Problems#
Problem 1: Longest Substring with at most 2 distinct characters

Given a string, find the length of the longest substring in it with at most two 
distinct characters.

Solution: This problem is exactly similar to our parent problem.

*/

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> fruitFrequencyMap;
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      fruitFrequencyMap[arr[windowEnd]]++;
      // shrink the sliding window, until we are left with '2' fruits in the frequency map
      while ((int)fruitFrequencyMap.size() > 2) {
        fruitFrequencyMap[arr[windowStart]]--;
        if (fruitFrequencyMap[arr[windowStart]] == 0) {
          fruitFrequencyMap.erase(arr[windowStart]);
        }
        windowStart++;  // shrink the window
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}

