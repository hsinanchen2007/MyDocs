/*

https://www.educative.io/courses/grokking-the-coding-interview/N0o9QnPLKNv

Permutation in a String (hard)#
Given a string and a pattern, find out if the string contains any permutation 
of the pattern.

Permutation is defined as the re-arranging of the characters of the string. 
For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n! permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.

Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.

Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.

Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.
Solution#
This problem follows the Sliding Window pattern, and we can use a similar sliding 
window strategy as discussed in Longest Substring with K Distinct Characters. We can use 
a HashMap to remember the frequencies of all characters in the given pattern. Our goal 
will be to match all the characters from this HashMap with a sliding window in the 
given string. Here are the steps of our algorithm:

Create a HashMap to calculate the frequencies of all characters in the pattern.
Iterate through the string, adding one character at a time in the sliding window.
If the character being added matches a character in the HashMap, decrement its frequency 
in the map. If the character frequency becomes zero, we got a complete match.
If at any time, the number of characters matched is equal to the number of distinct 
characters in the pattern (i.e., total characters in the HashMap), we have gotten our 
required permutation. If the window size is greater than the length of the pattern, 
shrink the window to make it equal to the pattern’s size. At the same time, if the character 
going out was part of the pattern, put it back in the frequency HashMap.

Time Complexity#
The above algorithm’s time complexity will be O(N + M), where ‘N’ and ‘M’ are the number 
of characters in the input string and the pattern, respectively.

Space Complexity#
The algorithm’s space complexity is O(M) since, in the worst case, the whole pattern 
can have distinct characters that will go into the HashMap.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    int windowStart = 0, matched = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    // our goal is to match all the characters from the 'charFrequencyMap' with the current window
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
        // decrement the frequency of the matched character
        charFrequencyMap[rightChar]--;
        if (charFrequencyMap[rightChar] == 0) {  // character is completely matched
          matched++;
        }
      }

      if (matched == (int)charFrequencyMap.size()) {
        return true;
      }

      if (windowEnd >= pattern.length() - 1) {  // shrink the window
        char leftChar = str[windowStart++];
        if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
          if (charFrequencyMap[leftChar] == 0) {
            matched--;  // before putting the character back, decrement the matched count
          }
          // put the character back for matching
          charFrequencyMap[leftChar]++;
        }
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}

