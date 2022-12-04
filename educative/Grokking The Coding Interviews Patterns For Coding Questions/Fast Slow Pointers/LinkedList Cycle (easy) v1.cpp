/*

Introduction

The Fast & Slow pointer approach, also known as the Hare & Tortoise algorithm, is a pointer algorithm 
that uses two pointers which move through the array (or sequence/LinkedList) at different speeds. 
This approach is quite useful when dealing with cyclic LinkedLists or arrays.

By moving at different speeds (say, in a cyclic LinkedList), the algorithm proves that the two pointers 
are bound to meet. The fast pointer should catch the slow pointer once both the pointers are in a cyclic 
loop.

One of the famous problems solved using this technique was Finding a cycle in a LinkedList. Let’s jump 
onto this problem to understand the Fast & Slow pattern.


https://www.educative.io/courses/grokking-the-coding-interview/N7rwVyAZl6D

LinkedList Cycle (easy)
We'll cover the following

Problem Statement
Try it yourself
Solution
Code
Time Complexity
Space Complexity
Similar Problems
Problem Statement
Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.

 Example:  
 head  
 Following LinkedList has a cycle:  
 Following LinkedList doesn't have a cycle:  
    2   
    4   
    6   
    8   
    10   
    null   
    1   
    2   
    3   
    4   
    5   
    6   
 head  
Try it yourself
Try solving this question here:

*/

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycle {
 public:
  static bool hasCycle(ListNode *head) {
    // define two pointers starting from same head location
    ListNode *fast = head;
    ListNode *slow = head;

    // as fast pointer will be the one reach nullptr if no cycle, so just check fast pointer here
    // check fast pointer current and next locations to see if it is nullptr or not
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        // detect cycle, return
        return true;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
}

