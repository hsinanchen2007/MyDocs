/*

https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80

Solution#
This problem follows the Sliding Window pattern, and we can use a similar dynamic sliding window 
strategy as discussed in Smallest Subarray With a Greater Sum. We can use a HashMap to remember 
the frequency of each character we have processed. Here is how we will solve this problem:

First, we will insert characters from the beginning of the string until we have K distinct characters 
in the HashMap. These characters will constitute our sliding window. We are asked to find the longest 
such window having no more than K distinct characters. We will remember the length of this window 
as the longest window so far. After this, we will keep adding one character in the sliding window 
(i.e., slide the window ahead) in a stepwise fashion. In each step, we will try to shrink the window 
from the beginning if the count of distinct characters in the HashMap is larger than K. We will 
shrink the window until we have no more than K distinct characters in the HashMap. This is needed 
as we intend to find the longest window. While shrinking, we’ll decrement the character’s frequency 
going out of the window and remove it from the HashMap if its frequency becomes zero. At the end of 
each step, we’ll check if the current window length is the longest so far, and if so, remember its 
length.

Time Complexity#
The above algorithm’s time complexity will be O(N)
, where N is the number of characters in the input string. The outer for loop runs for all characters, 
and the inner while loop processes each character only once; therefore, the time complexity of the 
algorithm will be O(N+N) , which is asymptotically equivalent to O(N)

Space Complexity#
The algorithm’s space complexity is O(K), as we will be storing a maximum of K+1 characters in the 
HashMap.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
public:
  static int findLength(const string &str, int k) {
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> charFrequencyMap;
    // in the following loop we'll try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      charFrequencyMap[rightChar]++;
      // shrink the sliding window, until we are left with 'k' distinct characters in the frequency
      // map
      while ((int)charFrequencyMap.size() > k) {
        char leftChar = str[windowStart];
        charFrequencyMap[leftChar]--;
        if (charFrequencyMap[leftChar] == 0) {
          charFrequencyMap.erase(leftChar);
        }
        windowStart++; // shrink the window
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1); // remember the maximum length so far
    }

    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}
