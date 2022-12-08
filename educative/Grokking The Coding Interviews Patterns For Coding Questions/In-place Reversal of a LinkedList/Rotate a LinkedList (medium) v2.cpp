/*

https://www.educative.io/courses/grokking-the-coding-interview/gkAM9kxgY8Z

Solution
Another way of defining the rotation is to take the sub-list of ‘k’ ending nodes of the LinkedList 
and connect them to the beginning. Other than that we have to do three more things:

Connect the last node of the LinkedList to the head, because the list will have a different tail after 
the rotation.

The new head of the LinkedList will be the node at the beginning of the sublist.
The node right before the start of sub-list will be the new tail of the rotated LinkedList.

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

class RotateList {
 public:
  static ListNode *rotate(ListNode *head, int rotations) {
    if (head == nullptr || head->next == nullptr || rotations <= 0) {
      return head;
    }

    // find the length and the last node of the list
    ListNode *lastNode = head;
    int listLength = 1;
    while (lastNode->next != nullptr) {
      lastNode = lastNode->next;
      listLength++;
    }

    lastNode->next = head;    // connect the last node with the head to make it a circular list
    rotations %= listLength;  // no need to do rotations more than the length of the list
    int skipLength = listLength - rotations;
    ListNode *lastNodeOfRotatedList = head;
    for (int i = 0; i < skipLength - 1; i++) {
      lastNodeOfRotatedList = lastNodeOfRotatedList->next;
    }

    // 'lastNodeOfRotatedList.next' is pointing to the sub-list of 'k' ending nodes
    head = lastNodeOfRotatedList->next;
    lastNodeOfRotatedList->next = nullptr;
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *result = RotateList::rotate(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}

