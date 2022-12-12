/*

Introduction
This pattern is based on the Breadth First Search (BFS) technique to traverse a tree.

Any problem involving the traversal of a tree in a level-by-level order can be efficiently 
solved using this approach. We will use a Queue to keep track of all the nodes of a level 
before we jump onto the next level. This also means that the space complexity of the algorithm 
will be O(W), where ‘W’ is the maximum number of nodes on any level.

Let’s jump onto our first problem to understand this pattern.

https://www.educative.io/courses/grokking-the-coding-interview/xV7E64m4lnz

Given a binary tree, populate an array to represent its level-by-level traversal. 
You should populate the values of all nodes of each level from left to right in separate 
sub-arrays.

Example 1:

    1   
    2   
    3   
    4   
    5   
    6   
    7   
 Level Order Traversal:  
 [[1],[2,3],[4,5,6,7]]  

Example 2:

    12   
    7   
    1   
    9   
    10   
    5   
 Level Order Traversal:  
 [[12],[7,1],[9,10,5]]  

*/