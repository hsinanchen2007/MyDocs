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

https://en.cppreference.com/w/cpp/algorithm/transform_inclusive_scan

Transforms each element in the range [first, last) with unary_op, then computes an inclusive prefix 
sum operation using binary_op over the resulting range, optionally with init as the initial value, 
and writes the results to the range beginning at d_first. "inclusive" means that the i-th input element 
is included in the i-th sum.

Formally, assigns through each iterator i in [d_first, d_first + (last - first)) the value of

for overloads (1-2), the generalized noncommutative sum of unary_op(*j)... for every j in [first, 
first + (i - d_first + 1)) over binary_op,
for overloads (3-4), the generalized noncommutative sum of init, unary_op(*j)... for every j in 
[first, first + (i - d_first + 1)) over binary_op,

where generalized noncommutative sum GNSUM(op, a
1, ..., a
N) is defined as follows:

if N=1, a
1
if N > 1, op(GNSUM(op, a
1, ..., a
K), GNSUM(op, a
M, ..., a
N)) for any K where 1 < K+1 = M ≤ N

In other words, the summation operations may be performed in arbitrary order, and the behavior is 
nondeterministic if binary_op is not associative.

Overloads (2, 4) are executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

unary_op and binary_op shall not invalidate iterators (including the end iterators) or subranges, 
nor modify elements in the ranges [first, last) or [d_first, d_first + (last - first)). Otherwise, 
the behavior is undefined.

Return value
Iterator to the element past the last element written.

*/

int main()
{
    std::vector data {3, 1, 4, 1, 5, 9, 2, 6};
    
    auto times_10 = [](int x) { return x * 10; };
    
    std::cout << "10 times exclusive sum: ";
    std::transform_exclusive_scan(data.begin(), data.end(),
                    std::ostream_iterator<int>(std::cout, " "),
                    0, std::plus<int>{}, times_10);
    std::cout << "\n10 times inclusive sum: ";
    std::transform_inclusive_scan(data.begin(), data.end(),
                    std::ostream_iterator<int>(std::cout, " "),
                    std::plus<int>{}, times_10);

    return 0;
}
