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
#include <iterator>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/mismatch

Returns the first mismatching pair of elements from two ranges: one defined by [first1, last1) 
and another defined by [first2,last2). If last2 is not provided (overloads (1-4)), it denotes 
first2 + (last1 - first1).

1,5) Elements are compared using operator==.
3,7) Elements are compared using the given binary predicate p.
2,4,6,8) Same as (1,3,5,7), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

*/

std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(), 
                        std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main()
{
    // note that the mismatch() function will return a pair of iterators, not element itself
    // below code is a demo to get mismatched pair, which is "X Z", then use the mismatched 
    // iterator as the end, so we can get matched string
    std::string input = "abXYZba";
    std::cout << "The input string is " << std::string(input.begin(), input.end()) << ", and do mismatch from forward and backward" << std::endl;
    auto test1 = std::mismatch(input.begin(), input.end(), input.rbegin());

    if (test1.first != input.end()) {
        std::cout << "First mismatched is " << *test1.first << ", and second mismatched is " << *test1.second << std::endl;
    } else {
        std::cout << "No mismatch found" << std::endl;
    }

    // as the test1.first returns the first mismatched iterator from input, so when we
    // print out the input.begin() to test1.first, which means the test1.first is like
    // the input.end(), so we will onlu print out the matched string
    std::cout << "The matched string is " << std::string(input.begin(), test1.first) << std::endl;

    // refer to https://en.cppreference.com/w/cpp/algorithm/mismatch
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';

    // 2022.8.1
    // Note, this function seems a good way to do LC string question
    // The input string is abXYZba, and do mismatch from forward and backward
    // First mismatched is X, and second mismatched is Z
    // The matched string is ab
    // ab
    // a
    // aba

    return 0;
}
