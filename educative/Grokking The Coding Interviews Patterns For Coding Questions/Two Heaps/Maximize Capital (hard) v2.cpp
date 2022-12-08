/*

https://www.educative.io/courses/grokking-the-coding-interview/B6x69OLX4jY

Solution
While selecting projects we have two constraints:

We can select a project only when we have the required capital.
There is a maximum limit on how many projects we can select.
Since we don’t have any constraint on time, we should choose a project, among the projects for which 
we have enough capital, which gives us a maximum profit. Following this greedy approach will give us 
the best solution.

While selecting a project, we will do two things:

Find all the projects that we can choose with the available capital.
From the list of projects in the 1st step, choose the project that gives us a maximum profit.
We can follow the Two Heaps approach similar to Find the Median of a Number Stream. Here are the steps 
of our algorithm:

Add all project capitals to a min-heap, so that we can select a project with the smallest capital 
requirement.

Go through the top projects of the min-heap and filter the projects that can be completed within our 
available capital. Insert the profits of all these projects into a max-heap, so that we can choose a 
project with the maximum profit.

Finally, select the top project of the max-heap for investment.
Repeat the 2nd and 3rd steps for the required number of projects.

Time complexity
Since, at the most, all the projects will be pushed to both the heaps once, the time complexity of our 
algorithm is O(NlogN + KlogN), where ‘N’ is the total number of projects and ‘K’ is the number of 
projects we are selecting.

Space complexity
The space complexity will be O(N) because we will be storing all the projects in the heaps.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MaximizeCapital {
 public:
  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return y.first > x.first; }
  };

  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    int n = profits.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;

    // insert all project capitals to a min-heap
    for (int i = 0; i < n; i++) {
      minCapitalHeap.push(make_pair(capital[i], i));
    }

    // let's try to find a total of 'numberOfProjects' best projects
    int availableCapital = initialCapital;
    for (int i = 0; i < numberOfProjects; i++) {
      // find all projects that can be selected within the available capital and insert them in a
      // max-heap
      while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
        auto capitalIndex = minCapitalHeap.top().second;
        minCapitalHeap.pop();
        maxProfitHeap.push(make_pair(profits[capitalIndex], capitalIndex));
      }

      // terminate if we are not able to find any project that can be completed within the available
      // capital
      if (maxProfitHeap.empty()) {
        break;
      }

      // select the project with the maximum profit
      availableCapital += maxProfitHeap.top().first;
      maxProfitHeap.pop();
    }

    return availableCapital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}

