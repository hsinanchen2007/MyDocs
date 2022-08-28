/*

https://www.educative.io/courses/grokking-the-coding-interview/N8vB7OVYo2D

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

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    int patternSize = pattern.size();
    unordered_map<char, int> patternTbl;
    for (auto item : pattern) {
      patternTbl[item]++;
    }
    int start = 0;
    unordered_map<char, int> tmpTbl;
    for (int end = 0; end < str.size(); end++) {
      tmpTbl[str[end]]++;
      if (end - start + 1 == patternSize) {
        bool isPermutation = true;
        for (auto test : tmpTbl) {
          if (tmpTbl[test.first] != patternTbl[test.first]) {
            isPermutation = false;
            break;
          }
        }
        if (!isPermutation) {
          // update start
          tmpTbl[str[start]]--;
          if (tmpTbl[str[start]] == 0) {
            tmpTbl.erase(str[start]);
          }
          start++;
        } else {
          // # of characters are all matched in two hash tables
          return true;
        }
      }
    }
    return false;
  }
};

