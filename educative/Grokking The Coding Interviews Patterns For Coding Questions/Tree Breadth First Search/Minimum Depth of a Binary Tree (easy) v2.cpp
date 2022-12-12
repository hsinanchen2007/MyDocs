/*

https://www.educative.io/courses/grokking-the-coding-interview/3jwVx84OMkO

Solution
This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. 
The only difference will be, instead of keeping track of all the nodes in a level, we will only track the 
depth of the tree. As soon as we find our first leaf node, that level will represent the minimum depth 
of the tree.

Time complexity
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can 
have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will 
need O(N) space to store them in the queue.

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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    int minimumTreeDepth = 0;
    while (!queue.empty()) {
      minimumTreeDepth++;
      int levelSize = queue.size();
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();

        // check if this is a leaf node
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
          return minimumTreeDepth;
        }

        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
    }
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
