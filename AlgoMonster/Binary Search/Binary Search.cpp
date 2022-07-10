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

Calculating mid
Note that when calculating mid, if the number of elements is even, there are two elements in the middle. We usually follow the convention of picking the first one, equivalent to doing integer division (left + right) / 2.

In most programming languages, we calculate mid with left + floor((right-left) / 2) to avoid potential integer overflow. However, in Python, we do not need to worry about left + right integer overflow because Python3 integers can be arbitrarily large.

Deducing binary search
It's essential to understand and deduce the algorithm yourself instead of memorizing it. In an actual interview, interviewers may ask you additional questions to test your understanding, so simply memorizing the algorithm may not be enough to convince the interviewer.

Key elements in writing a correct binary search:

1. When to terminate the loop
Make sure the while loop has an equality comparison. Otherwise, we'd skip the loop and miss the potential match for the edge case of a one-element array.

2. Whether/how to update left and right boundary in the if conditions
Consider which side to discard. If arr[mid] is already smaller than the target, we should discard everything on the left by making left = mid + 1.

3. Should I discard the current element?
For vanilla binary search, we can discard it since it can't be the final answer if it is not equal to the target. There might be situations where you would want to think twice before discarding the current element. We'll discuss this in the next module.

When to use binary search
Interestingly, binary search works beyond sorted arrays. You can use binary search whenever you make a binary decision to shrink the search range. We will see this in the following modules.

P.S. Did you notice AlgoMonster's logo is an illustration of binary search? :P

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
