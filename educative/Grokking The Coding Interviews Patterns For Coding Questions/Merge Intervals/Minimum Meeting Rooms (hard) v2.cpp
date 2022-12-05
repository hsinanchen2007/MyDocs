/*

https://www.educative.io/courses/grokking-the-coding-interview/JQMAmrVPL7l

Solution
Let’s take the above-mentioned example (4) and try to follow our Merge Intervals approach:

Meetings: [[4,5], [2,3], [2,4], [3,5]]

Step 1: Sorting these meetings on their start time will give us: [[2,3], [2,4], [3,5], [4,5]]

Step 2: Merging overlapping meetings:

[2,3] overlaps with [2,4], so after merging we’ll have => [[2,4], [3,5], [4,5]]
[2,4] overlaps with [3,5], so after merging we’ll have => [[2,5], [4,5]]
[2,5] overlaps [4,5], so after merging we’ll have => [2,5]

Since all the given meetings have merged into one big meeting ([2,5]), does this mean that they all are overlapping 
and we need a minimum of four rooms to hold these meetings? You might have already guessed that the answer is NO! 
As we can clearly see, some meetings are mutually exclusive. For example, [2,3] and [3,5] do not overlap and can 
happen in one room. So, to correctly solve our problem, we need to keep track of the mutual exclusiveness of the 
overlapping meetings.

Here is what our strategy will look like:

We will sort the meetings based on start time.
We will schedule the first meeting (let’s call it m1) in one room (let’s call it r1).
If the next meeting m2 is not overlapping with m1, we can safely schedule it in the same room r1.
If the next meeting m3 is overlapping with m2 we can’t use r1, so we will schedule it in another room (let’s call it r2).
Now if the next meeting m4 is overlapping with m3, we need to see if the room r1 has become free. For this, we need 
to keep track of the end time of the meeting happening in it. If the end time of m2 is before the start time of m4, 
we can use that room r1, otherwise, we need to schedule m4 in another room r3.
We can conclude that we need to keep track of the ending time of all the meetings currently happening so that when we 
try to schedule a new meeting, we can see what meetings have already ended. We need to put this information in a data 
structure that can easily give us the smallest ending time. A Min Heap would fit our requirements best.

So our algorithm will look like this:

Sort all the meetings on their start time.
Create a min-heap to store all the active meetings. This min-heap will also be used to find the active meeting with 
the smallest end time.
Iterate through all the meetings one by one to add them in the min-heap. Let’s say we are trying to schedule the meeting 
m1.
Since the min-heap contains all the active meetings, so before scheduling m1 we can remove all meetings from the heap 
that have ended before m1, i.e., remove all meetings from the heap that have an end time smaller than or equal to the 
start time of m1.

Now add m1 to the heap.
The heap will always have all the overlapping meetings, so we will need rooms for all of them. Keep a counter to remember 
the maximum size of the heap at any time which will be the minimum number of rooms needed.

Time complexity
The time complexity of the above algorithm is O(N*logN), where ‘N’ is the total number of meetings. This is due to the 
sorting that we did in the beginning. Also, while iterating the meetings we might need to poll/offer meeting to the priority 
queue. Each of these operations can take O(logN). Overall our algorithm will take O(NlogN)

Space complexity
The space complexity of the above algorithm will be O(N) which is required for sorting. Also, in the worst case scenario, 
we’ll have to insert all the meetings into the Min Heap (when all meetings overlap) which will also take O(N) space. The 
overall space complexity of our algorithm is O(N)

Similar Problems
Problem 1: Given a list of intervals, find the point where the maximum number of intervals overlap.

Problem 2: Given a list of intervals representing the arrival and departure times of trains to a train station, our goal is 
to find the minimum number of platforms required for the train station so that no train has to wait.

Both of these problems can be solved using the approach discussed above.

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct endCompare {
    bool operator()(const Meeting &x, const Meeting &y) { return x.end > y.end; }
  };

  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    if (meetings.empty()) {
      return 0;
    }

    // sort the meetings by start time
    sort(meetings.begin(), meetings.end(),
         [](const Meeting &x, const Meeting &y) { return x.start < y.start; });

    int minRooms = 0;
    priority_queue<Meeting, vector<Meeting>, endCompare> minHeap;
    for (auto meeting : meetings) {
      // remove all meetings that have ended
      while (!minHeap.empty() && meeting.start >= minHeap.top().end) {
        minHeap.pop();
      }
      // add the current meeting into the minHeap
      minHeap.push(meeting);
      // all active meeting are in the minHeap, so we need rooms for all of them.
      minRooms = max(minRooms, (int)minHeap.size());
    }

    return minRooms;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{1, 4}, {2, 5}, {7, 9}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}

