/*

https://www.educative.io/courses/grokking-the-coding-interview/NE1V3EDAnWN

Solution
This problem is similar to Structurally Unique Binary Search Trees. Following a similar 
approach, we can iterate from 1 to ‘n’ and consider each number as the root of a tree and 
make two recursive calls to count the number of left and right sub-trees.

Time complexity
The time complexity of this algorithm will be exponential and will be similar to Balanced 
Parentheses. Estimated time complexity will be O(n*2^n) but the actual time complexity 
( O(4^n/\sqrt{n}) is bounded by the Catalan number and is beyond the scope of a coding 
interview. See more details here.

Space complexity
The space complexity of this algorithm will be exponential too, estimated O(2^n) but the 
actual will be ( O(4^n/\sqrt{n})

*/

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
 public:
  int countTrees(int n) {
    if (n <= 1) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
      // making 'i' root of the tree
      int countOfLeftSubtrees = countTrees(i - 1);
      int countOfRightSubtrees = countTrees(n - i);
      count += (countOfLeftSubtrees * countOfRightSubtrees);
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  CountUniqueTrees ct;
  int count = ct.countTrees(3);
  cout << "Total trees: " << count;
}
