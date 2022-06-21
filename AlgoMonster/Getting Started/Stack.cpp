#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // ostream_iterator, prev
#include <limits> // numeric_limits
#include <stack> // stack
#include <string> // getline, string
#include <utility> // move
#include <vector> // vector

/*

Implementation
A basic implementation of the stack data structure uses a (statically-sized) array and a pointer pointing to the top of the stack 
(usually the next unused space). When inserting an item, we set the value at the pointer to the item and increment the pointer by 1. 
When removing an item, we decrease the pointer by 1. There is no need to reset the item at the pointer because it isn't accessible 
by the stack. It will be overwritten when more items are inserted (Although you might still want to reset it for languages with 
garbage collectors to prevent memory leaks).

Below is a graphical explanation of the actual implementation:

First slide
Previous
Next
In a real-world scenario, there are some situations we need to be careful of when doing an operation on a stack. Removing an item 
from a stack with no items will cause an "underflow" error. If we have a static-sized array as a stack and try to insert an item into 
the stack while it's full, it will cause an “overflow."

Underflow errors can be prevented by simply checking if the stack is empty before removing an item from the stack, as programs rarely 
want to pop from an empty stack. If a program does want that, that program probably wants to do something different if the stack is empty. 
Overflow errors are a bit tricky, as programs sometimes would like to add more items to the stack.

Fortunately for modern programming languages, there is usually a dynamically sized array data structure, and they can be used as 
a stack. Insertion and deletion from the list have a time complexity of O(1) (on average), just like a stack would, so we can use it 
as a stack. Because memories are dynamically assigned to the list, we don't have to worry about overflowing because if it reaches a 
max size, the system will allocate more memory for them.

For example, in Python, you can use the default list as a stack since all python lists are dynamically sized. In Java, you can use 
an ArrayList for this purpose (Java has a built-in Stack class, designed for synchronization, slower than ArrayList).

Here is a simple problem to demonstrate how you would use stacks in specific languages:

Given a mini program, consisting of a list of stack operations of push, pop, and peek, return the resulting stack after the execution 
of the program. Print out the top item in the stack when you get a peek instruction.

*/

std::stack<int> execute(std::vector<std::string> program) {
    // initialize the stack
    std::stack<int> stack;
    for (std::string instruction : program) {
        if (instruction == "peek") {
            // print out the top item in stack
            std::cout << stack.top() << std::endl;
        } else if (instruction == "pop") {
            // pop the top item in stack
            stack.pop();
        } else {
            // get the data in the "push" instruction
            int data = std::stoi(instruction.substr(5));
            // push data to the top of stack
            stack.push(data);
        }
    }
    return stack;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    int program_length;
    std::cin >> program_length;
    ignore_line();
    std::vector<std::string> program;
    for (int i = 0; i < program_length; i++) {
        std::string line;
        std::getline(std::cin, line);
        program.emplace_back(std::move(line));
    }
    std::stack<int> res_stack = execute(program);
    int n = res_stack.size();
    std::vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        res[i] = res_stack.top();
        res_stack.pop();
    }
    put_words(res);
}
