/*

https://www.educative.io/courses/grokking-the-coding-interview/YQWkA2l67GW

Solution
This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. 
The only difference will be that instead of keeping track of all nodes of a level, we will only track 
the running sum of the values of all nodes in each level. In the end, we will append the average of the 
current level to the result array.

Time complexity
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can 
have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will 
need O(N) space to store them in the queue.

Similar Problems
Problem 1: Find the largest value on each level of a binary tree.

Solution: We will follow a similar approach, but instead of having a running sum we will track the maximum 
value of each level.

maxValue = max(maxValue, currentNode.val)

*/

using namespace std;

#include <iostream>
#include <queue>

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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      double levelSum = 0;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node's value to the running sum
        levelSum += currentNode->val;
        // insert the children of current node to the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      // append the current level's average to the result array
      result.push_back(levelSum / levelSize);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
