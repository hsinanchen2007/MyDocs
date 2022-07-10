#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Selection Sort
The idea for this sorting algorithm is that during each cycle, we find the smallest item 
from the unsorted pile and add it to the sorted pile.

To find the smallest element in the unsorted pile, we have a temporary variable keeping 
track of the index to the smallest element. We then compare each element in the unsorted 
pile to that element, updating the new index if necessary.

After all the elements have been compared, we swap the smallest index with the first index 
of the unsorted pile. The element is now part of the sorted pile.

Below is a graphical demonstration.

First slide
Previous
Next
And below is an implementation.

For each n item in the list, the time complexity to find the smallest item in the unsorted 
pile is O(n - i), where i is the index of that item. Overall, the time complexity is O(n * (n + 1) / 2), 
which is equivalent to O(n^2).

This algorithm is not stable because an earlier element can jump after an element of the 
the same value during a swap, but the algorithm is in place as it only needs additional 
memory to store the index to the minimum element.

*/

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    int n = unsorted_list.size();
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i; j < n; j++) {
            if (unsorted_list[j] < unsorted_list[min_index]) {
                min_index = j;
            }
        }
        int temp = unsorted_list[i];
        unsorted_list[i] = unsorted_list[min_index];
        unsorted_list[min_index] = temp;
    }
    return unsorted_list;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> unsorted_list = get_words<int>();
    std::vector<int> res = sort_list(unsorted_list);
    put_words(res);
}