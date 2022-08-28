/*

The Peak of a Mountain Array

Prereq: Vanilla Binary Search and Finding the Boundary with Binary Search

A mountain array is defined as an array that

has at least 3 elements
has an element with the largest value called "peak", with index k. The array elements 
monotonically increase from the first element to A[k], and then monotonically decreases 
from A[k + 1] to the last element of the array. Thus creating a "mountain" of numbers.
That is, given A[0]<...<A[k-1]<A[k]>A[k+1]>...>A[n-1], we need to find the index k. 
Note that the peak element is neither the first nor the last element of the array.

Find the index of the peak element. Assume there is only one peak element.

Input: 0 1 2 3 2 1 0

Output: 3

Explanation: the largest element is 3 and its index is 3.

Explanation
The peak element is always larger than the next element. Applying the filter of 
arr[i] > arr[i + 1] we get a boolean array. A minor edge case is for the last element as 
it has no next element. In that case, we assume its next element is negative infinity.

Now the problem is reduced to finding the first true element in a boolean array. And we 
already know how to do this from Find the Boundary module.

Time Complexity: O(log(n))

*/

#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int peak_of_mountain_array(std::vector<int> arr) {
    int left = 0, right = arr.size() - 1, boundary_index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1]) {
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

int main() {
    std::vector<int> arr = get_words<int>();
    int res = peak_of_mountain_array(arr);
    std::cout << res << '\n';
}

