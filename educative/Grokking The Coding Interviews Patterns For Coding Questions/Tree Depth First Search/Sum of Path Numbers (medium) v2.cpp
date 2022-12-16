/*

https://www.educative.io/courses/grokking-the-coding-interview/YQ5o5vEXP69

Solution
This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach. 
The additional thing we need to do is to keep track of the number representing the current path.

How do we calculate the path number for a node? Taking the first example mentioned above, 
say we are at node ‘7’. As we know, the path number for this node is ‘17’, which was calculated 
by: 1 * 10 + 7 => 17. We will follow the same approach to calculate the path number of each node.

Time complexity
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the 
tree. This is due to the fact that we traverse each node once.

Space complexity
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used 
to store the recursion stack. The worst case will happen when the given tree is a linked list 
(i.e., every node has only one child).

*/

using namespace std;

#include <iostream>

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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    return findRootToLeafPathNumbers(root, 0);
  }

 private:
  static int findRootToLeafPathNumbers(TreeNode *currentNode, int pathSum) {
    if (currentNode == nullptr) {
      return 0;
    }

    // calculate the path number of the current node
    pathSum = 10 * pathSum + currentNode->val;

    // if the current node is a leaf, return the current path sum.
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
      return pathSum;
    }
    // traverse the left and the right sub-tree
    return findRootToLeafPathNumbers(currentNode->left, pathSum) + 
           findRootToLeafPathNumbers(currentNode->right, pathSum);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}

