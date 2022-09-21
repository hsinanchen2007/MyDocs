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

https://en.cppreference.com/w/cpp/algorithm/partition_copy

1) Copies the elements from the range [first, last) to two different ranges depending on the value 
returned by the predicate p. The elements that satisfy the predicate p are copied to the range beginning 
at d_first_true. The rest of the elements are copied to the range beginning at d_first_false.
The behavior is undefined if the input range overlaps either of the output ranges.
2) Same as (1), but executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
A std::pair constructed from the iterator to the end of the d_first_true range and the iterator to 
the end of the d_first_false range.

*/

int main()
{
    int arr [10] = {1,2,3,4,5,6,7,8,9,10};
    int true_arr [5] = {0};
    int false_arr [5] = {0};

    // partition given vector into two different vectors, one with all returned true elements,
    // another with all returned false elements
    std::partition_copy(std::begin(arr), std::end(arr), std::begin(true_arr),std::begin(false_arr),
                        [] (int i) {return i > 5;});
 
    std::cout << "true_arr: ";
    for (int x : true_arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n'; 
 
    std::cout << "false_arr: ";
    for (int x : false_arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n'; 

    return 0;
    // true_arr: 6 7 8 9 10 
    // false_arr: 1 2 3 4 5 
}
