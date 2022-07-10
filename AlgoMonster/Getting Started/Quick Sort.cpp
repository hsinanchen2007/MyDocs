#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Quick Sort
The idea of quick sort is this: We select an arbitrary element in the list (known as the "pivot"), 
and we swap the elements in the list into two sides: a side where all the elements are smaller than 
the pivot, and a side where all the elements are larger or equal to the pivot.

After grouping them this way, we swap the pivot with the first element of the side that is larger 
or equal to the pivot. This way, each element to the left of the pivot is smaller than it, and each 
element on the right is larger or equal. Then we need to sort the left and right intervals (using 
the same method), then the list will be sorted.

How would it group? One of the ways to achieve this is that for the interval that we are sorting, 
we have a pointer point before the start and at the end (including the pivot). For each swap, we move 
the start pointer until we find an element larger or equal to the pivot (after the initial index) 
and move the end pointer until we find an element smaller or equal to the pivot (before the initial index). 
Then we can swap those two elements and restart the process. If those two pointers meet, we stop , 
and then we can swap the pivot and the meeting point.

Below is a graphical explanation:

First slide
Previous
Next
And below is an implementation.

*/

void sort_list_interval(std::vector<int> &unsorted_list, int start, int end) {
    if (end - start <= 1) return;
    int pivot = unsorted_list[end - 1];
    int start_ptr = start, end_ptr = end - 1;
    while (start_ptr < end_ptr) {
        while (unsorted_list[start_ptr] < pivot && start_ptr < end_ptr) {
            start_ptr++;
        }
        while (unsorted_list[end_ptr] >= pivot && start_ptr < end_ptr) {
            end_ptr--;
        }
        if (start_ptr == end_ptr) break;
        int temp = unsorted_list[start_ptr];
        unsorted_list[start_ptr] = unsorted_list[end_ptr];
        unsorted_list[end_ptr] = temp;
    }
    int temp = unsorted_list[start_ptr];
    unsorted_list[start_ptr] = unsorted_list[end - 1];
    unsorted_list[end - 1] = temp;
    sort_list_interval(unsorted_list, start, start_ptr);
    sort_list_interval(unsorted_list, start_ptr + 1, end);
}

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    sort_list_interval(unsorted_list, 0, unsorted_list.size());
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