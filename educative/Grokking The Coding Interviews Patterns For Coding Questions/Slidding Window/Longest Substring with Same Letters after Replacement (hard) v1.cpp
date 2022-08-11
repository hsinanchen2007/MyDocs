/*

https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR

Problem Statement#
Given a string with lowercase letters only, if you are allowed to replace no more 
than k letters with any letter, find the length of the longest substring having 
the same letters after replacement.

Example 1:

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".

Example 2:

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have the longest repeating substring "bbbb".

Example 3:

Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0;
    int maxRepeat = 0;
    unordered_map<char, int> hashTbl;
    for (int end = 0; end < str.size(); end++) {
      hashTbl[str[end]]++;
      maxRepeat = max(maxRepeat, hashTbl[str[end]]);
      if (end - start + 1 - maxRepeat > k) {
        hashTbl[str[start]]--;
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};









