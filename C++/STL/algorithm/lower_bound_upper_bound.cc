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

https://en.cppreference.com/w/cpp/algorithm/lower_bound

Returns an iterator pointing to the first element in the range [first, last) that does not 
satisfy element < value (or comp(element, value)), (i.e. greater or equal to), or last if 
no such element is found.

The range [first, last) must be partitioned with respect to the expression element < value 
(or comp(element, value)), i.e., all elements for which the expression is true must precede 
all elements for which the expression is false. A fully-sorted range meets this criterion.

The first version uses operator< to compare the elements, the second version uses the given 
comparison function comp.

Return value
Iterator pointing to the first element in the range [first, last) such that element < value 
(or comp(element, value)) is false, or last if no such element is found.


https://en.cppreference.com/w/cpp/algorithm/upper_bound

Returns an iterator pointing to the first element in the range [first, last) such that 
value < element (or comp(value, element)) is true (i.e. strictly greater), or last if no 
such element is found.

The range [first, last) must be partitioned with respect to the expression !(value < element) 
or !comp(value, element), i.e., all elements for which the expression is true must precede 
all elements for which the expression is false. A fully-sorted range meets this criterion.

The first version uses operator< to compare the elements, the second version uses the given 
comparison function comp.

Return value
Iterator pointing to the first element in the range [first, last) such that value < element 
(or comp(value, element)) is true, or last if no such element is found.

*/

int main()
{
    vector<int> myV = {1, 3, 4, 5, 5, 5, 5, 5, 7, 9};

    // lower_bound() returns the iterator that is first one >= target
    auto ret1 = lower_bound(myV.begin(), myV.end(), 5);
    if (ret1 != myV.end()) cout << "lower_bound returns " << *ret1 << " at index " << distance(myV.begin(), ret1) << endl;

    // upper_bound returns the iterator that is first one > target
    auto ret2 = upper_bound(myV.begin(), myV.end(), 5);
    if (ret2 != myV.end()) cout << "upper_bound returns " << *ret2 << " at index " << distance(myV.begin(), ret2) << endl;

    // when there is no exact target existed in the given vector, lower_bound() returns the first >= iterator of value
    vector<int> myV2 = {1, 3, 5, 7, 9, 11};
    auto ret3 = lower_bound(myV2.begin(), myV2.end(), 6);
    if (ret3 != myV2.end()) cout << "lower_bound returns " << *ret3 << " at index " << distance(myV2.begin(), ret3) << endl;

    // when there is no exact target existed in the given vector, upper_bound() returns the first > iterator of value
    auto ret4 = upper_bound(myV2.begin(), myV2.end(), 6);
    if (ret4 != myV2.end()) cout << "upper_bound returns " << *ret4 << " at index " << distance(myV2.begin(), ret4) << endl;

    // 2022.8.2
    // Note, that means when lower_bound and upper_bound returns one iterator and same, that doesn't mean the given target
    // value existed based on above example. It may return the next one that is >= or > target value
    // from C++ 20, these functions will be under std::ranges, not under std::

    return 0;
    // lower_bound returns 5 at index 3
    // upper_bound returns 7 at index 8
    // lower_bound returns 7 at index 3
    // upper_bound returns 7 at index 3
}
