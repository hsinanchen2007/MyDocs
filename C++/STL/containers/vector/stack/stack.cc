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
    // STL stack adaptor study
    // The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO 
    // (last-in, first-out) data structure.
    // The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The stack 
    // pushes and pops the element from the back of the underlying container, known as the top of the stack.

    stack<int> myIntStack;
    stack<vector<string>> myStringVectorStack;

    myIntStack.push(5);
    myIntStack.push(4);
    myIntStack.push(3);
    myIntStack.push(2);
    myIntStack.push(1);

    // top(), get current top element from stack, this is the only way to access one element from stack
    // STL: Returns reference to the top element in the stack. This is the most recently pushed element. This element will be removed 
    // on a call to pop(). Effectively calls c.back().

    // Note 1: stack/queue/priority_queue adaptors have no iterator, so there is no way to use for(...) loop
    // Note 2: it will be tricky that if we use stack.size() as condition in the for loop, and pop item out,
    //         it will cause unexpected result. it's safer to use while loop with stack.empty() check instead
    //         to loop through all elements in the stack
    cout << "Size of stack: " << myIntStack.size() << endl;
    while (!myIntStack.empty()) {
        cout << myIntStack.top() << endl;
        myIntStack.pop();
    }

    // size(), return the current size of stack
    // STL: Returns the number of elements in the underlying container, that is, c.size().
    cout << "Size of stack: " << myIntStack.size() << endl;

    myIntStack.push(5);
    myIntStack.push(1);
    myIntStack.push(4);
    myIntStack.push(2);
    myIntStack.push(3);

    for (int i = 0; i < 5; i++) {
        vector<string> tmpV;
        string s = "string";
        // use std::to_string() to convert given input to string
        s = s + std::to_string(i);
        tmpV.push_back(s);
        myStringVectorStack.push(tmpV);
    }

    // empty(), check if the stack is empty
    // STL: Checks if the underlying container has no elements, i.e. whether c.empty().
    while (!myStringVectorStack.empty()) {
        vector<string> tmpV = myStringVectorStack.top();
        for (int i = 0; i < tmpV.size(); i++) {
            cout << "items in the vector from top stack is " << tmpV[i] << endl;
        }
        myStringVectorStack.pop();
    }

    // push()/pop()/emplace() are all most used above
    // STL: Pushes the given element value to the top of the stack.
    // 1) Effectively calls c.push_back(value)
    // 2) Effectively calls c.push_back(std::move(value))
    // STL: Removes the top element from the stack. Effectively calls c.pop_back()
    // STL: Pushes a new element on top of the stack. The element is constructed in-place, i.e. no copy or move operations are performed. 
    // The constructor of the element is called with exactly the same arguments as supplied to the function.
    // Effectively calls c.emplace_back(std::forward<Args>(args)...);
    myIntStack.emplace(5);
    myIntStack.emplace(1);
    myIntStack.emplace(4);
    myIntStack.emplace(2);
    myIntStack.emplace(3);
    cout << "Size of stack: " << myIntStack.size() << endl;
    while (!myIntStack.empty()) {
        cout << myIntStack.top() << endl;
        myIntStack.pop();
    }

    // swap()/std::swap(), swap content from one stack to another stack. This is similar to all other containers
    deque<double> myDoubleDeque = {1.1, 2.2, 3.3};

    // overload from deque to stack
    stack<double> myDoubleStack1(myDoubleDeque);
    stack<double> myDoubleStack2;

    myDoubleStack2.swap(myDoubleStack1);
    std::swap(myDoubleStack1, myDoubleStack2); 

    return 0;
}
