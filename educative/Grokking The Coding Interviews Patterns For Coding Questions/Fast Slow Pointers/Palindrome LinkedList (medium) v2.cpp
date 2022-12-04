/*

Solution Review: Problem Challenge 1
We'll cover the following

Palindrome LinkedList (medium)
Solution
Code
Time complexity
Space complexity
Palindrome LinkedList (medium)
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the 
lgorithm is finished. The algorithm should have O(N)

O(N)
 time complexity where ‘N’ is the number of nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false
Solution
As we know, a palindrome LinkedList will have nodes values that read the same backward or forward. 
This means that if we divide the LinkedList into two halves, the node values of the first half in the forward 
direction should be similar to the node values of the second half in the backward direction. As we have been 
given a Singly LinkedList, we can’t move in the backward direction. To handle this, we will perform the following 
steps:

We can use the Fast & Slow pointers method similar to Middle of the LinkedList to find the middle node of the 
LinkedList.
Once we have the middle of the LinkedList, we will reverse the second half.
Then, we will compare the first half with the reversed second half to see if the LinkedList represents a palindrome.
Finally, we will reverse the second half of the LinkedList again to revert and bring the LinkedList back to its 
original form.

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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    // find middle of the LinkedList
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *headSecondHalf = reverse(slow);  // reverse the second half
    ListNode *copyHeadSecondHalf =
        headSecondHalf;  // store the head of reversed part to revert back later

    // compare the first and the second half
    while (head != nullptr && headSecondHalf != nullptr) {
      if (head->value != headSecondHalf->value) {
        break;  // not a palindrome
      }
      head = head->next;
      headSecondHalf = headSecondHalf->next;
    }

    reverse(copyHeadSecondHalf);                         // revert the reverse of the second half
    if (head == nullptr || headSecondHalf == nullptr) {  // if both halves match
      return true;
    }
    return false;
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
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}


