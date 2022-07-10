#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Bubble Sort
The idea of bubble sort is this: for each pass, we use a pointer to point at the first element 
of the list. For each cycle, we compare it to the next element in the list and swap them if the 
current item is greater, then move the pointer by one until it reaches the end of the list. 
We repeat this process until the list becomes sorted. The list is sorted if, during a pass, no 
swapping occurs.

Note that the largest element will always "float" to the top during each pass, like a bubble. 
Therefore, for each pass, we only need to consider the interval excluding the last element of 
the previous interval, and the list is guaranteed to be sorted within n passes.

Below is a graphical explanation.

First slide
Previous
Next
And below is an implementation.

The time complexity of this algorithm, like before, is O(n^2), because it is essentially two 
loops.

It is a stable algorithm because a swap cannot cause an element to move past another one with 
the same value, and it is in place because no additional data structure is used.

*/

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    int n = unsorted_list.size();
    for (int i = n - 1; i >= 0; i--) {
        bool swapped = false;
        for (int j = 0; j < i; j++) {
            if (unsorted_list[j] > unsorted_list[j + 1]) {
                int temp = unsorted_list[j];
                unsorted_list[j] = unsorted_list[j + 1];
                unsorted_list[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) return unsorted_list;
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