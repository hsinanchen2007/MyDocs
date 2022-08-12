/*

https://www.educative.io/courses/grokking-the-coding-interview/YQ8N2OZq0VM

String Anagrams (hard)#
Given a string and a pattern, find all anagrams of the pattern in the given 
string.

Every anagram is a permutation of a string. As we know, when we are not allowed 
to repeat characters while finding permutations of a string, we get N! 
permutations (or anagrams) of a string having N characters. For example, here 
are the six anagrams of the string “abc”:

abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".

Example 2:

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int start = 0;
    int patternSize = pattern.size();
    unordered_map<char, int> hashTbl;
    for (auto item : pattern) {
      hashTbl[item]++;
    }
    unordered_map<char, int> tmpTbl;
    for (int end = 0; end < pattern.size(); end++) {
      tmpTbl[str[end]]++;
      if (end - start + 1 == patternSize) {
        bool isMatch = true;
        for (auto check : tmpTbl) {
          if (tmpTbl[check.first] != hashTbl[check.first]) {
            isMatch = false;
            break;
          } 
        }
        if (isMatch) {
          resultIndices.push_back(start);
        }
        tmpTbl[str[start]]--;
        if (tmpTbl[str[start]] == 0) {
          tmpTbl.erase(str[start]);
        }
        start++;
      } 
    }

    return resultIndices;
  }
};

int main(int argc, char *argv[]) {
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}






