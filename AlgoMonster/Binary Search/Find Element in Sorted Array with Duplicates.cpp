/*

Find Element in Sorted Array with Duplicates
Prereq: Vanilla Binary Search and Finding the Boundary with Binary Search

Given a sorted array of integers and a target integer, find the first occurrence of the target 
and return its index. Return -1 if the target is not in the array.

Input:

arr = [1, 3, 3, 3, 3, 6, 10, 10, 10, 100]
target = 3
Output: 1

Explanation: First occurrence of 3 is at index 1.

Input:

arr = [2, 3, 5, 7, 11, 13, 17, 19]
target = 6
Output: -1

Explanation: 6 does not exists in the array.

Explanation
The problem is equivalent to finding the boundary of elements < 3 and elements >= 3. Imagine 
we apply a filter of arr[i] >= 3, we would get:

Now the problem is reduced to finding the first true element in a boolean array. And we already 
know how to do this from Find the Boundary module.

Time Complexity: O(log(n))

Implementation

*/

#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_first_occurrence(std::vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1, target_index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            target_index = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return target_index;
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = find_first_occurrence(arr, target);
    std::cout << res << '\n';
}


