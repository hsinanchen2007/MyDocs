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
void myprint(string element) {
    cout << element << " ";
}

// main
int main() {
    deque<string> myDeque = {"First", "Second", "Third", "Forth", "Fifth"};

    // constructor copy
    deque<string> myOrgDeque1 = myDeque;
    deque<string> myOrgDeque2(myDeque);
    deque<string> myOrgDeque3(myOrgDeque1.begin(), myOrgDeque1.end());

    // show all elements in deque
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // assign(), similar to vector's assign(), assign either one single value to all elements, or 
    // multilpe elements by specifying individual value per index. The index here doesn't mean 
    // continuous locations, but as deque is similar to vector that it has several blocks of 
    // vector implemented
    // STL: Replaces the contents of the container.
    // 1) Replaces the contents with count copies of value value
    // 2) Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument 
    // is an iterator into *this. This overload has the same effect as overload (1) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt satisfies LegacyInputIterator. (since C++11)
    // 3) Replaces the contents with the elements from the initializer list ilist.
    // All iterators, pointers and references to the elements of the container are invalidated. The past-the-end iterator is also 
    // invalidated.
    cout << "Call assign() to update 5 elements to New" << endl;
    myDeque.assign(5, "New");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    cout << "Call assign() with begin/end iterators to update 5 elements from myOrgDeque1" << endl;
    myDeque.assign(myOrgDeque1.begin(), myOrgDeque1.end());
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    cout << "Call assign() by specifying value one by one" << endl;
    myDeque.assign({"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"});
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // get_allocator(), same as vector's get_allocator()
    // STL: Returns the allocator associated with the container.

    // at(), read/write specific index location in deque
    // STL: Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    for (int i=0; i < 10; i++) {
        myDeque.at(i) = "New";
    }
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;    

    // operator[], similar to vector's operator, and no bound check like at()
    // STL: Returns a reference to the element at specified location pos. No bounds checking is performed.
    try {
        myDeque.at(100) = "New";    
    } catch (out_of_range &exec) {
        cout << exec.what() << endl;
    }

    // front(), return the first element in deque
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    myDeque = myOrgDeque1;
    cout << "The first element in deque now is " << myDeque.front() << endl;

    // back(), similar to front(), return the last element in deque
    // STL: Returns a reference to the last element in the container.
    // Calling back on an empty container causes undefined behavior.
    cout << "The last element in deque now is " << myDeque.back() << endl;

    // iterator
    cout << "The reverse strings are ";
    for (auto it=myDeque.rbegin(); it!=myDeque.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // empty(), return if the deque is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha;
    cout << "Is the deque empty? " << myDeque.empty() << endl;

    // size(), return the size of deque
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    cout << "Size of the deque is " << myDeque.size() << endl;

    // max_size(), return the max size of deque that the current system can provide
    // STL: Returns the maximum number of elements the container is able to hold due to system or library 
    // implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of the deque is " << myDeque.max_size() << endl;

    // shrink_to_fit(), adjust the size to current existing elements in deque
    // STL: Requests the removal of unused capacity.
    // It is a non-binding request to reduce the memory usage without changing the size of the sequence. 
    // It depends on the implementation whether the request is fulfilled.
    // All iterators and references are invalidated. Past-the-end iterator is also invalidated.
    // Note that std::queue has no capacity() function (like std::vector), because of this we use a custom 
    // allocator to show the working of shrink_to_fit.
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    cout << "Size before shrink_to_fit() call " << myDeque.size() << endl;
    myDeque.shrink_to_fit();
    cout << "Size after shrink_to_fit() call " << myDeque.size() << endl;
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;    

    // clear(), erase all elements in the deque
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators 
    // are also invalidated.
    cout << "Size before clear() call " << myDeque.size() << endl;
    myDeque.clear();
    cout << "Size after clear() call " << myDeque.size() << endl;

    // insert(), insert a new element into deque by index
    // STL: Inserts elements at the specified location in the container.
    // 1-2) inserts value before pos
    // 3) inserts count copies of the value before pos
    // 4) inserts elements from range [first, last) before pos.
    // This overload has the same effect as overload (3) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt qualifies as LegacyInputIterator, to avoid 
    // ambiguity with the overload (3). (since C++11)
    // The behavior is undefined if first and last are iterators into *this.
    // 5) inserts elements from initializer list ilist before pos.
    // All iterators, including the past-the-end iterator, are invalidated. References are invalidated too, unless 
    // pos == begin() or pos == end(), in which case they are not invalidated.
    myDeque.insert(myDeque.begin(), 10, "OLD");
    for_each(myDeque.begin(), myDeque.end(), myprint);  // insert 10 new elements by insert() and iterator
    cout << endl;
    myDeque.insert(myDeque.begin()+5, "NEW");   // insert one new element by insert() by specific index with iterator
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // emplace(), similar to insert() but construct a new element instead of copy
    // STL: Inserts a new element into the container directly before pos.
    // The element is constructed through std::allocator_traits::construct, which typically uses placement-new to construct 
    // the element in-place at a location provided by the container. However, if the required location has been occupied 
    // by an existing element, the inserted element is constructed at another location at first, and then move assigned into 
    // the required location.
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args).... args... may directly or indirectly 
    // refer to a value in the container.
    // All iterators, including the past-the-end iterator, are invalidated. References are invalidated too, unless pos == begin() 
    // or pos == end(), in which case they are not invalidated.
    myDeque.emplace(myDeque.begin(), "emplace1");   // insert one new element by emplace() by specific index with iterator
    myDeque.emplace(myDeque.begin()+5, "emplace2");   // insert one new element by emplace() by specific index with iterator
    myDeque.emplace(myDeque.end(), "emplace3");   // insert one new element by emplace() by specific index with iterator
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // erase(), erase the specific one element by iterator
    // STL: Erases the specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first, last).
    // All iterators and references are invalidated, unless the erased elements are at the end or the beginning of the container, 
    // in which case only the iterators and references to the erased elements are invalidated.
    // It is unspecified when the past-the-end iterator is invalidated.	(until C++11)
    // The past-the-end iterator is also invalidated unless the erased elements are at the beginning of the container and the last 
    // element is not erased.	(since C++11)
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) 
    // cannot be used as a value for pos.
    // The iterator first does not need to be dereferenceable if first==last: erasing an empty range is a no-op.
    myDeque.erase(myDeque.begin()+7);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // push_back()/emplace_back(), add one new element into deque, by copy or contract way
    // STL: Appends the given element value to the end of the container.
    // 1) The new element is initialized as a copy of value.
    // 2) value is moved into the new element.
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    // STL: Appends a new element to the end of the container. The element is constructed through 
    // std::allocator_traits::construct, which typically uses placement-new to construct the element in-place at the location 
    // provided by the container. The arguments args... are forwarded to the constructor as std::forward<Args>(args)....
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    myDeque.push_back("LAST1");
    myDeque.emplace_back("LAST2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // pop_back(), remove element from the end of deque
    // STL: Removes the last element of the container.
    // Calling pop_back on an empty container results in undefined behavior.
    // Iterators and references to the erased element are invalidated. It is unspecified whether the past-the-end iterator is 
    // invalidated. Other references and iterators are not affected.	(until C++11)
    // Iterators and references to the erased element are invalidated. The past-the-end iterator is also invalidated. Other 
    // references and iterators are not affected.	(since C++11)
    myDeque.pop_back();
    myDeque.pop_back();
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // push_front()/pop_front(), add new element into deque from the beginning. Note that deque are two directions and allow adding new
    // element at front/back or remove element at front/back as well
    // STL: Prepends the given element value to the beginning of the container.
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    // STL: Removes the first element of the container. If there are no elements in the container, the behavior is undefined.
    // Iterators and references to the erased element are invalidated. It is unspecified whether the past-the-end iterator is invalidated 
    // if the element is the last element in the container. Other references and iterators are not affected.	(until C++11)
    // Iterators and references to the erased element are invalidated. If the element is the last element in the container, the 
    // past-the-end iterator is also invalidated. Other references and iterators are not affected.	(since C++11)
    myDeque.push_front("FIRST1");
    myDeque.push_front("FIRST2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    myDeque.pop_front();
    myDeque.pop_front();
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // emplace_front(), similar to posh_front(), but by constract way
    // STL: Inserts a new element to the beginning of the container. The element is constructed through std::allocator_traits::construct, 
    // which typically uses placement-new to construct the element in-place at the location provided by the container. The arguments 
    // args... are forwarded to the constructor as std::forward<Args>(args)....
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    myDeque.emplace_front("emplace_front1");
    myDeque.emplace_front("emplace_front2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // resize(), change deque size by specific size
    // STL: Resizes the container to contain count elements.
    // If the current size is greater than count, the container is reduced to its first count elements.
    // If the current size is less than count,
    // 1) additional default-inserted elements are appended
    // 2) additional copies of value are appended.
    myDeque.resize(1);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    myDeque.resize(0);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // swap(), swap elements in deque
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements. All iterators and references remain valid. The past-the-end iterator is invalidated.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined). (since C++11)
    myDeque = myOrgDeque1;
    int i=0, j=myDeque.size();
    while (i<=j) {
        myDeque[i].swap(myDeque[j-1]);
        i++;
        j--;
    }
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    std::reverse(myDeque.begin(), myDeque.end());    // use std::reverse to reverse the elements back
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // std::swap(), std::erase(), std::erase_of() are all similar to vector container, but they are supported from C++ 20 or above

    return 0;
}
