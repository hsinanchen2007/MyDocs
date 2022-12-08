/*

Introduction

In many problems, where we are given a set of elements such that we can divide them into two parts. We are 
interested in knowing the smallest element in one part and the biggest element in the other part. The Two Heaps 
pattern is an efficient approach to solve such problems.

As the name suggests, this pattern uses two Heaps; A Min Heap to find the smallest element and a Max Heap to 
find the biggest element.

Let’s jump onto our first problem to see this pattern in action.

https://www.educative.io/courses/grokking-the-coding-interview/3Yj2BmpyEy4

Problem Statement
Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.

Example 1:

1. insertNum(3)
2. insertNum(1)
3. findMedian() -> output: 2
4. insertNum(5)
5. findMedian() -> output: 3
6. insertNum(4)
7. findMedian() -> output: 3.5

*/