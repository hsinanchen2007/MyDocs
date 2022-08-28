/*

https://www.educative.io/courses/grokking-the-coding-interview/Bn2KLlOR0lQ

Problem Statement#
You are visiting a farm to collect fruits. The farm has a single row of 
fruit trees. You will be given two baskets, and your goal is to pick as 
many fruits as possible to be placed in the given baskets.

You will be given an array of characters where each character represents 
a fruit tree. The farm has following restrictions:

Each basket can have only one type of fruit. There is no limit to how many 
fruit a basket can hold. You can start with any tree, but you can’t skip a 
tree once you have started. You will pick exactly one fruit from every tree 
until you cannot, i.e., you will stop when you have to pick from a third 
fruit type. Write a function to return the maximum number of fruits in both 
baskets.

*/

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0;
    unordered_map<int, int> hashTbl;
    for (int end = 0; end < arr.size(); end++) {
      hashTbl[arr[end]]++;
      while (hashTbl.size() > 2) {
        hashTbl[arr[start]]--;
        if (hashTbl[arr[start]] == 0) {
          hashTbl.erase(arr[start]);
        }
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};

