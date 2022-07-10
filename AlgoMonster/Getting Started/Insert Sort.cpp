#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Insertion Sort

The idea of an insertion sort is this: initially, only the first item is considered sorted. 
Then, for each item in the sequence, we "insert" that item into the sorted list by swapping 
it with the item before it until the item is smaller than the current item.

Imagine you are sorting a hand of cards. What people usually do is maintain a pile of sorted 
cards and inserting from the unsorted pile into the sorted pile in the correct position. 
This algorithm is based on this idea.

Below is a graphical demonstration.

First slide
Previous
Next
The green squares represent the sorted list, and the yellow square represents the current item 
to be inserted.

Below is an implementation.

For each n item in the list, the time complexity to insert it into the sorted list is O(i), 
where i is the index of that item. Overall, the time complexity is O(n * (n - 1) / 2), which 
is equivalent to O(n^2).

It is a stable algorithm because later elements will not swap with earlier elements unless 
the later element is smaller, and it is an in-place algorithm because no additional data structure 
is used to store intermediate values.

*/

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    for (int i = 0; i < unsorted_list.size(); i++) {
        int current = i;
        while (current > 0 && unsorted_list[current] < unsorted_list[current - 1]) {
            int temp = unsorted_list[current];
            unsorted_list[current] = unsorted_list[current - 1];
            unsorted_list[current - 1] = temp;
            current--;
        }
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
