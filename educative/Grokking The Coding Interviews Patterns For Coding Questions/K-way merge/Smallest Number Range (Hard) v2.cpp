/*

https://www.educative.io/courses/grokking-the-coding-interview/JPGWDNRx3w2

Solution
This problem follows the K-way merge pattern and we can follow a similar approach 
as discussed in Merge K Sorted Lists.

We can start by inserting the first number from all the arrays in a min-heap. We will 
keep track of the largest number that we have inserted in the heap (let’s call it 
currentMaxNumber).

In a loop, we’ll take the smallest (top) element from the min-heap andcurrentMaxNumber 
has the largest element that we inserted in the heap. If these two numbers give us 
a smaller range, we’ll update our range. Finally, if the array of the top element has 
more elements, we’ll insert the next element to the heap.

We can finish searching the minimum range as soon as an array is completed or, in other 
terms, the heap has less than ‘M’ elements.

Time complexity
Since, at most, we’ll be going through all the elements of all the arrays and will 
remove/add one element in the heap in each step, the time complexity of the above algorithm 
will be O(N*logM) where ‘N’ is the total number of elements in all the ‘M’ input arrays.

Space complexity
The space complexity will be O(M) because, at any time, our min-heap will be store one 
number from all the ‘M’ input arrays.

*/

using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class SmallestRange {
 public:
  struct valueCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

  static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
    // we will store the actual number, list index and element index in the heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare>
        minHeap;

    int rangeStart = 0, rangeEnd = numeric_limits<int>::max(),
        currentMaxNumber = numeric_limits<int>::min();
    // put the 1st element of each array in the min heap
    for (int i = 0; i < lists.size(); i++) {
      if (!lists[i].empty()) {
        minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
        currentMaxNumber = max(currentMaxNumber, lists[i][0]);
      }
    }

    // take the smallest (top) element form the min heap, if it gives us smaller range, update the
    // ranges if the array of the top element has more elements, insert the next element in the heap
    while (minHeap.size() == lists.size()) {
      auto node = minHeap.top();
      minHeap.pop();
      if (rangeEnd - rangeStart > currentMaxNumber - node.first) {
        rangeStart = node.first;
        rangeEnd = currentMaxNumber;
      }
      node.second.second++;
      if (lists[node.second.first].size() > node.second.second) {
        node.first = lists[node.second.first][node.second.second];
        minHeap.push(node);  // insert the next element in the heap
        currentMaxNumber = max(currentMaxNumber, node.first);
      }
    }

    return make_pair(rangeStart, rangeEnd);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second << "]";
}
