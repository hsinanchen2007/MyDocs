/*

https://www.educative.io/courses/grokking-the-coding-interview/NE67J9YMj3m

Solution
This problem involves finding a cycle in the array and, as we know, the Fast & Slow pointer method is an efficient 
way to do that. We can start from each index of the array to find the cycle. If a number does not have a cycle we 
will move forward to the next element. There are a couple of additional things we need to take care of:

As mentioned in the problem, the cycle should have more than one element. This means that when we move a pointer 
forward, if the pointer points to the same element after the move, we have a one-element cycle. Therefore, we can 
finish our cycle search for the current element.

The other requirement mentioned in the problem is that the cycle should not contain both forward and backward movements. 
We will handle this by remembering the direction of each element while searching for the cycle. If the number is 
positive, the direction will be forward and if the number is negative, the direction will be backward. So whenever 
we move a pointer forward, if there is a change in the direction, we will finish our cycle search right there for 
the current element.

Code
Here is what our algorithm will look like:

Time Complexity
The above algorithm will have a time complexity of O(N^2)

where ‘N’ is the number of elements in the array. This complexity is due to the fact that we are iterating all elements 
of the array and trying to find a cycle for each element.

Space Complexity
The algorithm runs in constant space O(1)

An Alternate Approach
In our algorithm, we don’t keep a record of all the numbers that have been evaluated for cycles. We know that all such 
numbers will not produce a cycle for any other instance as well. If we can remember all the numbers that have been visited, 
our algorithm will improve to O(N) as, then, each number will be evaluated for cycles only once. We can keep track of 
this by creating a separate array, however, in this case, the space complexity of our algorithm will increase to O(N).

*/

using namespace std;

#include <iostream>
#include <vector>

class CircularArrayLoop {
 public:
  static bool loopExists(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      bool isForward = arr[i] >= 0;  // if we are moving forward or not
      int slow = i, fast = i;

      // if slow or fast becomes '-1' this means we can't find cycle for this number
      do {
        slow = findNextIndex(arr, isForward, slow);  // move one step for slow pointer
        fast = findNextIndex(arr, isForward, fast);  // move one step for fast pointer
        if (fast != -1) {
          fast = findNextIndex(arr, isForward, fast);  // move another step for fast pointer
        }
      } while (slow != -1 && fast != -1 && slow != fast);

      if (slow != -1 && slow == fast) {
        return true;
      }
    }

    return false;
  }

 private:
  static int findNextIndex(const vector<int> &arr, bool isForward, int currentIndex) {
    bool direction = arr[currentIndex] >= 0;
    if (isForward != direction) {
      return -1;  // change in direction, return -1
    }

    int nextIndex = (currentIndex + arr[currentIndex]) % (int) arr.size();
    if (nextIndex < 0)
      nextIndex += arr.size(); // wrap around for negative numbers

    // one element cycle, return -1
    if (nextIndex == currentIndex) {
      nextIndex = -1;
    }

    return nextIndex;
  }
};

int main(int argc, char *argv[]) {
  cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}

