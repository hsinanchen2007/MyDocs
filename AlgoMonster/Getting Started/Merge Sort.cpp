#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Merge Sort
The idea of a merge sort is divide and conquer: We divide the array into two almost equally, 
sort them (usually another merge sort), and merge the two sorted lists into one. To merge the 
two sorted lists, have two pointers point towards the bottom of the two lists, and in each step, 
add the smaller element from those two into the list and move the pointer of that item up by 
one until elements from both lists are fully added.

Below is a graphical demonstration.

First slide
Previous
Next
And below is an implementation.

*/

std::vector<int> sort_list(std::vector<int> unsorted_list) {
    int n = unsorted_list.size();
    if (n <= 1) return unsorted_list;
    int mid = n / 2;
    std::vector<int> left_list = sort_list(std::vector<int>(unsorted_list.begin(), unsorted_list.begin() + mid));
    std::vector<int> right_list = sort_list(std::vector<int>(unsorted_list.begin() + mid, unsorted_list.end()));
    std::vector<int> res;
    int left = 0, right = 0;
    while (left < mid || right < n - mid) {
        if (left == mid) {
            res.push_back(right_list[right]);
            right++;
        } else if (right == n - mid) {
            res.push_back(left_list[left]);
            left++;
        } else if (left_list[left] <= right_list[right]) {
            res.push_back(left_list[left]);
            left++;
        } else {
            res.push_back(right_list[right]);
            right++;
        }
    }
    return res;
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
