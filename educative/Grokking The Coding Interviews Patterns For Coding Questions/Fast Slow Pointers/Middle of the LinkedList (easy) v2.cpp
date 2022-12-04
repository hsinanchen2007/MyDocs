/*

https://www.educative.io/courses/grokking-the-coding-interview/3j5GD3EQMGM

Solution
One brute force strategy could be to first count the number of nodes in the LinkedList and then 
find the middle node in the second iteration. Can we do this in one iteration?

We can use the Fast & Slow pointers method such that the fast pointer is always twice the nodes 
ahead of the slow pointer. This way, when the fast pointer reaches the end of the LinkedList, 
the slow pointer will be pointing at the middle node.

Code
Here is what our algorithm will look like:

Time complexity
The above algorithm will have a time complexity of O(N)
O(N)
 where ‘N’ is the number of nodes in the LinkedList.

Space complexity
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

class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;
}


