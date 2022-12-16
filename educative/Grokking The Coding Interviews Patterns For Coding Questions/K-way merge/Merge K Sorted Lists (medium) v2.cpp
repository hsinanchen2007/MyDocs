/*

https://www.educative.io/courses/grokking-the-coding-interview/Y5n0n3vAgYK

Solution
A brute force solution could be to add all elements of the given ‘K’ lists to one list 
and sort it. If there are a total of ‘N’ elements in all the input lists, then the brute 
force solution will have a time complexity of O(N*logN) as we will need to sort the merged 
list. Can we do better than this? How can we utilize the fact that the input lists are 
individually sorted?

If we have to find the smallest element of all the input lists, we have to compare only 
the smallest (i.e. the first) element of all the lists. Once we have the smallest element, 
we can put it in the merged list. Following a similar pattern, we can then find the next 
smallest element of all the lists to add it to the merged list.

The best data structure that comes to mind to find the smallest number among a set of ‘K’ 
numbers is a Heap. Let’s see how can we use a heap to find a better algorithm.

We can insert the first element of each array in a Min Heap.
After this, we can take out the smallest (top) element from the heap and add it to the 
merged list.
After removing the smallest element from the heap, we can insert the next element of the 
same list into the heap.
We can repeat steps 2 and 3 to populate the merged list in sorted order.
Let’s take the Example-1 mentioned above to go through each step of our algorithm:

Given lists: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]

After inserting the 1st element of each list, the heap will have the following elements:
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   

 Given lists:  
    2   
    6   
    8   
 L1  
 L3  
 L2  
    3   
    6   
    7   
    1   
    3   
    4   
    1   
    2   
    3   

Insert the first number from each array in the heap
We’ll take the top number from the heap, insert it into the merged list and add the next number 
in the heap.
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   

 Given lists:  
    2   
    6   
    8   
 L1  
 L3  
 L2  
    3   
    6   
    7   

 Merged List  
    2   
    3   
    3   
    1   
    3   
    4   
    1   

Again, we’ll take the top element of the heap, insert it into the merged list and add the next 
number to the heap.
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   

 Given lists:  
 L1  
 L3  
 L2  
    3   
    6   
    7   
 Merged List  
    1   
    3   
    4   
    1   
    2   
    3   
    6   
    3   
    2   
    6   
    8   
Repeating the above step, take the top element of the heap, insert it into the merged list and 
add the next number to the heap. As there are two 3s in the heap, we can pick anyone but we need 
to take the next element from the corresponding list to insert in the heap.
    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   
 Given lists:  
 L1  
 L3  
 L2  
 Merged List  
    1   
    3   
    4   
    2   
    6   
    8   
    3   
    6   
    7   
    1   
    2   
    3   
    3   
    6   
    6   
We’ll repeat the above step to populate our merged array.

Time complexity
Since we’ll be going through all the elements of all arrays and will be removing/adding one 
element to the heap in each step, the time complexity of the above algorithm will be O(N*logK),
 where ‘N’ is the total number of elements in all the ‘K’ input arrays.

Space complexity
The space complexity will be O(K) because, at any time, our min-heap will be storing one number 
from all the ‘K’ input arrays.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
 public:
  struct valueCompare {
    bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value; }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

    // put the root of each list in the min heap
    for (auto root : lists) {
      if (root != nullptr) {
        minHeap.push(root);
      }
    }

    // take the smallest (top) element form the min-heap and add it to the result;
    // if the top element has a next element add it to the heap
    ListNode *resultHead = nullptr, *resultTail = nullptr;
    while (!minHeap.empty()) {
      ListNode *node = minHeap.top();
      minHeap.pop();
      if (resultHead == nullptr) {
        resultHead = resultTail = node;
      } else {
        resultTail->next = node;
        resultTail = resultTail->next;
      }
      if (node->next != nullptr) {
        minHeap.push(node->next);
      }
    }

    return resultHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
