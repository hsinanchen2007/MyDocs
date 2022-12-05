/*

https://www.educative.io/courses/grokking-the-coding-interview/3jKlyNMJPEM

Solution
If the given list was not sorted, we could have simply appended the new interval to it and used the merge() 
function from Merge Intervals. But since the given list is sorted, we should try to come up with a solution 
better than O(N * logN)

When inserting a new interval in a sorted list, we need to first find the correct index where the new interval 
can be placed. In other words, we need to skip all the intervals which end before the start of the new interval. 
So we can iterate through the given sorted listed of intervals and skip all the intervals with the following 
condition:

intervals[i].end < newInterval.start
Once we have found the correct place, we can follow an approach similar to Merge Intervals to insert and/or 
merge the new interval. Let’s call the new interval ‘a’ and the first interval with the above condition ‘b’. 
There are five possibilities:

svg viewer

The diagram above clearly shows the merging approach. To handle all four merging scenarios, we need to do 
something like this:

    c.start = min(a.start, b.start)
    c.end = max(a.end, b.end)
Our overall algorithm will look like this:

Skip all intervals which end before the start of the new interval, i.e., skip all intervals with the following 
condition:
    intervals[i].end < newInterval.start
Let’s call the last interval ‘b’ that does not satisfy the above condition. If ‘b’ overlaps with the new interval (a) 
(i.e. b.start <= a.end), we need to merge them into a new interval ‘c’:
    c.start = min(a.start, b.start)
    c.end = max(a.end, b.end)
We will repeat the above two steps to merge ‘c’ with the next overlapping interval.

Time complexity
As we are iterating through all the intervals only once, the time complexity of the above algorithm is O(N), 
where ‘N’ is the total number of intervals.

Space complexity
The space complexity of the above algorithm will be O(N) as we need to return a list containing all the merged 
intervals.

*/

using namespace std;

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

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    if (intervals.empty()) {
      return vector<Interval>{newInterval};
    }

    vector<Interval> mergedIntervals;

    int i = 0;
    // skip (and add to output) all intervals that come before the 'newInterval'
    while (i < intervals.size() && intervals[i].end < newInterval.start) {
      mergedIntervals.push_back(intervals[i++]);
    }

    // merge all intervals that overlap with 'newInterval'
    while (i < intervals.size() && intervals[i].start <= newInterval.end) {
      newInterval.start = min(intervals[i].start, newInterval.start);
      newInterval.end = max(intervals[i].end, newInterval.end);
      i++;
    }

    // insert the newInterval
    mergedIntervals.push_back(newInterval);

    // add all the remaining intervals to the output
    while (i < intervals.size()) {
      mergedIntervals.push_back(intervals[i++]);
    }

    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}


