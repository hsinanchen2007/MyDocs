#include <algorithm> // copy
#include <deque> // deque
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/* 

Implementation
The implementation of a queue is similar to a stack: we use an array and two pointers, one pointing at the start of the queue 
and the other pointing at the end of the queue.

When inserting an item into the queue, we set the entry at the end pointer to the value and increase the end pointer by one. 
When removing an item from the queue, we increase the start pointer by one.

For a deque, we can use the same logic, but we allow the increment and decrement of both start and end pointers.

Below is a graphical explanation.

First slide
Previous
Next
One of the current implementation flaws is that when one of the queue pointers reaches the end of the array, it will cause an 
overflow. However, if some elements have been removed from the other end, then when the queue overflows, there are still a lot 
of unused empty spaces, which is not ideal.

An improvement that can be done to this implementation is to make the array “loop." When a pointer tries to move past the array, 
it loops around to the other end of the array instead. This is known as a Circular Buffer.

This works on both queues and deques.

Below is a graphical explanation:

First slide
Previous
Next
Most modern programming languages offer a built-in deque data structure. They often use a dynamic array as its underlying data 
structure (although they can also use a double-linked list, like Python's deque class). You won't have to worry about deques 
overflowing because the resizing of the array is handled for you.

Below is a demonstration of how you would use a queue in specific languages.

The function rotate_left_till_zero() takes an integer array containing one 0 and rotates the array counterclockwise so that the 
0 ends up at the front of the array.

*/

std::vector<int> rotate_left_till_zero(std::vector<int> nums) {
    // initialize the queue out of nums
    std::deque<int> queue(nums.begin(), nums.end());

    // continue the loop till front of queue is 0
    while (queue.front() != 0) {
        // peek at the front of queue and add it to the back of queue
        queue.push_back(queue.front());
        // dequeue the first number
        queue.pop_front();
    }

    // create a vector out of the queue
    std::vector<int> res;
    while (!queue.empty()) {
        res.emplace_back(std::move(queue.front()));
        queue.pop_front();
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
    std::vector<int> nums = get_words<int>();
    std::vector<int> res = rotate_left_till_zero(nums);
    put_words(res);
}
