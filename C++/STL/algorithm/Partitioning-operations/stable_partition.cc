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

https://en.cppreference.com/w/cpp/algorithm/stable_partition

1) Reorders the elements in the range [first, last) in such a way that all elements for which the 
predicate p returns true precede the elements for which predicate p returns false. Relative order 
of the elements is preserved.
2) Same as (1), but executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the first element of the second group

*/

int main()
{
    std::vector<int> v{0, 0, 3, -1, 2, 4, 5, 0, 7};

    // it will keep original order and partition the given vector
    std::stable_partition(v.begin(), v.end(), [](int n){return n>0;});
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
    // 3 2 4 5 7 0 0 -1 0 
}
