/*

https://www.educative.io/courses/grokking-the-coding-interview/B1PzmqOKDLQ

Problem Challenge 1
We'll cover the following

Palindrome LinkedList (medium)
Try it yourself
Palindrome LinkedList (medium)
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the 
algorithm is finished. The algorithm should have O(N)

O(N)
 time complexity where ‘N’ is the number of nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false
Try it yourself
Try solving this question here:

*/

// Memory Limit Exceeded!

using namespace std;

#include <iostream>
#include <deque>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    std::deque<ListNode*> dq;
    while (head != nullptr) {
      dq.push_back(head);
    }
    while (dq.size() > 2) {
      if (dq.front() != dq.back()) {
        return false;
      } else {
        dq.pop_front();
        dq.pop_back();
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}


