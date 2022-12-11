/*

https://www.educative.io/courses/grokking-the-coding-interview/xVQyDZBMpKE

Solution 
This problem follows the Subsets pattern and is quite similar to Evaluate Expression. 
Following a similar approach, we can iterate from 1 to ‘n’ and consider each number as 
the root of a tree. All smaller numbers will make up the left sub-tree and bigger numbers 
will make up the right sub-tree. We will make recursive calls for the left and right 
sub-trees

Time complexity
The time complexity of this algorithm will be exponential and will be similar to Balanced 
Parentheses. Estimated time complexity will be O(n*2^n) but the actual time complexity 
( O(4^n/\sqrt{n}) is bounded by the Catalan number and is beyond the scope of a coding 
interview. See more details here.

Space complexity
The space complexity of this algorithm will be exponential too, estimated at O(2^n), 
but the actual will be ( O(4^n/\sqrt{n})

Memoized version
Since our algorithm has overlapping subproblems, can we use memoization to improve it? 
We could, but every time we return the result of a subproblem from the cache, we have to 
clone the result list because these trees will be used as the left or right child of a 
tree. This cloning is equivalent to reconstructing the trees, therefore, the overall time 
complexity of the memoized algorithm will also be the same.

*/

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class UniqueTrees {
 public:
  static vector<TreeNode *> findUniqueTrees(int n) {
    if (n <= 0) {
      return vector<TreeNode *>();
    }
    return findUniqueTreesRecursive(1, n);
  }

  static vector<TreeNode *> findUniqueTreesRecursive(int start, int end) {
    vector<TreeNode *> result;
    // base condition, return 'null' for an empty sub-tree
    // consider n=1, in this case we will have start=end=1, this means we should have only one tree
    // we will have two recursive calls, findUniqueTreesRecursive(1, 0) & (2, 1)
    // both of these should return 'null' for the left and the right child
    if (start > end) {
      result.push_back(nullptr);
      return result;
    }

    for (int i = start; i <= end; i++) {
      // making 'i' root of the tree
      vector<TreeNode *> leftSubtrees = findUniqueTreesRecursive(start, i - 1);
      vector<TreeNode *> rightSubtrees = findUniqueTreesRecursive(i + 1, end);
      for (auto leftTree : leftSubtrees) {
        for (auto rightTree : rightSubtrees) {
          TreeNode *root = new TreeNode(i);
          root->left = leftTree;
          root->right = rightTree;
          result.push_back(root);
        }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<TreeNode *> result = UniqueTrees::findUniqueTrees(2);
  cout << "Total trees: " << result.size() << endl;

  result = UniqueTrees::findUniqueTrees(3);
  cout << "Total trees: " << result.size() << endl;
}


