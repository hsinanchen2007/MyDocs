/*

https://www.educative.io/courses/grokking-the-coding-interview/YVwln9kYxV2

Solution
The problem follows the Merge Intervals pattern and can easily be converted to Minimum Meeting Rooms. 
Similar to ‘Minimum Meeting Rooms’ where we were trying to find the maximum number of meetings happening 
at any time, for ‘Maximum CPU Load’ we need to find the maximum number of jobs running at any time. 
We will need to keep a running count of the maximum CPU load at any time to find the overall maximum load.

Time complexity
The time complexity of the above algorithm is O(N*logN), where ‘N’ is the total number of jobs. This is 
due to the sorting that we did in the beginning. Also, while iterating the jobs, we might need to poll/offer 
jobs to the priority queue. Each of these operations can take O(logN). Overall our algorithm will take O(NlogN)

Space complexity
The space complexity of the above algorithm will be O(N), which is required for sorting. Also, in the worst 
case, we have to insert all the jobs into the priority queue (when all jobs overlap) which will also take O(N)
 space. The overall space complexity of our algorithm is O(N)

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

class MaximumCPULoad {
 public:
  struct endCompare {
    bool operator()(const Job &x, const Job &y) { return x.end > y.end; }
  };

  static int findMaxCPULoad(vector<Job> &jobs) {
    if (jobs.empty()) {
      return 0;
    }

    // sort the jobs by start time
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) { return a.start < b.start; });

    int maxCPULoad = 0;
    int currentCPULoad = 0;
    priority_queue<Job, vector<Job>, endCompare> minHeap;
    for (auto job : jobs) {
      // remove all jobs that have ended
      while (!minHeap.empty() && job.start > minHeap.top().end) {
        currentCPULoad -= minHeap.top().cpuLoad;
        minHeap.pop();
      }

      // add the current job into the minHeap
      minHeap.push(job);
      currentCPULoad += job.cpuLoad;
      maxCPULoad = max(maxCPULoad, currentCPULoad);
    }

    return maxCPULoad;
  }
};

int main(int argc, char *argv[]) {
  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;
}

