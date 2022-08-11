/*

Problem Statement#
Given a string, find the length of the longest substring, which has all distinct 
characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring with distinct characters is "abc".

Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring with distinct characters is "ab".

Example 3:

Input: String="abccde"
Output: 3
Explanation: Longest substrings with distinct characters are "abc" & "cde".

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0;
    unordered_map<char, int> hashTbl;
    for (int end = 0; end < str.size(); end++) {
      hashTbl[str[end]]++;
      for (auto item : hashTbl) {
        if (item.second > 1) {
          hashTbl[item.first]--;
          if (hashTbl[item.first] == 0) {
            hashTbl.erase(item.first);
          }
          start = end;
          break;
        }
      }
      
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};

