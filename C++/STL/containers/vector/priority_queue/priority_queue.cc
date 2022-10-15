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
    // STL adaptor priority_queue study
    priority_queue<double> myPQ;

    // regular constructor
    myPQ.emplace(1.999);
    myPQ.emplace(10.999);
    myPQ.emplace(10000.999);
    myPQ.emplace(1000.999);
    myPQ.emplace(100.999);

    // top(), return the toppest one, and if pop() is called, it will be the one
    // STL: Returns reference to the top element in the priority queue. This element will be removed on a call to pop(). 
    // If default comparison function is used, the returned element is also the greatest among the elements in the queue.
    cout << "the top element in the priority_queue is " << std::to_string(myPQ.top()) << endl;

    // ex  Input data : 5 9 3 10 12 4.
    // 
    // Heap (Considering Min heap) would be :
    //
    //               [3]
    //         [9]             [4]
    //     [10]    [12]     [5]
    //
    //
    // NOW , we store this min heap in to vector,             
    //  [3][9][4][10][12][5].
    //  Using formula ,
    //  Parent : ceiling of n-1/2
    //  Left Child : 2n+1
    //  Right Child : 2n+2 .
    // Hence ,
    //  Time Complexity for 
    //    Top = O(1) , get element from root node.
    //    POP()= O(logn) , During deletion of root node ,there  is chance to violation of heap order. hence restructure of heap order 
    //           takes at most O(logn) time (an element might move down to height of tree).
    //    PUSH()= O(logn) , During insertion also , there might chance to violation of  heap order . hence restructure of heap order 
    //           takes at most O(logn) time (an element might move up to root from leaf node).

    // new constructor with condition, now the default top element will be smallest one
    priority_queue<double, vector<double>, std::greater<double> > myPQ1;
    myPQ1.emplace(1.999);
    myPQ1.emplace(10.999);
    myPQ1.emplace(10000.999);
    myPQ1.emplace(1000.999);
    myPQ1.emplace(100.999);
    cout << "the top element in the priority_queue is " << std::to_string(myPQ1.top()) << endl;
    while (!myPQ1.empty()) {
        cout << std::to_string(myPQ1.top()) << endl;
        myPQ1.pop();
    }

    // empty()/size()/push()/pop()/emplace()
    // STL: Checks if the underlying container has no elements, i.e. whether c.empty().
    // STL: Returns the number of elements in the underlying container, that is, c.size().
    // STL: Pushes the given element value to the priority queue.
    // 1) Effectively calls c.push_back(value); std::push_heap(c.begin(), c.end(), comp);
    // 2) Effectively calls c.push_back(std::move(value)); std::push_heap(c.begin(), c.end(), comp);
    // STL: Pushes a new element to the priority queue. The element is constructed in-place, i.e. no copy or move operations are performed. 
    // The constructor of the element is called with exactly the same arguments as supplied to the function.
    // Effectively calls c.emplace_back(std::forward<Args>(args)...); std::push_heap(c.begin(), c.end(), comp);
    // STL: Removes the top element from the priority queue. Effectively calls std::pop_heap(c.begin(), c.end(), comp); c.pop_back();
    cout << boolalpha << "Is myPQ empty? " << myPQ.empty() << endl;
    cout << "Size of myPQ is " << myPQ.size() << endl;
    cout << "Top element of myPQ is " << myPQ.top() << endl;

    // swap(), swap context from one priority_queue to another priority_queue
    // STL: Exchanges the contents of the container adaptor with those of other. Effectively calls using std::swap; swap(c, other.c); 
    // swap(comp, other.comp);
    priority_queue<double, vector<double>, std::greater<double> > myPQ2;

    myPQ1.emplace(1.999);
    myPQ1.emplace(10.999);
    myPQ1.emplace(10000.999);
    myPQ1.emplace(1000.999);
    myPQ1.emplace(100.999);

    myPQ2.swap(myPQ1);
    cout << "Size of myPQ1 is " << myPQ1.size() << endl;
    cout << "Size of myPQ2 is " << myPQ2.size() << endl;

    // std::swap(), not from STL but C++ way
    std::swap(myPQ1, myPQ2);
    cout << "Size of myPQ1 is " << myPQ1.size() << endl;
    cout << "Size of myPQ2 is " << myPQ2.size() << endl;


    return 0;
}
