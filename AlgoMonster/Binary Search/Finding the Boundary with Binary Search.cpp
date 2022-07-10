/*

Finding the Boundary with Binary Search
Prereq: Binary Search Introduction

An array of boolean values is divided into two sections; the left section consists of all false and the 
right section consists of all true. Find the boundary of the right section, i.e. the index of the first 
true element. If there is no true element, return -1.

Input: arr = [false, false, true, true, true]

Output: 2

Explanation: first true's index is 2.

Explanation
The binary decision we have to make when we look at an element is

if the element is false, we discard everything to the left and the current element itself.
if the element is true, the current element could be the first true although there may be other true to 
the left. We discard everything to the right but what about the current element?
We can either keep the current element in the range or record it somewhere and then discard it. Here we 
choose the latter. We'll discuss the other approach in the alternative solution section.

We keep a variable boundary_index that represents the leftmost true's index currently recorded. If the 
current element is true, then we update boundary_index with its index and discard everything to the right 
including the current element itself since its index has been recorded by the variable.

Time Complexity: O(log(n))

The good thing with this approach is that we don't have to modify the while loop logic in the vanilla 
binary search from the last module, besides introducing a variable.

Alternative approach
Another approach to handle case 2 above is to keep the current element in the search range instead of 
discarding it, i.e. if arr[mid]: right = mid instead of right = mid - 1. However, doing this without 
modifying the while condition will result in an infinite loop. This is because when left == right, 
right = mid will not modify right and thus, not shrink search range and we will be stuck in the while loop 
forever. To make this work we have to remove the equality in the while condition. In addition, as mentioned 
in the last module, a while loop without equality will miss the single-element edge case so we have to 
add an additional check after the loop to handle this case. Overall, we have to make three modifications 
to the vanilla binary search to make it work.

Side note: how to not get stuck in an infinite loop
make progress in each step
have an exit strategy

Summary
This problem is a major 🔑 in solving future binary search-related problems. As we will see in the following 
modules, many problems boil down to finding the boundary in a boolean array.

*/

#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_boundary(std::vector<bool> arr) {
    int left = 0;
    int right = arr.size() - 1;
    int boundaryIndex = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid]) {
            boundaryIndex = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return boundaryIndex;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}
