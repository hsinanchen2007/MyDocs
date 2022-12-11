/*

https://www.educative.io/courses/grokking-the-coding-interview/NE1V3EDAnWN

Memoized version
Our algorithm has overlapping subproblems as our recursive call will be evaluating 
the same sub-expression multiple times. To resolve this, we can use memoization and 
store the intermediate results in a HashMap. In each function call, we can check our 
map to see if we have already evaluated this sub-expression before. Here is the 
memoized version of our algorithm, please see highlighted changes:

The time complexity of the memoized algorithm will be O(n^2), since we are iterating 
from ‘1’ to ‘n’ and ensuring that each sub-problem is evaluated only once. The space 
complexity will be O(n) for the memoization map.

*/

using namespace std;

#include <iostream>
#include <unordered_map>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
 public:
  unordered_map<int, int> map = unordered_map<int, int>();

  virtual int countTrees(int n) {
    if (map.find(n) != map.end()) {
      return map[n];
    }

    if (n <= 1) {
      return 1;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
      // making 'i' root of the tree
      int countOfLeftSubtrees = countTrees(i - 1);
      int countOfRightSubtrees = countTrees(n - i);
      count += (countOfLeftSubtrees * countOfRightSubtrees);
    }
    map[n] = count;
    return count;
  }
};

int main(int argc, char *argv[]) {
  CountUniqueTrees ct;
  int count = ct.countTrees(3);
  cout << "Total trees: " << count;
}
