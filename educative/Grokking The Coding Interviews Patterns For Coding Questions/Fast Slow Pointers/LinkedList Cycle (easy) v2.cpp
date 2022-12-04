/*

https://www.educative.io/courses/grokking-the-coding-interview/N7rwVyAZl6D

Solution
Imagine two racers running in a circular racing track. If one racer is faster than the other, the faster racer 
is bound to catch up and cross the slower racer from behind. We can use this fact to devise an algorithm to 
determine if a LinkedList has a cycle in it or not.

Imagine we have a slow and a fast pointer to traverse the LinkedList. In each iteration, the slow pointer moves 
one step and the fast pointer moves two steps. This gives us two conclusions:

If the LinkedList doesn’t have a cycle in it, the fast pointer will reach the end of the LinkedList before the 
slow pointer to reveal that there is no cycle in the LinkedList.

The slow pointer will never be able to catch up to the fast pointer if there is no cycle in the LinkedList.
If the LinkedList has a cycle, the fast pointer enters the cycle first, followed by the slow pointer. After this, 
both pointers will keep moving in the cycle infinitely. If at any stage both of these pointers meet, we can conclude 
that the LinkedList has a cycle in it. Let’s analyze if it is possible for the two pointers to meet. When the fast 
pointer is approaching the slow pointer from behind we have two possibilities:

The fast pointer is one step behind the slow pointer.
The fast pointer is two steps behind the slow pointer.
All other distances between the fast and slow pointers will reduce to one of these two possibilities. Let’s analyze 
these scenarios, considering the fast pointer always moves first:

If the fast pointer is one step behind the slow pointer: The fast pointer moves two steps and the slow pointer moves 
one step, and they both meet.
If the fast pointer is two steps behind the slow pointer: The fast pointer moves two steps and the slow pointer moves 
one step. After the moves, the fast pointer will be one step behind the slow pointer, which reduces this scenario to 
the first scenario. This means that the two pointers will meet in the next iteration.
This concludes that the two pointers will definitely meet if the LinkedList has a cycle. A similar analysis can be done 
where the slow pointer moves first. Here is a visual representation of the above discussion:

    1   
    2   
    3   
    4   
    5   
    6   
 fast, slow  
    1   
    2   
    3   
    4   
    5   
    6   
    1   
    2   
    3   
    4   
    5   
    6   
 fast  
 slow  
 fast  
 slow  
    1   
    2   
    3   
    4   
    5   
    6   
 slow  
 fast  
    1   
    2   
    3   
    4   
    5   
    6   
 fast, slow  
Code
Here is what our algorithm will look like:

Time and Space Complexity: The above algorithm runs in O(N)
O(N)
 time complexity and O(1)
O(1)
 space complexity.

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
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        return true;  // found the cycle
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



