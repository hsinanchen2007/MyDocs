/*

https://www.educative.io/courses/grokking-the-coding-interview/3wEkKy6Pr9A

Similar Problems
Problem 1: Can we solve the above problem in O(1) space and without modifying the input array?

Solution: While doing the cyclic sort, we realized that the array will have a cycle due to the duplicate 
number and that the start of the cycle will always point to the duplicate number. This means that we can 
use the fast & the slow pointer method to find the duplicate number or the start of the cycle similar to 
Start of LinkedList Cycle.

*/

using namespace std;

#include <iostream>
#include <vector>

class DuplicateNumber {
 public:
  static int findDuplicate(const vector<int> &arr) {
    int slow = 0, fast = 0;
    do {
      slow = arr[slow];
      fast = arr[arr[fast]];
    } while (slow != fast);

    // find cycle length
    int current = arr[slow];
    int cycleLength = 0;
    do {
      current = arr[current];
      cycleLength++;
    } while (current != arr[slow]);

    return findStart(arr, cycleLength);
  }

 private:
  static int findStart(const vector<int> &arr, int cycleLength) {
    int pointer1 = arr[0], pointer2 = arr[0];
    // move pointer2 ahead 'cycleLength' steps
    while (cycleLength > 0) {
      pointer2 = arr[pointer2];
      cycleLength--;
    }

    // increment both pointers until they meet at the start of the cycle
    while (pointer1 != pointer2) {
      pointer1 = arr[pointer1];
      pointer2 = arr[pointer2];
    }

    return pointer1;
  }
};

int main(int argc, char *argv[]) {
  cout << DuplicateNumber::findDuplicate(vector<int>{1, 4, 4, 3, 2}) << endl;
  cout << DuplicateNumber::findDuplicate(vector<int>{2, 1, 3, 3, 5, 4}) << endl;
  cout << DuplicateNumber::findDuplicate(vector<int>{2, 4, 1, 4, 4}) << endl;
}

