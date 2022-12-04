/*

https://www.educative.io/courses/grokking-the-coding-interview/qAo438WozV7

Solution Review: Problem Challenge 2
We'll cover the following

Rearrange a LinkedList (medium)
Solution
Code
Time Complexity
Space Complexity
Rearrange a LinkedList (medium)
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

Example 1:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
Example 2:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
Output: 2 -> 10 -> 4 -> 8 -> 6 -> null
Solution
This problem shares similarities with Palindrome LinkedList. To rearrange the given LinkedList we will follow the following steps:

We can use the Fast & Slow pointers method similar to Middle of the LinkedList to find the middle node of the LinkedList.
Once we have the middle of the LinkedList, we will reverse the second half of the LinkedList.
Finally, we’ll iterate through the first half and the reversed second half to produce a LinkedList in the required order.
Code
Here is what our algorithm will look like:

Time Complexity
The above algorithm will have a time complexity of O(N)
O(N)
 where ‘N’ is the number of nodes in the LinkedList.

Space Complexity
The algorithm runs in constant space O(1)
O(1)
.

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

class RearrangeList {
 public:
  static void reorder(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return;
    }

    // find the middle of the LinkedList
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // slow is now pointing to the middle node
    ListNode *headSecondHalf = reverse(slow);  // reverse the second half
    ListNode *headFirstHalf = head;

    // rearrange to produce the LinkedList in the required order
    while (headFirstHalf != nullptr && headSecondHalf != nullptr) {
      ListNode *temp = headFirstHalf->next;
      headFirstHalf->next = headSecondHalf;
      headFirstHalf = temp;

      temp = headSecondHalf->next;
      headSecondHalf->next = headFirstHalf;
      headSecondHalf = temp;
    }

    // set the next of the last node to 'null'
    if (headFirstHalf != nullptr) {
      headFirstHalf->next = nullptr;
    }
  }

 private:
  static ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}

