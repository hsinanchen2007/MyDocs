#include <algorithm> // copy
#include <deque> // deque
#include <iostream> // cin, cout, streamsize
#include <iterator> // ostream_iterator, prev
#include <limits> // numeric_limits
#include <string> // getline, string
#include <utility> // move
#include <vector> // vector

std::deque<int> execute(std::vector<std::string> program) {
    // initialize the deque representing a queue
    std::deque<int> queue;
    for (std::string instruction : program) {
        if (instruction == "peek") {
            if (queue.empty()) {
                // print warning message if queue is empty
                std::cout << "Queue is empty!" << std::endl;
            } else {
                // print out the top item in stack
                std::cout << queue.front() << std::endl;
            }
        } else if (instruction == "pop") {
            if (queue.empty()) {
                // print warning message if queue is empty
                std::cout << "Queue is empty!" << std::endl;
            } else {
                // pop the top item in stack
                queue.pop_front();
            }
        } else {
            // get the data in the "push" instruction
            int data = std::stoi(instruction.substr(5));
            // push data to the top of stack
            queue.push_back(data);
        }
    }
    return queue;
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
    std::deque<int> queue = execute(program);
    // create a vector out of the deque
    std::vector<int> res;
    while (!queue.empty()) {
        res.emplace_back(std::move(queue.front()));
        queue.pop_front();
    }
    put_words(res);
}
