/*

https://www.educative.io/courses/grokking-the-coding-interview/N7pvEn86YrN

Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node 
of the cycle.

 head  
    1   
    2   
    3   
    4   
    5   
    6   
 Cycle start  

 Examples:  
 Cycle start  
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
 head  
 head  
 Cycle start  

*/

using namespace std;

#include <iostream>
#include <unordered_set>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    // use unordered_set to trace the traversed nodes
    std::unordered_set<ListNode*> hashTbl;
    ListNode *tmp = head;
    hashTbl.insert(tmp);
    
    while (tmp != nullptr) {
      tmp = tmp->next;
      if (tmp != nullptr) {
        if (hashTbl.find(tmp) == hashTbl.end()) {
          // not found yet
          hashTbl.insert(tmp);
        } else {
          // found this ListNode has been traversed before
          return tmp;
        }
      }
    }

    // tmp may be nullptr or one valid ListNode
    return tmp;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}


