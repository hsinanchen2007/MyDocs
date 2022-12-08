/*

https://www.educative.io/courses/grokking-the-coding-interview/3Y9jm7XRrXO

Solution 
This problem follows the Two Heaps pattern and share similarities with Find the Median of a Number 
Stream. We can follow a similar approach of maintaining a max-heap and a min-heap for the list of 
numbers to find their median.

The only difference is that we need to keep track of a sliding window of ‘k’ numbers. This means, 
in each iteration, when we insert a new number in the heaps, we need to remove one number from the 
heaps which is going out of the sliding window. After the removal, we need to rebalance the heaps 
in the same way that we did while inserting.

Time complexity
The time complexity of our algorithm is O(N*K) where ‘N’ is the total number of elements in the input 
array and ‘K’ is the size of the sliding window. This is due to the fact that we are going through 
all the ‘N’ numbers and, while doing so, we are doing two things:

Inserting/removing numbers from heaps of size ‘K’. This will take O(logK)

Removing the element going out of the sliding window. This will take O(K) as we will be searching 
this element in an array of size ‘K’ (i.e., a heap).

Space complexity
Ignoring the space needed for the output array, the space complexity will be O(K) because, at any 
time, we will be storing all the numbers within the sliding window.

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// extending priority_queue to implement 'remove'
template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
 public:
  bool remove(const T &valueToRemove) {
    auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
    if (itr == this->c.end()) {
      return false;
    }
    this->c.erase(itr);
    // ideally we should not be rebuilding the heap as we are removing only one element
    // a custom implementation of priority queue can adjust only one element in O(logN)
    std::make_heap(this->c.begin(), this->c.end(), this->comp);
    return true;
  }
};

class SlidingWindowMedian {
 public:
  priority_queue_with_remove<int> maxHeap;
  priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result(nums.size() - k + 1);
    for (int i = 0; i < nums.size(); i++) {
      if (maxHeap.size() == 0 || maxHeap.top() >= nums[i]) {
        maxHeap.push(nums[i]);
      } else {
        minHeap.push(nums[i]);
      }
      rebalanceHeaps();

      if (i - k + 1 >= 0) {  // if we have at least 'k' elements in the sliding window
        // add the median to the the result array
        if (maxHeap.size() == minHeap.size()) {
          // we have even number of elements, take the average of middle two elements
          result[i - k + 1] = maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        } else {  // because max-heap will have one more element than the min-heap
          result[i - k + 1] = maxHeap.top();
        }

        // remove the element going out of the sliding window
        int elementToBeRemoved = nums[i - k + 1];
        if (elementToBeRemoved <= maxHeap.top()) {
          maxHeap.remove(elementToBeRemoved);
        } else {
          minHeap.remove(elementToBeRemoved);
        }
        rebalanceHeaps();
      }
    }
    return result;
  }

 private:
  void rebalanceHeaps() {
    // either both the heaps will have equal number of elements or max-heap will have
    // one more element than the min-heap
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}

