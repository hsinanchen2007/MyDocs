/*

First Element Not Smaller Than Target
Prereq: Finding the Boundary with Binary Search

Given an array of integers sorted in increasing order and a target, find the index of the 
first element in the array that is larger than or equal to the target. Assume that it is 
guaranteed to find a satisfying number.

Input:

arr = [1, 3, 3, 5, 8, 8, 10]
target = 2
Output: 1

Explanation: the first element larger than 2 is 3 which has index 1.

Input:

arr = [2, 3, 5, 7, 11, 13, 17, 19]
target = 6
Output: 3

Explanation: the first element larger than 6 is 7 which has index 3.

Explanation
The problem is equivalent to finding the boundary of elements < 3 and elements >=3. Imagine 
if we apply a filter of arr[i] < target, we would get:

Now the problem is reduced to finding the first true element in a boolean array. And we already 
know how to do this from Find the Boundary module.

Time Complexity: `O(log(n))

Implementation

*/

#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int first_not_smaller(std::vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1, boundary_index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            boundary_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = first_not_smaller(arr, target);
    std::cout << res << '\n';
}


