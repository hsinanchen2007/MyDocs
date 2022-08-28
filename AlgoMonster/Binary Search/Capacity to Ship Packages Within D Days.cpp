/*

Capacity to Ship Packages Within D Days
There are n packages that needs to be transported from one city to another, and you 
need to transport them there within d days. For the ith package, the weight of the 
package is weights[i]. You are required to deliver them in order with a rental truck. 
The rental trucks come in different sizes. The bigger trucks have greater weight capacity 
but cost more to rent. To minimize cost, you want to deliver the packages in one truck 
once per day, with a weight capacity as small as possible to save on rental cost. 
What is the minimum weight capacity of the truck that is required to deliver all packages 
within d days?

Input
weights: A list of packages and their weights.
d: The number of days to deliver all packages.
Output
The minimum weight capacity of the truck.

Examples
Example 1:
Input:

weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
d = 5
Output: 15

Explanation:

The first day we deliver the first 5 package. The second day we deliver the next 2, 
and for each following days, we deliver 1. The maximum weight delivered on each day is 15, 
so we can have a truck with a capacity of 15. This value is the minimum.

Constraints
1 <= len(weights) <= 5 * 10^4
1 <= d <= len(weights)
1 <= weights[i] <= 500

Solution
At minimum, the truck's capacity has to be >= max(weights) to be able to carry the biggest 
package.

At maximum, if our truck capacity is sum(weights), then it'd take only 1 day to ship.

Since we want to ship within d days, the optimal truck capacity somewhere in between.

We know how to find if a truck capacity is feasible or not - we simply loop through the weights 
and see if we can ship it within d days.

Now this has yet again turned into the classic Finding the Boundary problem.

Time complexity: O(n log n)

In our solution, setting the initial min_ptr and max_ptr values takes O(n) to find out the 
maximum value and the sum of weights. Then, performing binary search is O(log n), and the helper 
function feasible() that is called inside the binary search loop is O(n). Overall, the binary 
search takes O(n log n), which is more significant than O(n), so the time complexity of our 
solution is O(n log n).

*/

#include <algorithm> // copy, max_element
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <numeric> // accumulate
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool feasible(std::vector<int> weights, int max_weight, int d) {
    int req_days = 1;
    int capacity = max_weight;
    int i = 0;
    int n = weights.size();
    while (i < n) {
        if (weights[i] <= capacity) {
            capacity -= weights[i];
            i++;
        } else {
            req_days++;
            capacity = max_weight;
        }
    }
    return req_days <= d;
}

int min_max_weight(std::vector<int> weights, int d) {
    int min_ptr = *std::max_element(weights.begin(), weights.end());
    int max_ptr = std::accumulate(weights.begin(), weights.end(), 0);
    int boundary_index = max_ptr;
    while (min_ptr <= max_ptr) {
        int mid = min_ptr + (max_ptr - min_ptr) / 2;
        if (feasible(weights, mid, d)) {
            boundary_index = mid;
            max_ptr = mid - 1;
        } else {
            min_ptr = mid + 1;
        }
    }
    return boundary_index;
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
    std::vector<int> weights = get_words<int>();
    int d;
    std::cin >> d;
    ignore_line();
    int res = min_max_weight(weights, d);
    std::cout << res << '\n';
}

