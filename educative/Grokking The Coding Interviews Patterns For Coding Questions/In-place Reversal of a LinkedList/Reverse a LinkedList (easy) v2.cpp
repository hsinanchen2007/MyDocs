/*

https://www.educative.io/courses/grokking-the-coding-interview/3wENz1N4WW9

Solution 
To reverse a LinkedList, we need to reverse one node at a time. We will start with a variable current 
which will initially point to the head of the LinkedList and a variable previous which will point to 
the previous node that we have processed; initially previous will point to null.

In a stepwise manner, we will reverse the current node by pointing it to the previous before moving on 
to the next node. Also, we will update the previous to always point to the previous node that we have 
processed. Here is the visual representation of our algorithm:

2
4
6
8
10
null
current
previous = null
current = head, previous = null
1 of 7

Time complexity
The time complexity of our algorithm will be O(N) where ‘N’ is the total number of nodes in the LinkedList.

Space complexity
We only used constant space, therefore, the space complexity of our algorithm is O(1)

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

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode *current = head;      // current node that we will be processing
    ListNode *previous = nullptr;  // previous node that we have processed
    ListNode *next = nullptr;      // will be used to temporarily store the next node

    while (current != nullptr) {
      next = current->next;      // temporarily store the next node
      current->next = previous;  // reverse the current node
      previous = current;  // before we move to the next node, point previous to the current node
      current = next;      // move on the next node
    }
    // after the loop current will be pointing to 'null' and 'previous' will be the new head
    return previous;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}


