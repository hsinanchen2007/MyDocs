/*

Introduction
This pattern is based on the Depth First Search (DFS) technique to traverse a tree.

We will be using recursion (or we can also use a stack for the iterative approach) to keep track 
of all the previous (parent) nodes while traversing. This also means that the space complexity of 
the algorithm will be O(H), where ‘H’ is the maximum height of the tree.

Let’s jump onto our first problem to understand this pattern.

https://www.educative.io/courses/grokking-the-coding-interview/RMlGwgpoKKY

Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the 
sum of all the node values of that path equals ‘S’.

1
2
3
4
5
6
7

Example 1:
S: 10
Output: true

Explanation: The path with sum '10' is highlighted

Example 2:
12
7
1
9
10
5
S: 23
Output: true

Explanation: The path with sum '23' is highlightedS: 16Output: falseExplanation: 
There is no root-to-leaf path with sum '16'.

*/
