/*

Introduction
This pattern describes an interesting approach to deal with problems involving arrays containing 
numbers in a given range. For example, take the following problem:

You are given an unsorted array containing n numbers taken from the range 1 to n. The array can 
have duplicates, which means that some numbers will be missing. Find all the missing numbers.

To efficiently solve this problem, we can use the fact that the input array contains numbers in 
the range of 1 to n. For example, to efficiently sort the array, we can try placing each number 
at its correct place, i.e., placing 1 at index '0', placing 2 at index ‘1’, and so on. Once we 
are done with the sorting, we can iterate the array to find all indices missing the correct numbers. 
These will be our required numbers.

Let’s jump on to our first problem to understand the Cyclic Sort pattern in detail.

https://www.educative.io/courses/grokking-the-coding-interview/B8qXVqVwDKY

Problem Statement
We are given an array containing n objects. Each object, when created, was assigned a unique number 
from the range 1 to n based on their creation sequence. This means that the object with sequence 
number 3 was created just before the object with sequence number 4.

Write a function to sort the objects in-place on their creation sequence number in O(n) and without 
using any extra space. For simplicity, let’s assume we are passed an integer array containing only 
the sequence numbers, though each number is actually an object.

Example 1:

Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]

Example 2:

Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]

Example 3:

Input: [1, 5, 6, 4, 3, 2]
Output: [1, 2, 3, 4, 5, 6]

*/



