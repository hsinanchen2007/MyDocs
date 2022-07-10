/*

Square Root
Prereq: Finding the Boundary

Given an integer, find its square root without using the built-in square root function. Only return 
the integer part (truncate the decimals).

Input: 16

Output: 4

Input: 8

Output: 2

Explanation: square root of 8 is 2.83..., return integer part 2

Explanation
The problem is equivalent to finding the boundary of elements < n and elements >= n. Imagine we 
apply a filter of arr[i]^2 <= n, we would get:

Now the problem is reduced to finding the last true element in a boolean array. And we already know 
how to do this from Find the Boundary module.

Time Complexity: O(log(n))

Implementation

*/

#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int square_root(int n) {
    int left = 0, right = n, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= n / mid) {
            left = mid + 1;
            res = mid;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = square_root(n);
    std::cout << res << '\n';
}
