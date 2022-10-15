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
void myprint(string value) {
    cout << value << endl;
}
void myprint2(int value) {
    cout << value << endl;
}
bool isSmallerThan(int value) {
    if (value < 10) {
        return true;
    } else {
        return false;
    }
}

// main
int main() {
    list<string> myList = {"First", "Second", "Third"};
    list<string> myOrgList1 = myList;
    list<string> myOrgList2;

    // show all elements in the list
    for_each(myList.begin(), myList.end(), myprint);
    // move myOrgList1 to myOrgList2
    cout << "After std::move from myOrgList1 to myOrgList2" << endl;
    myOrgList2 = std::move(myOrgList1);
    cout << "myOrgList1 should have nothing" << endl;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << endl;
    cout << "myOrgList1 size " << myOrgList1.size() << endl;
    cout << "myOrgList2" << endl;
    for_each(myOrgList2.begin(), myOrgList2.end(), myprint);
    cout << endl;
    cout << "myOrgList2 size " << myOrgList2.size() << endl;

    // assign(), assign one or multiple elements into list
    // STL: Replaces the contents of the container.
    // 1) Replaces the contents with count copies of value value
    // 2) Replaces the contents with copies of those in the range [first, last). The behavior is undefined if 
    // either argument is an iterator into *this.
    // This overload has the same effect as overload (1) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt satisfies LegacyInputIterator. (since C++11)
    // 3) Replaces the contents with the elements from the initializer list ilist.
    // All iterators, pointers and references to the elements of the container are invalidated.
    cout << "Assign all elements from myOrgList2 to myOrgList1" << endl;
    myOrgList1.assign(myOrgList2.begin(), myOrgList2.end()); 
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << "Assign 5 elements to NEW" << endl;
    myOrgList1.assign(5, "NEW");
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << "Assign 5 elements to different values" << endl;
    myOrgList1.assign({"First", "Second", "Third", "Forth", "Fifth"});
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // getallocator(), similar to all other container's

    // front()/back(), return the first or last element in list. Note that list is doubly linked list
    // Note that there is no operator[] or such iterator++/iterator--/begin()++/end()++ ways for element access in list
    // which means we cannot access element by begin()+1 to get next one from begin(). We need to use std::next()
    // or std::prev() to access next or previous one
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    // STL: Returns a reference to the last element in the container.
    // Calling back on an empty container causes undefined behavior.
    cout << "First element is " << myOrgList1.front() << " and last element is " << myOrgList1.back() << endl;

    // iterator
    for (auto it=myOrgList1.begin(); it!=myOrgList1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto &it : myOrgList1) {
        cout << it << " ";
    }
    cout << endl;

    // empty()/size()/max_size(), check if the list is empty, its size and its max_size that the system can handle
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    // STL: Returns the maximum number of elements the container is able to hold due to system or library implementation 
    // limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << boolalpha;
    cout << "Is the list empty? " << myOrgList1.empty() << ", size = " << myOrgList1.size() << ", max size = " << myOrgList1.max_size() << endl;

    // clear(), erase all elements in ths list
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterator remains valid.
    cout << "Erasing all elements in myOrgList1 now" << endl;
    myOrgList1.clear();
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // insert()/emplace(), add one element into list at a specific location by using iterator
    // STL: Inserts elements at the specified location in the container.
    // 1-2) inserts value before pos
    // 3) inserts count copies of the value before pos
    // 4) inserts elements from range [first, last) before pos.
    // This overload has the same effect as overload (3) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt qualifies as LegacyInputIterator, to avoid ambiguity with 
    // the overload (3). (since C++11)
    // The behavior is undefined if first and last are iterators into *this.
    // 5) inserts elements from initializer list ilist before pos.
    // No iterators or references are invalidated.
    // STL: Inserts a new element into the container directly before pos.
    // The element is constructed through std::allocator_traits::construct, which uses placement-new to construct the element 
    // in-place at a location provided by the container.
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args).... args... may directly or indirectly 
    // refer to a value in the container.
    // No iterators or references are invalidated.
    cout << "Calling insert() and emplace() to add two new elements" << endl;
    myOrgList1.insert(myOrgList1.begin(), "Test1");
    myOrgList1.emplace(myOrgList1.end(), "Test2");
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // erase(), erase a specific one by using iterator
    // STL: Erases the specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first, last).
    // References and iterators to the erased elements are invalidated. Other references and iterators are not affected.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) 
    // cannot be used as a value for pos.
    // The iterator first does not need to be dereferenceable if first==last: erasing an empty range is a no-op.
    cout << "Calling erase() to remove elements" << endl;
    myOrgList1.erase(myOrgList1.begin());
    myOrgList1.erase(std::prev(myOrgList1.end()));   // interesting, can't use "end()-1" instead. Need to use std::prev()
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // push_back()/emplace_back()/pop_back(), add or remove element at back in the list
    // STL: Appends the given element value to the end of the container.
    // 1) The new element is initialized as a copy of value.
    // 2) value is moved into the new element.
    // No iterators or references are invalidated.
    // STL: Appends a new element to the end of the container. The element is constructed through std::allocator_traits::construct, 
    // which typically uses placement-new to construct the element in-place at the location provided by the container. 
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args)....
    // No iterators or references are invalidated.
    // STL: Removes the last element of the container.
    // Calling pop_back on an empty container results in undefined behavior.
    // References and iterators to the erased element are invalidated.
    cout << "Before push_back()/emplace_back()" << endl;
    myOrgList1 = myOrgList2;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << "After push_back()/emplace_back()" << endl;
    myOrgList1.push_back("push_back1");
    myOrgList1.emplace_back("emplace_back2");
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    myOrgList1.pop_back();
    myOrgList1.pop_back();
    cout << "After pop_back() last two elements" << endl;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // posh_front()/emplace_front()/pop_front(), add or remove element at front in the list
    // STL: Prepends the given element value to the beginning of the container.
    // No iterators or references are invalidated.
    // STL: Inserts a new element to the beginning of the container. The element is constructed through std::allocator_traits::construct, 
    // which typically uses placement-new to construct the element in-place at the location provided by the container. 
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args)....
    // No iterators or references are invalidated.
    // STL: Removes the first element of the container. If there are no elements in the container, the behavior is undefined.
    // References and iterators to the erased element are invalidated.
    cout << "Before push_front()/emplace_front()" << endl;
    myOrgList1 = myOrgList2;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << "After push_front()/emplace_front()" << endl;
    myOrgList1.push_front("push_front1");
    myOrgList1.emplace_front("emplace_front2");
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    myOrgList1.pop_front();
    myOrgList1.pop_front();
    cout << "After pop_front() first two elements" << endl;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // resize(), resize the size of the list
    // STL: Resizes the container to contain count elements.
    // If the current size is greater than count, the container is reduced to its first count elements.
    // If the current size is less than count,
    // 1) additional default-inserted elements are appended
    // 2) additional copies of value are appended.
    cout << "Before resize the list, size = " << myOrgList1.size() << endl;
    myOrgList1.resize(1);
    cout << "After resize the list, size = " << myOrgList1.size() << endl;
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    cout << "Elements other than first one were erased as well" << endl;

    // swap(), swap elements in the list. Note that this swap() is swapping whole list from one to another
    // To swap one individual element, need to use std::swap() instead
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations 
    // on individual elements.
    // All iterators and references remain valid. It is unspecified whether an iterator holding the past-the-end value in this 
    // container will refer to this or the other container after the operation.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged 
    // using an unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), 
    // the behavior is undefined). (since C++11)
    cout << "Before swapping whole list" << endl;
    myOrgList1.assign(3, "TEST");
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    for_each(myList.begin(), myList.end(), myprint);
    myOrgList1.swap(myList);
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    for_each(myList.begin(), myList.end(), myprint);
    // swap individual one
    cout << "Swap one element in same list by using std::swap()" << endl;
    auto item1 = myOrgList1.begin();
    auto item2 = std::prev(myOrgList1.end());
    std::swap(*item1, *item2);
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);

    // merge(), this is one of special API only existed in list/forward_list container. Note that we need to sort them before merge
    // Also, the sorting is done by list's sort(), not by std::sort()
    // STL: Merges two sorted lists into one. The lists should be sorted into ascending order.
    // No elements are copied. The container other becomes empty after the operation. The function does nothing if other refers to 
    // the same object as *this. If get_allocator() != other.get_allocator(), the behavior is undefined. No iterators or references 
    // become invalidated, except that the iterators of moved elements now refer into *this, not into other. The first version uses 
    // operator< to compare the elements, the second version uses the given comparison function comp.
    // This operation is stable: for equivalent elements in the two lists, the elements from *this shall always precede the elements 
    // from other, and the order of equivalent elements of *this and other does not change.
    cout << "Before merge call, all lists and their elements" << endl;
    myList.sort();
    myOrgList1.sort();
    myOrgList2.sort();
    for_each(myList.begin(), myList.end(), myprint);
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    for_each(myOrgList2.begin(), myOrgList2.end(), myprint);
    myList.merge(myOrgList1);
    myList.merge(myOrgList2);
    cout << "After merge call, all lists and their elements" << endl;
    for_each(myList.begin(), myList.end(), myprint);
    for_each(myOrgList1.begin(), myOrgList1.end(), myprint);
    for_each(myOrgList2.begin(), myOrgList2.end(), myprint);

    // splice(), without sorting, this function will make elements from another list to be added into current list
    // STL: Transfers elements from one list to another.
    // No elements are copied or moved, only the internal pointers of the list nodes are re-pointed. The behavior is undefined 
    // if: get_allocator() != other.get_allocator(). No iterators or references become invalidated, the iterators to moved elements 
    // remain valid, but now refer into *this, not into other.
    // 1) Transfers all elements from other into *this. The elements are inserted before the element pointed to by pos. The container 
    // other becomes empty after the operation. The behavior is undefined if other refers to the same object as *this.
    // 2) Transfers the element pointed to by it from other into *this. The element is inserted before the element pointed to by pos.
    // 3) Transfers the elements in the range [first, last) from other into *this. The elements are inserted before the element pointed 
    // to by pos. The behavior is undefined if pos is an iterator in the range [first,last).
    std::list<int> list1 = { 1, 2, 3, 4, 5 };
    std::list<int> list2 = { 50, 40, 30, 20, 10 };
    auto it1 = list1.begin();
    cout << "Before splice call, all lists and their elements" << endl;
    cout << "list1: " << endl;
    for_each(list1.begin(), list1.end(), myprint2);
    cout << "list2: " << endl;
    for_each(list2.begin(), list2.end(), myprint2);
    list1.splice(it1, list2);
    cout << "After splice call, all lists and their elements" << endl;
    cout << "list1: " << endl;
    for_each(list1.begin(), list1.end(), myprint2);
    cout << "list2: " << endl;
    for_each(list2.begin(), list2.end(), myprint2);
    // again, the sorting should be done by list's sort(), not by std::sort()
    list1.sort();
    for_each(list1.begin(), list1.end(), myprint2);

    // remove()/remove_if(), remove specific element under condition. These two APIs are only available from C++ 20 and above
    // STL: Removes all elements satisfying specific criteria. The first version removes all elements that are equal to value, 
    // the second version removes all elements for which predicate p returns true.
    cout << "Remove 1 from list1, which is existed in the list1" << endl;
    list1.remove(1);
    for_each(list1.begin(), list1.end(), myprint2);
    cout << "Remove 11 from list1, which is not existed in the list1" << endl;
    list1.remove(11);
    for_each(list1.begin(), list1.end(), myprint2);
    list1.emplace(list1.begin(), 1);
    for_each(list1.begin(), list1.end(), myprint2);
    cout << "Add 1 back to list1 and remove elements that is larger than 10" << endl;
    list1.remove_if([](int n){ return n > 10; });
    for_each(list1.begin(), list1.end(), myprint2);
    // use function way instead of "[](int n){ return n > 10; }" way
    cout << "Remove elements that is smaller than 10" << endl;
    list1.remove_if(isSmallerThan);
    for_each(list1.begin(), list1.end(), myprint2);

    // reverse(), reverse the order of elements in the list
    // STL: Reverses the order of the elements in the container. No references or iterators become invalidated.
    list1.emplace_back(11);
    list1.emplace_back(12);
    list1.emplace_back(13);
    list1.emplace_back(14);
    list1.emplace_back(15);
    cout << "Update elements before reverse() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);
    list1.reverse();
    cout << "Update elements after reverse() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);

    // unique(), remove duplicated ones in list. Note that this function will remove the "consecutive duplicate elements"
    // so if we need to remove all duplicated one, we need to sort the list first
    // STL: Removes all consecutive duplicate elements from the container. Only the first element in each group of equal 
    // elements is left. The behavior is undefined if the selected comparator does not establish an equivalence relation.
    // 1) Uses operator== to compare the elements.
    // 2) Uses the given binary predicate p to compare the elements.
    list1.emplace_back(11);
    list1.emplace_back(12);
    list1.emplace_back(13);
    list1.emplace_back(14);
    list1.emplace_back(15);
    cout << "Update elements before unique() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);
    // if no sort, the elements NOT consecutive duplicated will NOT be removed
    cout << "Just call unique() without sorting" << endl;
    list1.unique();
    for_each(list1.begin(), list1.end(), myprint2);
    cout << "Sort the list so duplicated elements will be sorted in consecutive & duplicated" << endl;
    // the unique() function will only remove consecutive duplicate elements
    list1.sort();
    list1.unique();
    cout << "Update elements after sort() and unique() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);

    // sort(), sort elements in the list
    // STL: Sorts the elements in ascending order. The order of equal elements is preserved. The first version uses 
    // operator< to compare the elements, the second version uses the given comparison function comp.
    // If an exception is thrown, the order of elements in *this is unspecified.
    list1.emplace_back(19);
    list1.emplace_back(18);
    list1.emplace_back(17);
    list1.emplace_back(16);
    list1.emplace_back(15);
    cout << "Elements before sort() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);
    list1.sort();
    cout << "Elements after sort() call" << endl;
    for_each(list1.begin(), list1.end(), myprint2);

    // erase()/easer_if(), remove the specific one from list. These two functions are available only from C++ 20 and above
    // STL: 1) Erases all elements that compare equal to value from the container. Equivalent to return c.remove_if([&](auto& elem) 
    // { return elem == value; });
    // 2) Erases all elements that satisfy the predicate pred from the container. Equivalent to return c.remove_if(pred);
    // std::list<char> cnt(10);
    // std::iota(cnt.begin(), cnt.end(), '0');
    // std::erase(cnt, '3');
    // auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });

    return 0;
}
