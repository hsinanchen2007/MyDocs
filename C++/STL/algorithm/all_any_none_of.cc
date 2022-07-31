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

https://en.cppreference.com/w/cpp/algorithm/all_any_none_of

1) Checks if unary predicate p returns true for all elements in the range [first, last).
3) Checks if unary predicate p returns true for at least one element in the range [first, last).
5) Checks if unary predicate p returns true for no elements in the range [first, last).
2,4,6) Same as (1,3,5), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

See also Notes below.

1-2) true if unary predicate returns true for all elements in the range, false otherwise. Returns true if the range is empty.
3-4) true if unary predicate returns true for at least one element in the range, false otherwise. Returns false if the range is empty.
5-6) true if unary predicate returns true for no elements in the range, false otherwise. Returns true if the range is empty.

*/

int main()
{
    vector<int> myV = {1, 3, 5, 7, 9, 10};

    // by using all_of() to see if all values in the given vector are odd or not
    // note that all_of() returns true only if the condition applies to all return true
    bool isAllOdd = all_of(myV.begin(), myV.end(), [](int value) { return (value % 2 == 0); });
    if (isAllOdd) {
        cout << "All numbers are odd!" << endl;
    } else {
        cout << "Some numbers are even!" << endl;
    }

    // by using any_of() to see if any value in the given vector is even or not
    // note that any_of() returtns true as long as the condition matches to one value
    bool isAnyEven = any_of(myV.begin(), myV.end(), [](int value) { return (value % 2 == 0); });
    if (isAnyEven) {
        cout << "At least one number is even!" << endl;
    } else {
        cout << "All numbers are odd!" << endl;
    }

    // by using none_of() to see if any value is larger than 100 or not
    // note that none_of() returns true only if the condition applies to all values return false
    bool allLess = none_of(myV.begin(), myV.end(), [](int value) { return (value > 100); });
    if (allLess) {
        cout << "None of numbers is larger than 100!" << endl;
    } else {
        cout << "At least one number is larger than 100!" << endl;
    }

    // easier to remember is, whether "function" them is "condition"? Then use this to for return true/false 
    // from C++ 20, these functions will be under std::ranges, not under std::

    return 0;
    // Some numbers are even!
    // At least one number is even!
    // None of numbers is larger than 100!
}
