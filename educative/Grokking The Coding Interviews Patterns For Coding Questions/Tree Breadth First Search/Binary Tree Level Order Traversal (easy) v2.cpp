/*

https://www.educative.io/courses/grokking-the-coding-interview/xV7E64m4lnz

Solution
Since we need to traverse all nodes of each level before moving onto the next level, 
we can use the Breadth First Search (BFS) technique to solve this problem.

We can use a Queue to efficiently traverse in BFS fashion. Here are the steps of our 
algorithm:

Start by pushing the root node to the queue.
Keep iterating until the queue is empty.
In each iteration, first count the elements in the queue (let’s call it levelSize). 
We will have these many nodes in the current level.

Next, remove levelSize nodes from the queue and push their value in an array to 
represent the current level.

After removing each node from the queue, insert both of its children into the queue.

If the queue is not empty, repeat from step 3 for the next level.
Let’s take the example-2 mentioned above to visually represent our algorithm:

    12   
    7   
    1   
    9   
    10   
    5   
 Queue:  
    12   
 Level Size: 1  

Start by pushing the root to the queue.
1 of 7

Time complexity
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes 
in the tree. This is due to the fact that we traverse each node once.

Space complexity
The space complexity of the above algorithm will be O(N) as we need to return a list containing 
the level order traversal. We will also need O(N) space for the queue. Since we can have a maximum 
of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N)
space to store them in the queue.

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node to the current level
        currentLevel.push_back(currentNode->val);
        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      result.push_back(currentLevel);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
