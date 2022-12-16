/*

https://www.educative.io/courses/grokking-the-coding-interview/xV2J7jvN1or

Solution
This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach. 
But there will be four differences:

We will keep track of the current path in a list which will be passed to every recursive call.

Whenever we traverse a node we will do two things:

Add the current node to the current path.
As we added a new node to the current path, we should find the sums of all sub-paths ending 
at the current node. If the sum of any sub-path is equal to ‘S’ we will increment our path count.
We will traverse all paths and will not stop processing after finding the first path.

Remove the current node from the current path before returning from the function. This is needed 
to Backtrack while we are going up the recursive call stack to process other paths.

Time complexity
The time complexity of the above algorithm is O(N^2) in the worst case, where ‘N’ is the total 
number of nodes in the tree. This is due to the fact that we traverse each node once, but for 
every node, we iterate the current path. The current path, in the worst case, can be O(N) (in the 
case of a skewed tree). But, if the tree is balanced, then the current path will be equal to the 
height of the tree, i.e., O(logN). So the best case of our algorithm will be O(NlogN)

Space complexity
The space complexity of the above algorithm will be O(N). This space will be used to store the 
recursion stack. The worst case will happen when the given tree is a linked list (i.e., every 
node has only one child). We also need O(N) space for storing the currentPath in the worst case.

Overall space complexity of our algorithm is O(N)

*/

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    vector<int> currentPath;
    return countPathsRecursive(root, S, currentPath);
  }

 private:
  static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
    if (currentNode == nullptr) {
      return 0;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);
    int pathCount = 0, pathSum = 0;
    // find the sums of all sub-paths in the current path list
    for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend();
         ++itr) {
      pathSum += *itr;
      // if the sum of any sub-path is equal to 'S' we increment our path count.
      if (pathSum == S) {
        pathCount++;
      }
    }

    // traverse the left sub-tree
    pathCount += countPathsRecursive(currentNode->left, S, currentPath);
    // traverse the right sub-tree
    pathCount += countPathsRecursive(currentNode->right, S, currentPath);

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();

    return pathCount;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
