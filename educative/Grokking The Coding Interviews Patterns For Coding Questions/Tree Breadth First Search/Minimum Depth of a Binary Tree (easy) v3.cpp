/*

https://www.educative.io/courses/grokking-the-coding-interview/3jwVx84OMkO

Similar Problems
Problem 1: Given a binary tree, find its maximum depth (or height).

Solution: We will follow a similar approach. Instead of returning as soon as we find a leaf node, 
we will keep traversing for all the levels, incrementing maximumDepth each time we complete a level. 
Here is what the code will look like:

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

class MaximumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    int maximumTreeDepth = 0;
    while (!queue.empty()) {
      maximumTreeDepth++;
      int levelSize = queue.size();
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
    }

    return maximumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Maximum Depth: " << MaximumBinaryTreeDepth::findDepth(root) << endl;
}
