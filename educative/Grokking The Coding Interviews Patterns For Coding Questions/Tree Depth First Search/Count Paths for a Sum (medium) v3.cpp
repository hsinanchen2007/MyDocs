/*

https://www.educative.io/courses/grokking-the-coding-interview/xV2J7jvN1or

A more efficient solution
Can we further improve the solution?

One thing we are repeating for each node is traversing the current path and seeing 
if any sub-path that ends at the current node gives us the required sum.

Let’s see if we can improve this part.

We can use the Prefix Sum technique to efficiently manage the path sums.

Prefix Sum
Let’s first understand what Prefix Sum is. For a given array, its Prefix Sum is another 
array where each element is the commutative sum of the corresponding element in the given 
array and all its previous elements.

Prefix Sum
Prefix Sum
Here is an example:

Prefix Sum Example
Prefix Sum Example
Now, let’s say we want to find all subarrays of a given array with a target sum.

Let’s say our target sum is 7, and we want to find all the subarrays of the array mentioned 
above.

We can clearly see that there are two such subarrays: 1) [1, 6], and 2) [2, 5].

How can we utilize the Prefix Sum array to find these two subarrays efficiently?

There are two ways Prefix Sum can help us:

a) Since each element of the prefix sum array contains the cumulative sum of current and previous 
elements, therefore, whenever we see our target sum, we have found our targeted subarray. For example, 
since the second element of the prefix sum array is 7; therefore, our target subarray will be from 
the start of the array till the second element, i.e., [1, 6]

(b) Secondly, the prefix sum array can also help us find our target subarray that is not starting 
from the first index.

If we subtract the target sum from any element of the prefix sum array, the result will also give us 
our target subarray (if that result is present in the prefix sum array).

For example, take the 4th element of the prefix sum array and subtract the target sum from it: 14 – 7 => 7

Is this result (7) present in the prefix sum array? Yes, it is the second element. This means the sum 
from the 3rd element to the current element (i.e., the 4th) is also 7.

Hence, our target subarray will be from the 3rd element to the current element, i.e., [2, 5].

Now, let’s see how we can use prefix sum for binary trees. Take the following example:

Using Prefix Sum for Trees
Using Prefix Sum for Trees

We can consider each path as an array and calculate its prefix sums to find any required sub-paths. 
In the above tree, the highlighted sub-paths are exactly the same as our previous array example.

Time complexity
As we are not traversing the current path for each node, the time complexity of the above algorithm 
will be O(N) in the worst case, where ‘N’ is the total number of nodes in the tree.

Space complexity
The space complexity of the above algorithm will be O(N). This space will be used to store the recursion 
stack, as well as for the prefix sum.

*/

using namespace std;

#include <iostream>
#include <unordered_map>

class TreeNode
{
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x)
  {
    val = x;
    left = right = nullptr;
  }
};

class CountAllPathSum
{
public:
  static int countPaths(TreeNode *currentNode, int targetSum)
  {
    // A map that stores the number of times a prefix sum has occurred so far.
    unordered_map<int, int> map;

    return countPathsPrefixSum(currentNode, targetSum, map, 0);
  }

private:
  static int countPathsPrefixSum(TreeNode *currentNode, int targetSum, unordered_map<int, int> map, int currentPathSum)
  {
    if (currentNode == nullptr)
      return 0;

    // The number of paths that have the required sum.
    int pathCount = 0;

    // 'currentPathSum' is the prefix sum, i.e., sum of all node values from root to current node.
    currentPathSum += currentNode->val;

    // This is the base case. If the current sum is equal to the target sum, we have found a path from root to
    // the current node having the required sum. Hence, we increment the path count by 1.
    if (targetSum == currentPathSum)
      pathCount++;

    //'currentPathSum' is the path sum from root to the current node. If within this path, there is a
    // valid solution, then there must be an 'oldPathSum' such that:
    // => currentPathSum - oldPathSum = targetSum
    // => currentPathSum - targetSum = oldPathSum
    // Hence, we can search such an 'oldPathSum' in the map from the key 'currentPathSum - targetSum'.
    if (map.find(currentPathSum - targetSum) != map.end())
      pathCount += map[currentPathSum - targetSum];

    // This is the key step in the algorithm. We are storing the number of times the prefix sum
    // `currentPathSum` has occurred so far.
    map[currentPathSum]++;

    // Counting the number of paths from the left and right subtrees.
    pathCount += countPathsPrefixSum(currentNode->left, targetSum, map, currentPathSum);
    pathCount += countPathsPrefixSum(currentNode->right, targetSum, map, currentPathSum);

    // Removing the current path sum from the map for backtracking.
    // 'currentPathSum' is the prefix sum up to the current node. When we go back (i.e., backtrack), then
    // the current node is no more a part of the path, hence, we should remove its prefix sum from the map.
    map[currentPathSum]--;

    return pathCount;
  }
};

int main(int argc, char *argv[])
{
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}

