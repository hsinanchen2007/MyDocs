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

https://en.cppreference.com/w/cpp/algorithm/partition_point

Examines the partitioned (as if by std::partition) range [first, last) and locates the end of 
the first partition, that is, the first element that does not satisfy p or last if all elements 
satisfy p.

*/

auto print_seq = [](auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; std::cout << *first++ << ' ') {}
    std::cout << '\n';
};

int main()
{
    std::array<int, 9> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 
    auto is_even = [](int i){ return i % 2 == 0; };
 
    // do a stable partition which will keep original order of vector
    std::stable_partition(v.begin(), v.end(), is_even);
    print_seq("After partitioning, v: ", v.cbegin(), v.cend());
 
    // after partition, locate the iterator of first part
    const auto pp = std::partition_point(v.cbegin(), v.cend(), is_even);
    const auto i = std::distance(v.cbegin(), pp);
    std::cout << "Partition point is at " << i << "; v[" << i << "] = " << *pp << '\n';
 
    print_seq("First partition (all even elements): ", v.cbegin(), pp);
    print_seq("Second partition (all odd elements): ", pp, v.cend());

    return 0;
    // After partitioning, v: 2 4 6 8 1 3 5 7 9 
    // Partition point is at 4; v[4] = 1
    // First partition (all even elements): 2 4 6 8 
    // Second partition (all odd elements): 1 3 5 7 9 
}
