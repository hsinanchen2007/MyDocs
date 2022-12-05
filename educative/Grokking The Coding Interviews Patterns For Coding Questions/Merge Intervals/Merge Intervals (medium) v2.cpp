/*

https://www.educative.io/courses/grokking-the-coding-interview/3jyVPKRA8yx

Solution 
Let’s take the example of two intervals (‘a’ and ‘b’) such that a.start <= b.start. There are four 
possible scenarios:

Our goal is to merge the intervals whenever they overlap. For the above-mentioned three overlapping 
scenarios (2, 3, and 4), this is how we will merge them:

The diagram above clearly shows a merging approach. Our algorithm will look like this:

Sort the intervals on the start time to ensure a.start <= b.start
If ‘a’ overlaps ‘b’ (i.e. b.start <= a.end), we need to merge them into a new interval ‘c’ such that:
    c.start = a.start
    c.end = max(a.end, b.end)
We will keep repeating the above two steps to merge ‘c’ with the next interval if it overlaps with ‘c’.

Time complexity
The time complexity of the above algorithm is O(N * logN), where ‘N’ is the total number of intervals. 
We are iterating the intervals only once which will take O(N), in the beginning though, since we need to 
sort the intervals, our algorithm will take O(N * logN)

Space complexity
The space complexity of the above algorithm will be O(N) as we need to return a list containing all the 
merged intervals. We will also need O(N) space for sorting. For Java, depending on its version, Collections.sort() 
either uses Merge sort or Timsort, and both these algorithms need O(N) space. Overall, our algorithm has 
a space complexity of O(N)

Similar Problems
Problem 1: Given a set of intervals, find out if any two intervals overlap.

Example:

Intervals: [[1,4], [2,5], [7,9]]
Output: true
Explanation: Intervals [1,4] and [2,5] overlap
Solution: We can follow the same approach as discussed above to find if any two intervals overlap.

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }

    // sort the intervals by start time
    sort(intervals.begin(), intervals.end(),
         [](const Interval &x, const Interval &y) { return x.start < y.start; });

    vector<Interval> mergedIntervals;

    vector<Interval>::const_iterator intervalItr = intervals.begin();
    Interval interval = *intervalItr++;
    int start = interval.start;
    int end = interval.end;
    while (intervalItr != intervals.end()) {
      interval = *intervalItr++;
      if (interval.start <= end) {  // overlapping intervals, adjust the 'end'
        end = max(interval.end, end);
      } else {  // non-overlapping interval, add the previous interval and reset
        mergedIntervals.push_back({start, end});
        start = interval.start;
        end = interval.end;
      }
    }
    // add the last interval
    mergedIntervals.push_back({start, end});
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}



