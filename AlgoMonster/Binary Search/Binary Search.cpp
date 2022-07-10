#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*

Binary Search
Intuition
Binary search is an efficient array search algorithm. It works by narrowing down the search range by half each time. 
If you have looked up a word in a physical dictionary, you've already used binary search in real life. Let's look at 
a simple example:

Given a sorted array of integers and an integer called target, find the element that equals the target and return its 
index. If the element is not found, return -1.

The key observation here is that the array is sorted. We pick a random element in the array and compare it to the target.

If we happen to pick the element that equals the target (how lucky!), then bingo. We don't need to do any more work; 
return its index. If the element is smaller than the target, then we know the target cannot be found in the section to 
the left of the current element since everything to the left is even smaller. So we discard the current element and 
everything on the left from the search range. If the element is larger than the target, then we know the target cannot 
be found in the section to the right of the current element since everything to the right is even larger. So we discard 
the current element and everything on the right from the search range. We repeat this process until we find the target. 
Instead of picking a random element, we always pick the middle element in the current search range. This way, we can 
discard half of the options and shrink the search range by half each time. This gives us O(log(N)) runtime.

Implementation

The search range is represented by the left and right indices that start from both ends of the array and move towards 
each other as we search. When moving the index, we discard elements and shrink the search range.

Time Complexity: O(log(n))

*/

int binary_search(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) { // <= here because left and right could point to the same element, < would miss it
        int mid = left + (right - left) / 2; // use `(right - left) /2` to prevent `left + right` potential overflow
        // found target, return its index
        if (arr.at(mid) == target) return mid;
        if (arr.at(mid) < target) {
            // middle less than target, discard left half by making left search boundary `mid + 1`
            left = mid + 1;
        } else {
            // middle greater than target, discard right half by making right search boundary `mid - 1`
            right = mid - 1;
        }
    }
    return -1; // if we get here we didn't hit above return so we didn't find target
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
    int res = binary_search(arr, target);
    std::cout << res << '\n';
}
