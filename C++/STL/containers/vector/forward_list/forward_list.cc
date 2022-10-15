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
void myprint(double value) {
    cout << value << endl;
}

// main
int main() {
    forward_list<double> myForwardList = {1.1, 2.2, 3.3, 4.4, 5.5};
    forward_list<double> myOrgForwardList(myForwardList.begin(), myForwardList.end());

    // forward_list, we only know the head/begin, not tail/end, so most functions are same as list except:
    // 1. No size() as it didn't know the end. Everything needed to start from the beginning
    // 2. All add/remove/insert calls will start from the beginning, or before one specific iterator location
    // 3. No back() call

    // iterator, before_begin()/cbefore_begin(), as forward_list didn't have "back" direct access, but it allows
    // to access something before the begin(). Only forward_list has these two functions
    // STL: Returns an iterator to the element before the first element of the container. This element acts as a 
    // placeholder, attempting to access it results in undefined behavior. The only usage cases are in functions 
    // insert_after(), emplace_after(), erase_after(), splice_after() and the increment operator: incrementing the 
    // before-begin iterator gives exactly the same iterator as obtained from begin()/cbegin().
    cout << "Before inserting one element before begin()" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    auto beforeBegin = myForwardList.before_begin();
    myForwardList.insert_after(beforeBegin, 0.0);
    cout << "After inserting one element before begin()" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    // again, no back() or size() functions as it is forward list, so as it cannot access elements to the end directly,
    // no size() of back() call

    // insert_after()/emplace_after()/erase_after(), insert/create/erase one element after the specific iterator location
    cout << "Before inserting two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    auto beginPtr = myForwardList.begin();
    myForwardList.insert_after(beginPtr, 0.5);
    myForwardList.emplace_after(beginPtr, 0.6);
    // 0.6 will be added before 0.5, as the beginPtr remains same
    cout << "After inserting two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    myForwardList.erase_after(beginPtr);
    myForwardList.erase_after(beginPtr);
    cout << "After erasing two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    // clear()/push_front()/emplace_front()/pop_front()/resize()/swap() are all same functions as list

    // splice_after(), insert another list after the specific iterator location
    cout << "After inserting another list to after begin iterator" << endl;
    myForwardList.splice_after(beginPtr, myOrgForwardList);
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    return 0;
}
