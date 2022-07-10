/*

Newspapers

You've begun working in the one and only Umbristan, and it is part of your job duty to 
organize newspapers. Every morning, your fellow coworkers will dilligently read through 
the newspapers to examine its contents. It is your job to organize the newspapers into 
piles and hand them out to your coworkers to read through.

Each newspaper is marked with the time it would take to read through its contents. 
The newspapers are carefully laid out in a line in a particular order that must not be 
broken when assigning the newspapers. You cannot pick and choose newspapers randomly from 
the line to assign to a co-worker. Instead, you must take newspapers from a particular 
subsection of the line, make a pile and give that to a co-worker.

What is the minimum amount of time it would take to have your coworkers go through all 
the newspapers?

Constraints
1 <= newspapers_read_times.length <= 10^5

1 <= newspapers_read_times[i] <= 10^5

1 <= num_coworkers <= 10^5

Examples
Example 1:
Input: newspapers_read_times = [7,2,5,10,8], num_coworkers = 2
Output: 18
Explanation:
Assign first 3 newspapers to one coworker then assign the rest to another. The time it 
takes for the first 3 newspapers is 7 + 2 + 5 = 14 and for the last 2 is 10 + 8 = 18.

Example 2:
Input: newspapers_read_times = [2,3,5,7], num_coworkers = 3
Output: 7
Explanation:
Assign [2, 3], [5], and [7] separately to workers. The minimum time is 7.

Solution
At minimum, the amount of time required to go through all the newspapers has to 
be >= max(newspapers_read_times) to be able to finish reading the longest newspaper. 
At maximum, if the amount of time taken to go through all the newspapers is 
sum(newspapers_read_times), then it'd require only 1 coworker to finish the work. 
Since we want to split the work of going through all the newspapers among num_coworkers 
workers, the minimum amount of time required to finish reading all the newspapers is 
somewhere in between max(newspapers_read_times) and sum(newspapers_read_times). 
Now, we simply need to perform binary search on the possible time values, checking if 
each time limit is enough to finish the work.

We check if a particular time works by trying to split the work among the coworkers 
and see if the the total time taken exceeds the given time limit. We do so by moving 
from left to right in the newspapers array while keeping track of the time that the 
current coworker spent. When the time that the current coworker spent exceeds the given 
time limit, we reset the current time tracker and add 1 to our coworker count. 
When we finish checking the newspapers array, we check if the required coworker count 
exceeds the one we are given. If it does, then we know that the given time limit doesn't 
work and we must try a higher value. Otherwise, we want to try a lower value to look 
for the minimum time limit that works.

Time complexity: O(n log n)

Setting the initial low and high values takes O(n) to find out the maximum value and 
the sum of newspapers_read_times. Then, performing binary search is O(log n), and the 
helper function feasible() that is called inside the binary search loop is O(n). 
Overall, the binary search takes O(n log n), which is more significant than O(n), 
so the time complexity of our solution is O(n log n).

*/

#include <algorithm> // copy, max_element
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <numeric> // accumulate
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool feasible(std::vector<int> newspapers_read_times, int num_coworkers, int limit) {
    // time to keep track of the current worker's time spent, num_workers to keep track of the number of coworkers used
    int time = 0, num_workers = 0;
    for (int read_time : newspapers_read_times) {
        // check if current time exceeds the given time limit
        if (time + read_time > limit) {
            time = 0;
            num_workers++;
        }
        time += read_time;
    }
    // edge case to check if we needed an extra worker at the end
    if (time != 0) {
        num_workers++;
    }
    // check if the number of workers we need is more than what we have
    return num_workers <= num_coworkers;
}

int newspapers_split(std::vector<int> newspapers_read_times, int num_coworkers) {
    int low = *std::max_element(newspapers_read_times.begin(), newspapers_read_times.end());
    int high = std::accumulate(newspapers_read_times.begin(), newspapers_read_times.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (feasible(newspapers_read_times, num_coworkers, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high + 1;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> newspapers_read_times = get_words<int>();
    int num_coworkers;
    std::cin >> num_coworkers;
    ignore_line();
    int res = newspapers_split(newspapers_read_times, num_coworkers);
    std::cout << res << '\n';
}

