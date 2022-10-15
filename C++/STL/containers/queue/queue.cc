// https://leetcode.com/problems/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution


// main
int main() {
    // STL adaptor queue study
    queue<double> myQueue;

    myQueue.push(1.2);
    myQueue.push(2.3);
    myQueue.push(3.4);
    myQueue.push(4.5);
    myQueue.push(5.6);

    // front()/back(), queue is different from stack that it allows to access either front or back element directly
    // Queue is FIFO
    // STL: Returns reference to the first element in the queue. This element will be the first element to be removed 
    // on a call to pop(). Effectively calls c.front().
    // STL: Returns reference to the last element in the queue. This is the most recently pushed element. Effectively calls c.back().
    cout << "current myQueue front is " << myQueue.front() << endl;
    cout << "current myQueue back is " << myQueue.back() << endl;

    // empty()/size(), return queue status and its size
    // STL: Checks if the underlying container has no elements, i.e. whether c.empty().
    // STL: Returns the number of elements in the underlying container, that is, c.size().
    cout << boolalpha << "Is current queue empty? " << myQueue.empty() << " and its size is " << myQueue.size() << endl;

    // similar to stack, if we want to iterate all elements from front side in order, use while loop
    while (!myQueue.empty()) {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }

    // push()/pop()/emplace()/swap()/std::swap(), there are all similar to stack, however, queue can only push new element at the end, and 
    // pop first element from the front. This is different from deque container, where it is actually implemented by vector internally
    // so it allows to push/pop elements from/to front/back
    // STL: Pushes the given element value to the end of the queue.
    // 1) Effectively calls c.push_back(value)
    // 2) Effectively calls c.push_back(std::move(value))
    // STL: Removes an element from the front of the queue. Effectively calls c.pop_front()
    // STL: Pushes a new element to the end of the queue. The element is constructed in-place, i.e. no copy or move operations are performed. 
    // The constructor of the element is called with exactly the same arguments as supplied to the function.
    // Effectively calls c.emplace_back(std::forward<Args>(args)...);
    // STL: Exchanges the contents of the container adaptor with those of other. Effectively calls using std::swap; swap(c, other.c);
    myQueue.emplace(1.2);
    myQueue.push(2.3);
    myQueue.emplace(3.4);
    myQueue.push(4.5);
    myQueue.emplace(5.6);

    queue<double> myQueue2;
    myQueue2.swap(myQueue);
    cout << "Size of myQueue is " << myQueue.size() << endl;
    cout << "Size of myQueue2 is " << myQueue2.size() << endl;

    std::swap(myQueue, myQueue2);
    cout << "Size of myQueue is " << myQueue.size() << endl;
    cout << "Size of myQueue2 is " << myQueue2.size() << endl;

    return 0;
}
