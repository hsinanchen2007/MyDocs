/*

Problem Statement#
Given a string, find the length of the longest substring in it with no more than 
K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

Example 4:

Input: String="cbbebi", K=10
Output: 6
Explanation: The longest substring with no more than '10' distinct characters is "cbbebi".

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0;
    unordered_map<int, int> hashTbl;
    for (int end = 0; end < str.size(); end++) {
      hashTbl[str[end]]++;
      while (hashTbl.size() > k) {
        maxLength = max(maxLength, end - start);
        hashTbl[str[start]]--;
        if (hashTbl[str[start]] == 0) {
          hashTbl.erase(str[start]);
        }
        start++;
      }
      maxLength = max(maxLength, end -start + 1);
    }
    return maxLength;
  }
};



